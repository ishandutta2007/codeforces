#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
#include <assert.h>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
#include <functional>
#include <unordered_map>

using namespace std;
typedef pair<int, int> Pi;
typedef long long ll;
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define sz(x) (int)x.size()
#define rep(i, n) for(int i=0;i<n;i++)
#define all(x) x.begin(), x.end()

struct node{
	node(){rep(i, 5)for(int j=i;j<5;j++)p[i][j] = (i == j ? 0 : 1e9);}
	int p[5][5];
	node operator*(const node &a)const{
		node res;
		for(int i=0;i<5;i++){
			for(int j=i;j<5;j++){
				res.p[i][j] = 1e9;
				for(int k=i;k<=j;k++){
					res.p[i][j] = min(res.p[i][j], p[i][k] + a.p[k][j]);
				}
			}
		}
		return res;
	}
};

node T[1<<19];
int n, q;
char A[200020];
const int add = 1<<18;
int last_7[200020];

int get(int x, int y){
//	printf("%d %d\n", x, y);
	x += add; y += add;
	node resL = node(), resR = node();
	while(x <= y){
		if(x & 1)resL = resL * T[x];
		if(!(y & 1))resR = T[y] * resR;
		x = (x+1) >> 1;
		y = (y-1) >> 1;
	}
	return (resL * resR).p[0][3];
}

int S[200020];

void solve(){
	scanf("%d%d", &n, &q);
	scanf("%s", A+1);
	last_7[0] = -1;
	for(int i=1;i<=n;i++){
		last_7[i] = last_7[i-1];
		if(A[i] == '7')last_7[i] = i;
		S[i] = S[i-1];
		if(A[i] == '6')S[i]++;
	}
	for(int i=1;i<=n;i++){
		if(A[i] == '2'){
			T[add+i].p[0][0] = 1; T[add+i].p[0][1] = 0;
		}
		else if(A[i] == '0'){
			T[add+i].p[1][1] = 1; T[add+i].p[1][2] = 0;
		}
		else if(A[i] == '1'){
			T[add+i].p[2][2] = 1; T[add+i].p[2][3] = 0;
		}
		else if(A[i] == '6'){
			T[add+i].p[3][3] = 1; T[add+i].p[3][4] = 0;
		}
	}
	for(int i=add-1;i>=1;i--)T[i] = T[i+i] * T[i+i+1];
//	rep(i, 5){for(int j=i;j<5;j++)printf("%d ", T[1].p[i][j]); puts(""); }
	rep(i, q){
		int x, y; scanf("%d%d", &x, &y);
		if(last_7[y] == -1){
			puts("-1"); continue;
		}
		int ty = last_7[y];
		int g = get(x, ty);
		if(g == 1e9){
			puts("-1");
		}
		else{
			printf("%d\n", g + S[y] - S[ty-1]);
		}
	}
}

int main(){
	int Tc = 1; //scanf("%d", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		solve();
	}
	return 0;
}
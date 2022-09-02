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
#include <unordered_set>
#include <list>
#include <bitset>

using namespace std;
typedef pair<int, int> Pi;
typedef long long ll;
#define pii Pi
#define pll PL
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define sz(x) ((int)(x).size())
#define rep(i, n) for(int i=0;i<n;i++)
#define all(x) (x).begin(), (x).end()
typedef tuple<int, int, int> t3;
typedef pair<ll, ll> PL;

char A[1010];
int D[1010][1010];
char B[1010][1010];
int n, m;
int cost[10];
int lenB[1010];

void solve(){
	scanf("%s", A+1);
	n = (int)strlen(A+1);
	reverse(A+1, A+1+n);
	scanf("%d", &m);
	for(int i=1;i<=m;i++){
		scanf("%s", B[i]+1);
		lenB[i] = (int)strlen(B[i]+1);
		reverse(B[i]+1, B[i]+1+lenB[i]);
	}
	rep(i, 10)scanf("%d",cost+i);
	int C[10], temp[1010];
	int ord[1010];
	for(int i=1;i<=m;i++)ord[i] = i;
	int z = m;
	int L = max(n, *max_element(lenB+1, lenB+1+m)) + 1;
	for(int i=0;i<=L;i++)for(int j=0;j<=m+1;j++)D[i][j] = -(1e9+1e7);
	D[0][0] = 0;
	for(int i=1;i<=L;i++){
		rep(j, 10)C[j] = 0;
		int cc[1010] = {};
		for(int j=1;j<=z;j++)cc[j] = B[ord[j]][i] ? B[ord[j]][i] - '0' : 0;
		for(int j=1;j<=z;j++)C[cc[j]]++;
		for(int j=1;j<10;j++)C[j] += C[j-1];
		for(int j=z;j;j--)temp[C[cc[j]]--] = ord[j];
		
		int l = 0, h = 9;
		if(i == n)l = 1;
		if(A[i] != '?')l = h = A[i] - '0';
		if(i > n)l = h = 0;
		for(int d=l;d<=h;d++){
			int cnt = 0, u = 0;
			for(int j=1;j<=z;j++){
				if(cc[j] + d >= 10)++u;
				if(cc[j] + d == 0 && i > lenB[ord[j]] && i > n);
				else cnt += cost[(cc[j] + d) % 10];
			}
			D[i][u] = max(D[i][u], D[i-1][0] + cnt);
			for(int j=z;j;j--){
				if(cc[j] + d + 1 == 10){
					++u;
					cnt += cost[0] - cost[9];
				}
				else{
					int t = (cc[j] + d) % 10;
					if(cc[j] + d == 0 && i > lenB[ord[j]] && i > n)cnt += cost[1];
					else cnt += cost[t+1] - cost[t];
				}
				D[i][u] = max(D[i][u], D[i-1][z-j+1] + cnt);
			}
		}
		
	//	for(int j=0;j<=z;j++)if(D[i][j] > 0)printf("%d:%d ", j, D[i][j]); puts("");
		for(int j=1;j<=z;j++)ord[j] = temp[j];
	//	rep(j, z)printf("%d ", ord[j+1]); puts("");
	}
	printf("%d\n", D[L][0]);
}

int main(){
	int Tc = 1; //scanf("%d", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		//printf("Case %d: ", tc);
		solve();
	}
	return 0;
}
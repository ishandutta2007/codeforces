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
typedef long double ldouble;

char S[110];
int n;

int ok[130];
int D[77][77][77][2];

void put(int &a, int b){
	if(a == -1 || a > b)a = b;
}

int A[80], B[80], C[80];

void solve(){
	ok['V'] = ok['K'] = 1;
	scanf("%d", &n);
	scanf("%s", S+1);
	for(int i=1;i<=n;i++)if(!ok[S[i]])S[i] = 'O';
	int za = 0, zb = 0, zc = 0;
	for(int i=1;i<=n;i++){
		if(S[i] == 'V')A[++za] = i;
		if(S[i] == 'K')B[++zb] = i;
		if(S[i] == 'O')C[++zc] = i;
	}
	memset(D, -1, sizeof D);
	D[0][0][0][0] = 0;
	int ans = 1e9;
	for(int i=0;i<=n;i++){
		for(int j=0;j<=i;j++){
			for(int k=0;j+k<=i;k++){
				int u = i - j - k;
				rep(q, 2){
					if(D[i][j][k][q] == -1)continue;
					if(i == n){ans = min(ans, D[i][j][k][q]); continue;}
					int ok[80] = {};
					for(int a=1;a<=j;a++)ok[A[a]] = 1;
					for(int a=1;a<=k;a++)ok[B[a]] = 1;
					for(int a=1;a<=u;a++)ok[C[a]] = 1;
					if(j+1 <= za){
						int temp = A[j+1] - i - 1;
						for(int a=A[j+1];a<=n;a++)temp += ok[a];
						put(D[i+1][j+1][k][1], D[i][j][k][q] + temp);
					}
					if(k+1 <= zb && q == 0){
						int temp = B[k+1] - i - 1;
						for(int a=B[k+1];a<=n;a++)temp += ok[a];
						put(D[i+1][j][k+1][0], D[i][j][k][q] + temp);
					}
					if(u+1 <= zc){
						int temp = C[u+1] - i - 1;
						for(int a=C[u+1];a<=n;a++)temp += ok[a];
						put(D[i+1][j][k][0], D[i][j][k][q] + temp);
					}
				}
			}
		}
	}
	printf("%d\n", ans);
}

int main(){
	int Tc = 1; //scanf("%d\n", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		solve();
	}
	return 0;
}
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
typedef pair<int, int> pii;
typedef long long ll;
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define szz(x) ((int)(x).size())
#define rep(i, n) for(int i=0;i<n;i++)
#define all(x) (x).begin(), (x).end()
typedef tuple<int, int, int> t3;
typedef pair<ll, ll> pll;
typedef long double ldouble;
typedef pair<double, double> pdd;

const int MOD = 1e9 + 7;

int D[2][710][11][710];
int E[2][710][11][710];
char ch[720];
int A[720], L;
ll ans;
ll pw[720];

inline void add(int &a, int b) { a = (a+b>=MOD ? a+b-MOD : a+b); }

void solve() {
	scanf("%s", ch+1);
	//for(int i=1;i<=300;i++) ch[i] = rand() % 10 + '0';
	L = (int)strlen(ch+1);
	reverse(ch+1, ch+1+L);
	for(int i=1;i<=L;i++) {
		A[i] = ch[i] - '0';
	}
	pw[0] = 1;
	for(int i=1;i<720;i++) pw[i] = pw[i-1] * 10 % MOD;
	rep(x, 11) D[0][0][x][0] = D[1][0][x][0] = 1;
	for(int i=1;i<=L;i++) {
		for(int j=10;j>=0;j--) {
			for(int u=0;u<=i;u++) {
				for(int x=0;x<10;x++) {
					int ni = i - 1;
					int nj = j;
					int nu = (u - (x >= j));
					if(nu >= 0) {
						add(D[0][i][j][u], D[0][ni][nj][nu]);
						if(x < A[i]) add(D[1][i][j][u], D[0][ni][nj][nu]);
						else if(x == A[i]) add(D[1][i][j][u], D[1][ni][nj][nu]);
					}
				}
			}
		}
	}
	rep(x, 11) E[1][L+1][x][0] = 1;
	for(int i=L;i;i--) {
		for(int j=9;j>=0;j--) {
			for(int u=0;u<=L+1-i;u++) {
				for(int x=0;x<10;x++) {
					int ni = i + 1;
					int nj = j;
					int nu = (u - (x >= j));
					if(nu >= 0) {
						if(x == A[i]) add(E[1][i][j][u], E[1][ni][nj][nu]);
						add(E[0][i][j][u], E[0][ni][nj][nu]);
						if(x < A[i]) add(E[0][i][j][u], E[1][ni][nj][nu]);
					}
				}
			}
		}
	}
	const ll LX = 7e18;
	rep(a, 2) rep(b, L+2) rep(c, 11) rep(d, L+2) E[a][b][c][d] = ((ll)E[a][b][c][d] * c % MOD * pw[d] % MOD);
	rep(a, 2) rep(b, L+2) rep(c, 11) rep(d, L+2) D[a][b][c][d] = (ll)D[a][b][c][d] * pw[d] % MOD;
	ll ans = 0;
	for(int i=1;i<=L;i++) {
		for(int j=1;j<=9;j++) {
			for(int u=0;u<=i-1;u++) for(int v=0;v<=L-i;v++) {
				ll val = 0;
				if(j < A[i]) val = (E[0][i+1][j][v] + E[1][i+1][j][v]) * (ll)D[0][i-1][j+1][u];
				else if(j == A[i]) val = (E[0][i+1][j][v] * (ll)D[0][i-1][j+1][u] + (ll)E[1][i+1][j][v] * D[1][i-1][j+1][u]);
				else val = ((ll)E[0][i+1][j][v] * D[0][i-1][j+1][u]);
				ans += val;
				if(ans > LX) ans %= MOD;
			}
		}
	}
	printf("%lld\n", ans % MOD);
}

int main(){
	int Tc = 1; // scanf("%d\n", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		solve();
	}
	return 0;
}
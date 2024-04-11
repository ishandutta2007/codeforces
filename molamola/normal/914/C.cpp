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
int C[1010][1010];
char ch[1010];
int d[100010];

void solve() {
	rep(i, 1010) {
		C[i][0] = 1;
		for(int j=1;j<=i;j++) C[i][j] = (C[i-1][j-1] + C[i-1][j]) % MOD;
	}
	scanf("%s", ch+1);
	int L = (int)strlen(ch+1);
	int k; scanf("%d", &k);
	if(k == 0) {
		puts("1");
		return;
	}
	else if(k == 1) {
		printf("%d\n", L - 1);
		return;
	}
	--k;
	d[1] = 0;
	for(int i=2;i<=100005;i++) {
		d[i] = d[__builtin_popcount(i)] + 1;
	}
	int now = 0;
	ll ans = 0;
	for(int i=1;i<=L;i++) {
		int c = ch[i] - '0';
		if(c == 1) {
			for(int j=0;j<=L-i;j++) {
				int z1 = now + j;
				if(z1 > 0 && d[z1] == k) ans = (ans + C[L-i][j]) % MOD;
			}
			++now;
		}
	}
	int temp = 0;
	for(int i=1;i<=L;i++) temp += ch[i] - '0';
	if(d[temp] == k) ans = (ans + 1) % MOD;
	printf("%lld\n", ans);
}

int main(){
	int Tc = 1; // scanf("%d\n", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		solve();
	}
	return 0;
}
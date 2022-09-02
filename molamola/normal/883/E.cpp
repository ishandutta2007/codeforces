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
#define sz(x) ((int)(x).size())
#define rep(i, n) for(int i=0;i<n;i++)
#define all(x) (x).begin(), (x).end()
typedef tuple<int, int, int> t3;
typedef pair<ll, ll> pll;
typedef long double ldouble;
typedef pair<double, double> pdd;

int n, m;
char A[55], B[1010][55];
int can[1010];

void solve() {
	scanf("%d%s", &n, A+1);
	scanf("%d", &m);
	for(int i=1;i<=m;i++) scanf("%s", B[i]+1);
	int chk[26] = {};
	for(int i=1;i<=n;i++) chk[A[i] - 'a'] = 1;
	for(int i=1;i<=m;i++) {
		can[i] = 1;
		for(int j=1;j<=n;j++) if(B[i][j] != A[j] && A[j] != '*') can[i] = 0;
		for(int j=1;j<=n;j++) if(A[j] == '*' && chk[B[i][j] - 'a']) can[i] = 0;
	}
	int cnt = 0;
	for(int i=0;i<26;i++) if(chk[i] == 0) {
		int f = 1;
		for(int j=1;j<=m;j++) if(can[j]) {
			int ok = 0;
			for(int k=1;k<=n;k++) if(B[j][k] == 'a' + i) ok = 1;
			if(ok == 0) f = 0;
		}
		if(f) cnt++;
	}
	printf("%d\n", cnt);
}

int main(){
	int Tc = 1; // scanf("%d\n", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		// printf("Case #%d: ", tc);
		solve();
	}
	return 0;
}
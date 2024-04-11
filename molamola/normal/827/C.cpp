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
typedef long long ll;
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define sz(x) ((int)(x).size())
#define rep(i, n) for(int i=0;i<n;i++)
#define all(x) (x).begin(), (x).end()
typedef tuple<int, int, int> t3;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ldouble;
typedef pair<double, double> pdd;

int T[4][11][10][100010], L;
char A[100010];

void update(int T2[100010], int c, int v) {
	for(int i=c;i<=L;i+=(i&-i)) T2[i] += v;
}

int read(int T2[100010], int l, int r) {
	int res = 0;
	for(int i=r;i;i-=(i&-i)) res += T2[i];
	for(int i=l-1;i;i-=(i&-i)) res -= T2[i];
	return res;
}

int change(char c) { return c == 'A' ? 0 : c == 'G' ? 1 : c == 'T' ? 2 : 3; }

void solve(){
	scanf("%s", A+1);
	L = (int)strlen(A+1);
	for(int i=1;i<=L;i++) {
		int c = change(A[i]);
		for(int j=1;j<=10;j++) {
			update(T[c][j][i % j], i, 1);
		}
	}
	int q; scanf("%d", &q);
	while(q--){
		int cmd; scanf("%d", &cmd);
		if(cmd == 1) {
			int x; char ch; scanf("%d %c", &x, &ch);
			int c = change(ch);
			int cc = change(A[x]);
			for(int j=1;j<=10;j++) {
				update(T[cc][j][x % j], x, -1);
				update(T[c][j][x % j], x, 1);
			}
			A[x] = ch;
		}
		else {
			int l, r; char S[12];
			scanf("%d%d%s", &l, &r, S);
			int len = (int)strlen(S);
			int ans = 0;
			for(int i=0;i<len;i++) {
				int c = change(S[i]);
				ans += read(T[c][len][(l+i)%len], l, r);
			}
			printf("%d\n", ans);
		}
	}
}

int main(){
	int Tc = 1; // scanf("%d\n", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		// printf("Case #%d: ", tc);
		solve();
	}
	return 0;
};
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
#include <assert.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
#include <functional>
#include <unordered_set>
#include <bitset>
#include <time.h>
#include <limits.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define Fi first
#define Se second
#define pb push_back
#define szz(x) (int)x.size()
#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) x.begin(),x.end()
typedef tuple<int, int, int> t3;

int n, q;
char X[100010];
int dp[252][252][252];
int nxt[100010][30];

int main() {
	scanf("%d%d%s", &n, &q, X+1);
	rep(i, 30) nxt[n+1][i] = n+1;
	for(int i=n;i;i--) {
		rep(j, 26) nxt[i][j] = nxt[i+1][j];
		nxt[i][X[i]-'a'] = i;
	}
	auto get_nxt = [&](int x, char c) {
		int cc = c - 'a';
		return x == n+1 ? n+1 : nxt[x+1][cc];
	};
	auto upd = [&](int &x, int y) { if(x > y) x = y; };
	int la = 0, lb = 0, lc = 0;
	string sa, sb, sc;
	for(int i=1;i<=q;i++) {
		char ch[2]; scanf("%s", ch);
		if(ch[0] == '+') {
			int x; char c;
			scanf("%d %c", &x, &c); --x;
			if(x == 0) {
				for(int i=0;i<=lb;i++) for(int j=0;j<=lc;j++) {
					dp[la+1][i][j] = get_nxt(dp[la][i][j], c);
					if(i) upd(dp[la+1][i][j], get_nxt(dp[la+1][i-1][j], sb[i-1]));
					if(j) upd(dp[la+1][i][j], get_nxt(dp[la+1][i][j-1], sc[j-1]));
				}
				++la; sa.pb(c);
			}
			else if(x == 1) {
				for(int i=0;i<=la;i++) for(int j=0;j<=lc;j++) {
					dp[i][lb+1][j] = get_nxt(dp[i][lb][j], c);
					if(i) upd(dp[i][lb+1][j], get_nxt(dp[i-1][lb+1][j], sa[i-1]));
					if(j) upd(dp[i][lb+1][j], get_nxt(dp[i][lb+1][j-1], sc[j-1]));
				}
				++lb; sb.pb(c);
			}
			else {
				for(int i=0;i<=la;i++) for(int j=0;j<=lb;j++) {
					dp[i][j][lc+1] = get_nxt(dp[i][j][lc], c);
					if(i) upd(dp[i][j][lc+1], get_nxt(dp[i-1][j][lc+1], sa[i-1]));
					if(j) upd(dp[i][j][lc+1], get_nxt(dp[i][j-1][lc+1], sb[j-1]));
				}
				++lc; sc.pb(c);
			}
		}
		else {
			int x; scanf("%d", &x); --x;
			if(x == 0) --la, sa.pop_back();
			else if(x == 1) --lb, sb.pop_back();
			else --lc, sc.pop_back();
		}
		if(dp[la][lb][lc] <= n) puts("YES");
		else puts("NO");
	}
	return 0;
}
#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <cstring>
#include <list>  
#include <cassert>
#include <climits>
#include <bitset>
using namespace std;  

#define PB push_back  
#define MP make_pair  
#define SZ(v) ((int)(v).size())  
#define FOR(i,a,b) for(int i=(a);i<(b);++i)  
#define REP(i,n) FOR(i,0,n)  
#define FORE(i,a,b) for(int i=(a);i<=(b);++i)  
#define REPE(i,n) FORE(i,0,n)  
#define FORSZ(i,a,v) FOR(i,a,SZ(v))  
#define REPSZ(i,v) REP(i,SZ(v))  
typedef long long ll;  
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXN = 1000;
const int MAXLEN = 1000;

int n, len, idx;
char s[MAXN*MAXLEN + 1];
char ans[MAXN][MAXLEN + 1];

int cnt[26];

void solve() {
	memset(cnt, 0, sizeof(cnt));
	REP(i, n*len) ++cnt[s[i] - 'a'];
	REP(i, n) { REP(j, len) ans[i][j] = '?'; ans[i][len] = '\0'; }
	int row = 0, col = 0;
	REP(c, 26) if(cnt[c]>0) {
		int vert = idx + 1 - row;
		int hor = min(len - col, cnt[c] / vert);
		//printf("%c: cnt=%d vert=%d hor=%d\n", 'a' + c, cnt[c], vert, hor);
		REP(j, hor) REP(i, vert) ans[row + i][col + j] = 'a' + c;
		cnt[c] -= vert*hor;
		col += hor;
		if (col < len) {
			int rem = cnt[c];
			//printf("rem=%d\n", rem);
			assert(rem < vert);
			REP(i, rem) ans[row + i][col] = 'a' + c;
			cnt[c] -= rem;
			row += rem;
		}
	}
	int at = 0;
	REP(i,n) REP(j,len) if(ans[i][j]=='?') {
		while (at < 26 && cnt[at] == 0) ++at;
		assert(at < 26);
		ans[i][j] = 'a' + at;
		--cnt[at];
	}
}

void run() {
	scanf("%d%d%d", &n, &len, &idx); --idx;
	scanf("%s", s); assert(strlen(s) == n*len);
	solve();
	REP(i, n) printf("%s\n", ans[i]);
}

int main() {
	run();
	return 0;
}
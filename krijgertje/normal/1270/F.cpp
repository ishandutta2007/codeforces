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

const int MAXN = 200000;

int n;
char s[MAXN + 1];

int freq[MAXN];
int freqscore[MAXN];

int one[MAXN], none;

ll sumdiv(int mxnum, int den) {
	//ll ret = 0; REPE(i, mxnum) ret += i / den; return ret;
	ll ret = 0;
	int extra = (mxnum + 1) % den; ret += (ll)extra*(mxnum / den); mxnum -= extra;
	if (mxnum >= 0) { int last = mxnum / den; ret += (ll)den*last*(last + 1) / 2; }
	return ret;
}
ll sumdiv(int l, int r, int den) { 
	//ll ret = 0; FORE(i, l, r) ret += i / den; return ret; 
	ll ret = sumdiv(r, den); if (l > 0) ret -= sumdiv(l - 1, den); return ret;
}

ll solve() {
	int upto = (int)sqrt(1.0*n);
	//printf("upto=%d\n", upto);
	ll ret = 0;
	// calculate substrings for which #zeroes <= upto * #ones
	REPE(mltzero, upto) {
		// #zeroes = mltzero * #ones
		memset(freq, 0, sizeof(freq));
		memset(freqscore, -1, sizeof(freqscore));
		int score = 0, id = 0;
		freqscore[id] = score, freq[id] = 1;
		REP(i, n) {
			if (s[i] == '0') {
				--score;
				if (--id < 0) id += n;
			} else {
				score += mltzero;
				if ((id += mltzero) >= n) id -= n;
			}
			if (freqscore[id] != score) freqscore[id] = score, freq[id] = 0;
			//printf("%d: score=%d (%d)\n", mltzero, score, freq[id]);
			ret += freq[id];
			++freq[id];
		}
	}
	// calculate substrings for which #zeroes >= (upto+1) * #ones
	none = 0; REP(i, n) if (s[i] == '1') one[none++] = i;
	for (int cntone = 1; cntone + cntone*(upto + 1) <= n; ++cntone) {
		int mnzero = cntone*(upto + 1);
		//printf("cntone=%d (mnzero=%d)\n", cntone, mnzero);
		REPE(a, none - cntone) {
			int b = a + cntone - 1;
			int x = one[a] - (a == 0 ? -1 : one[a - 1]) - 1;
			int y = (b == none - 1 ? n : one[b + 1]) - one[b] - 1;
			int havezero = one[b] - one[a] + 1 - cntone;
			/*REPE(i, x) {
				int l = max(upto + 1, (havezero + i + cntone - 1) / cntone);
				int r = (havezero + i + y) / cntone;
				if (l <= r) ret += r - l + 1;
			}*/
			// upto+1>=(havezero+i)/cntone -> i<=mnzero-havezero
			int flip = min(max(0, mnzero - havezero + 1), x + 1);
			// upto + 1 <= (havezero + i + y) / cntone -> i >= mnzero-havezero-y
			int lb = max(0, mnzero - havezero - y);
			if (lb < flip) ret += sumdiv(havezero + y + lb, havezero + y + flip - 1, cntone) - (ll)(flip - lb)*upto;
			if (flip <= x) ret += sumdiv(havezero + flip + y, havezero + x + y, cntone) - sumdiv(havezero + flip + cntone - 1, havezero + x + cntone - 1, cntone) + (x - flip + 1);
		}
	}
	return ret;
}

void run() {
	scanf("%s", s); n = strlen(s);
	printf("%lld\n", solve());
}

int main() {
	run();
	return 0;
}
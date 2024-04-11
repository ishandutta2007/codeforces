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

const int MAXPERSON = 100000;
const int MAXPLAYER = 7;
const int MAXINTERESTING = 2 * MAXPLAYER*MAXPLAYER + MAXPLAYER;
struct Person { int supportscore; int playerscore[MAXPLAYER]; int id; };
bool operator<(const Person &a, const Person &b) { return a.supportscore > b.supportscore; }

int nperson, nplayer, nsupport;
Person person[MAXPERSON];

bool isinteresting[MAXPERSON];
pair<int, int> o[MAXPERSON]; int no = 0;
int interesting[MAXPERSON], ninteresting;
ll dp[MAXINTERESTING + 1][1 << MAXPLAYER];
ll noninteresting[MAXPERSON + 1]; int nnoninteresting;

void upd(ll &a, ll b) { a = max(a, b); }
ll solve() {
	REP(i, nperson) person[i].id = i;
	sort(person, person + nperson);
	// options for player in position k:
	// * best 7 by playerscore[i][k]-supportscore[i] in first nsupport persons
	// * next 7 persons
	// * best 7 by playerscore[i][k] in remaining persons
	REP(i, nperson) isinteresting[i] = false;
	REP(k, nplayer) {
		no = 0; REP(i, nsupport) o[no++] = MP(-(person[i].playerscore[k] - person[i].supportscore), i); sort(o, o + no); REP(i, min(no, nplayer)) isinteresting[o[i].second] = true;
		FOR(i, nsupport, nsupport + nplayer) isinteresting[i] = true;
		no = 0; FOR(i, nsupport + nplayer, nperson) o[no++] = MP(-person[i].playerscore[k], i); sort(o, o + no); REP(i, min(no, nplayer)) isinteresting[o[i].second] = true;
	}
	ninteresting = 0; REP(i, nperson) if (isinteresting[i]) interesting[ninteresting++] = i;
	//printf("interesting:"); REP(i, nperson) printf(" %d=%s", person[i].id + 1, isinteresting[i] ? "YES" : "NO"); puts("");

	REPE(supp, ninteresting) REP(mask, 1 << nplayer) dp[supp][mask] = LLONG_MIN;
	dp[0][0] = 0;
	REP(i, ninteresting) for (int supp = ninteresting; supp >= 0; --supp) for (int mask = (1 << nplayer) - 1; mask >= 0; --mask) if (dp[supp][mask] != LLONG_MIN) {
		int at = interesting[i];
		upd(dp[supp + 1][mask], dp[supp][mask] + person[at].supportscore);
		REP(k, nplayer) if ((mask&(1 << k)) == 0) upd(dp[supp][mask ^ (1 << k)], dp[supp][mask] + person[at].playerscore[k]);
	}
	nnoninteresting = 0; REP(i, nperson) if (!isinteresting[i]) noninteresting[nnoninteresting++] = person[i].supportscore;
	sort(noninteresting, noninteresting + nnoninteresting); reverse(noninteresting, noninteresting + nnoninteresting);
	noninteresting[nnoninteresting] = 0; rotate(noninteresting, noninteresting + nnoninteresting, noninteresting + nnoninteresting + 1);
	REP(i, nnoninteresting) noninteresting[i + 1] += noninteresting[i];
	ll ret = LLONG_MIN;
	REPE(supp, ninteresting) {
		ll cur = dp[supp][(1 << nplayer) - 1]; if (cur == LLONG_MIN) continue;
		int rem = nsupport - supp; if (rem<0 || rem>nnoninteresting) continue;
		cur += noninteresting[rem];
		ret = max(ret, cur);
	}
	return ret;
}

void run() {
	scanf("%d%d%d", &nperson, &nplayer, &nsupport);
	REP(i, nperson) scanf("%d", &person[i].supportscore);
	REP(i, nperson) REP(j, nplayer) scanf("%d", &person[i].playerscore[j]);
	printf("%lld\n", solve());
}

int main() {
	run();
	return 0;
}
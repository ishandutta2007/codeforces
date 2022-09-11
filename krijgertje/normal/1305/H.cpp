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

const int MAXQUESTION = 100000;
const int MAXSTUDENT = 100000;
struct Fix { int rank, score; };
bool operator<(const Fix& a, const Fix& b) { return a.rank < b.rank; }

int nquestion, nstudent;
int lcorrect[MAXQUESTION], rcorrect[MAXQUESTION];
int nfix;
Fix fix[MAXSTUDENT];
ll totscore;

int score[MAXSTUDENT];
ll lsum[MAXQUESTION + 1], rsum[MAXQUESTION + 1];
ll scoresum[MAXSTUDENT + 1];

bool calcscore(int ntie,int tiescore) {
	REP(rep, 2) {
		REP(i, nstudent) score[i] = -1;
		REP(i, nfix) score[fix[i].rank] = fix[i].score;
		REP(i, ntie) if (score[i] != -1) { if (tiescore == -1) tiescore = score[i]; if (score[i] != tiescore) return false; }
		if (tiescore != -1) REP(i, ntie) score[i] = tiescore;
		ll havescore = 0; int lastscore = 0;
		for (int i = nstudent - 1; i >= 0; --i) { if (score[i] != -1) { if (score[i] < lastscore) return false; lastscore = score[i]; } havescore += lastscore; }
		if (havescore > totscore) return false;
		ll remscore = totscore - havescore; lastscore = 0; int lastidx = nstudent;
		for (int i = nstudent - 1; i >= 0; --i) if (score[i] != -1) {
			int cntbetween = lastidx - i - 1, limextraeach = score[i] - lastscore;
			if (cntbetween >= 1) {
				ll curextratot = min((ll)limextraeach * cntbetween, remscore); ll curextraeach = curextratot / cntbetween; int curextrarem = curextratot % cntbetween;
				REP(j, cntbetween) score[i + j + 1] = lastscore + curextraeach + (j < curextrarem ? 1 : 0);
				remscore -= curextratot;
			}
			lastscore = score[i], lastidx = i;
		}
		{
			int cntbefore = lastidx, limextraeach = nquestion - lastscore;
			if (cntbefore >= 1) {
				ll curextratot = min((ll)limextraeach * cntbefore, remscore); ll curextraeach = curextratot / cntbefore; int curextrarem = curextratot % cntbefore;
				assert(cntbefore >= ntie && tiescore == -1);
				if (curextrarem != 0 && curextrarem < ntie) { tiescore = lastscore + curextraeach + 1; continue; }
				REP(j, cntbefore) score[j] = lastscore + curextraeach + (j < curextrarem ? 1 : 0);
				remscore -= curextratot;
			}
		}
		if (remscore != 0) return false; else break;
	}
	//printf("score:"); REP(i, nstudent) printf(" %d", score[i]); puts("");
	return true;
}

ll divdown(ll num, ll den) { return num >= 0 ? num / den : (num - den + 1) / den; }
struct CHMin {
	vector<pair<int, ll>> q;

	void init() { q.clear(); }
	ll overtake(const pair<int, ll>& p, const pair<int, ll>& q) {
		// p.first*x+p.second<=q.first*x+q.second, p.first>q.first
		// x<=(q.second-p.second)/(p.first-q.first), p.first>q.first
		return divdown(q.second - p.second, p.first - q.first);
	}
	void add(int a, ll b) { // increasing a
		if (SZ(q) >= 1) assert(a > q[SZ(q) - 1].first);
		while (SZ(q) >= 2 && overtake(q[SZ(q) - 1], q[SZ(q) - 2]) <= overtake(MP(a, b), q[SZ(q) - 2])) q.pop_back();
		q.PB(MP(a, b));
	}
	ll get(int x) { // non-deceasing x
		while (SZ(q) >= 2 && overtake(q[SZ(q) - 1], q[SZ(q) - 2]) < x) q.pop_back();
		return (ll)x * q[SZ(q) - 1].first + q[SZ(q) - 1].second;
	}

};

CHMin ch1, ch2;

bool isfeasable() {
	scoresum[0] = 0; REP(i, nstudent) scoresum[i + 1] = scoresum[i] + score[nstudent - i - 1];
	//printf("scoresum:"); REPE(i, nstudent) printf(" %lld", scoresum[i]); puts("");
	// for all 0<=i<=nstudent and 0<=j<=nquestion: scoresum[i]+rsum[j]+(nstudent-i)*(nquestion-j)>=totscore
	// for all 0<=i<=nstudent and 0<=j<=nquestion: scoresum[i]+lsum[j]+(nstudent-i)*(nquestion-j)>=lsum[nquestion]

	// if we fix i, then j*i+(sum[j]-nstudent*j)>=rhs-scoresum[i]-nstudent*nquestion+i*nquestion, so we need to minimize j*i+(sum[j]-nstudent*j)
	ch1.init(); REPE(j, nquestion) ch1.add(j, rsum[j] - (ll)nstudent * j);
	ch2.init(); REPE(j, nquestion) ch2.add(j, lsum[j] - (ll)nstudent * j);
	REPE(i, nstudent) {
		ll lhs1 = ch1.get(i), rhs1 = totscore - scoresum[i] - (ll)nstudent * nquestion + (ll)i * nquestion;
		ll lhs2 = ch2.get(i), rhs2 = lsum[nquestion] - scoresum[i] - (ll)nstudent * nquestion + (ll)i * nquestion;
		//ll have1 = lhs1 - rhs1; ll want1 = LLONG_MAX; REPE(j, nquestion) want1 = min(want1, scoresum[i] + rsum[j] + (ll)(nstudent - i) * (nquestion - j) - totscore); assert(have1 == want1);
		//ll have2 = lhs2 - rhs2; ll want2 = LLONG_MAX; REPE(j, nquestion) want2 = min(want2, scoresum[i] + lsum[j] + (ll)(nstudent - i) * (nquestion - j) - lsum[nquestion]); assert(have2 == want2);
		if (lhs1 < rhs1 || lhs2 < rhs2) return false;
	}
	return true;
}

pair<int, int> ans;

bool solve() {
	sort(fix, fix + nfix);
	REP(i, nquestion) lsum[i + 1] = lcorrect[i], rsum[i + 1] = rcorrect[i];
	sort(lsum + 1, lsum + nquestion + 1); sort(rsum, rsum + nquestion + 1);
	REP(i, nquestion) lsum[i + 1] += lsum[i], rsum[i + 1] += rsum[i];
	//printf("lsum:"); REPE(i, nquestion) printf(" %lld", lsum[i]); puts("");
	//printf("rsum:"); REPE(i, nquestion) printf(" %lld", rsum[i]); puts("");

	if (!calcscore(1, -1)) return false;
	if (!isfeasable()) return false;

	int lo = 1, hi = nstudent + 1;
	while (lo + 1 < hi) {
		int mi = lo + (hi - lo) / 2;
		if (!calcscore(mi, -1) || !isfeasable()) hi = mi; else lo = mi;
	}
	int ntie = lo;
	//printf("ntie=%d\n", ntie);
	assert(calcscore(ntie, -1));
	lo = score[0], hi = nquestion + 1;
	while (lo + 1 < hi) {
		int mi = lo + (hi - lo) / 2;
		if (!calcscore(ntie, mi) || !isfeasable()) hi = mi; else lo = mi;
	}
	int tiescore = lo;
	//printf("tiescore=%d\n", tiescore);
	ans = MP(ntie, tiescore);
	return true;
}

void run() {
	scanf("%d%d", &nquestion, &nstudent);
	REP(i, nquestion) scanf("%d%d", &lcorrect[i], &rcorrect[i]);
	scanf("%d", &nfix);
	REP(i, nfix) scanf("%d%d", &fix[i].rank, &fix[i].score), --fix[i].rank;
	scanf("%lld", &totscore);
	if (!solve()) { printf("-1 -1\n"); return; }
	printf("%d %d\n", ans.first, ans.second);
}

int main() {
	run();
	return 0;
}
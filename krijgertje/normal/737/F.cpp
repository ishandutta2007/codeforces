#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <cstring>
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <list>  
#include <cassert>
#include <ctime>
#include <climits>
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
typedef unsigned long long ull;
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a%b); }

const int MAXN = 2000;

int n, a, b;
int s[MAXN];

int pos[MAXN];
int need[MAXN]; // need[i] = last position on or after i such that s[need[i]]>=s[i]

int stck[MAXN], nstck;
pair<int,int> mid[MAXN]; int nmid,ndst;

vector<pair<int,int> > ops;

bool take(int &at,int cnt) {
	//printf("taking %d [first=%d] [nmid=%d]",cnt,s[at]+1,nmid); if(nmid!=0) printf(" {%d,%d}",mid[nmid-1].first+1,mid[nmid-1].second+1); puts("");
	if(cnt>a) return false;
	for(int i=at+cnt-1;i>=at;--i) {
		if(nmid!=0&&s[i]==mid[nmid-1].first-1) --mid[nmid-1].first;
		else if(nmid!=0&&s[i]<=mid[nmid-1].second) return false;
		else mid[nmid++]=MP(s[i],s[i]);
	}
	ops.PB(MP(1,cnt));
	at+=cnt;
	while(nmid>0&&mid[nmid-1].second==n-ndst-1) {
		int len=mid[nmid-1].second-mid[nmid-1].first+1;
		if(len>b) return false;
		ops.PB(MP(2,len));
		ndst+=len; --nmid;
	}
	return true;
}

bool bcan(int at,int cnt) {
	if(cnt==0) return true;
	int prv=s[at],mn=s[at],len=1;
	FOR(i,1,cnt) {
		int now=s[at+i];
		if(len<b&&now==prv+1) { prv=now,++len; continue; }
		if(now<mn) { prv=mn=now,len=1; continue; }
		return false;
	}
	return true;
}


bool solve() {
	REP(i, n) pos[s[i]] = i;
	nstck = 0;
	for (int i = n - 1; i >= 0; --i) {
		if (nstck == 0 || s[i] > s[stck[nstck - 1]]) {
			need[i] = i; stck[nstck++] = i;
		} else {
			int l = -1, h = nstck - 1; // (l,h]
			while (l + 1 < h) { int m = l + (h - l) / 2; if (s[i] <= s[stck[m]]) h = m; else l = m; }
			need[i] = stck[h];
		}
	}
	//printf("need:"); REP(i, n) printf(" %d", need[i]); puts("");

	nmid = ndst = 0; ops.clear();
	int at = 0;
	while (at<n) {
		int top=nmid==0?-1:mid[nmid-1].first;
		bool nosmall=true; FOR(i,at+1,need[at]) if(s[i]<s[at]) nosmall=false;
		if(top!=-1&&top!=0&&pos[top-1]>=at&&need[at]>=pos[top-1]) {
			if(!take(at,pos[top-1]-at+1)) return false;
		} else if(s[at]==0||pos[s[at]-1]<at||need[at]<pos[s[at]-1]&&nosmall) {
			if(need[at]==at) {
				if(!take(at,1)) return false;
			} else {
				int extra=0; while(at+1+extra<n&&s[at+1+extra]<s[at]) ++extra;
				if(!take(at,1+extra)) return false;
			}
		} else {
			int to=pos[s[at]-1];
			int atlen = 1; while (at + atlen < n&&s[at + atlen] == s[at] + atlen) ++atlen;
			int tolen = 1; while (to - tolen >= 0 && s[to - tolen] == s[to] - tolen) ++tolen;
			if(at+atlen+tolen-1!=to) {
				int extra=0; while(at+atlen+extra<n&&s[at+atlen+extra]<s[at]&&s[at+atlen+extra]!=s[at]-tolen) ++extra;
				if(!take(at,atlen+extra)) return false;
			} else {
				int extra=0; while(at+atlen+tolen+extra<n&&s[at+atlen+tolen+extra]<s[at]) ++extra;
				bool other=false; FOR(i,at+atlen+tolen+extra,need[at]) if(s[i]<s[at]) other=true;
				//printf("here atlen=%d tolen=%d extra=%d other=%s\n",atlen,tolen,extra,other?"YES":"NO");
				if(!other&&atlen+tolen+extra<=a&&atlen<=b&&tolen<=b&&bcan(at+atlen+tolen,extra)) {
					if(!take(at,atlen+tolen+extra)) return false;
				} else if(atlen<=a&&tolen<=a&&atlen+tolen<=b) {
					if(!take(at,atlen)) return false;
					if(!take(at,tolen)) return false;
				} else {
					int x=0; while(x<=atlen+tolen&&!(x<=a&&atlen+tolen-x<=a&&(x<=atlen?tolen+x:x-atlen)<=b&&(x<=atlen?atlen-x:atlen+tolen-x+atlen)<=b)) ++x; if(x>atlen+tolen) return false;
					if(x!=0&&!take(at,x)) return false;
					if(!take(at,atlen+tolen-x)) return false;
				}
			}
		}
	}
	assert(nmid==0&&ndst==n);
	return true;
}

void run() {
	scanf("%d%d%d", &n, &a, &b); REP(i, n) scanf("%d", &s[i]), --s[i];
	if(!solve()) { printf("NO\n"); return; }
	printf("YES\n");
	printf("%d\n",SZ(ops));
	REPSZ(i,ops) printf("%d %d\n",ops[i].first,ops[i].second);
}

int main() {
	run();
	return 0;
}
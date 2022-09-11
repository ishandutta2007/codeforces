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
#include <chrono>
#include <chrono>
#include <random>
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
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXN=1000;

int n;
int a[MAXN];
vector<string> ans;

pair<int,int> o[MAXN];
pair<int,int> lst[MAXN]; int nlst;

void solve() {
	REP(i,n) o[i]=MP(a[i],i);
	sort(o,o+n);

	nlst=0;
	for(int l=0,r=l;l<n;l=r) {
		while(r<n&&o[r].first==o[l].first) ++r;
		int cnt=r-l;
		lst[nlst++]=MP(cnt,l);
	}
	sort(lst,lst+nlst);

	ans.clear();
	int none=0; REP(i,nlst) if(lst[i].first==1) ++none;
	int at=none;
	REP(i,nlst) {
		int cnt=lst[i].first,l=lst[i].second;
		while(SZ(ans)<at+cnt) ans.PB(string(n,'0'));
		if(cnt==1) {
			int inside=i+1; assert(inside<=o[l].first);
			REP(i,inside) ans[i][o[l].second]='1';
			int rem=o[l].first-inside;
			for(int i=0;rem>0;++i) {
				if(i<none) continue;
				if(i>=SZ(ans)) ans.PB(string(n,'0'));
				ans[i][o[l].second]='1';
				--rem;
			}
		} else {
			int inside=min(o[l].first,cnt-1);
			REP(k,cnt) REP(i,inside) ans[at+(k+i)%cnt][o[l+k].second]='1';
			int rem=o[l].first-inside;
			for(int i=0;rem>0;++i) {
				if(i>=at&&i<at+cnt) continue;
				if(i>=SZ(ans)) ans.PB(string(n,'0'));
				REP(k,cnt) ans[i][o[l+k].second]='1';
				--rem;
			}
			at+=cnt;
		}
	}
}

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d",&a[i]);
	solve();
	printf("%d\n",SZ(ans));
	REPSZ(i,ans) printf("%s\n",ans[i].c_str());
}

void stress() {
	int mxn=10;
	REP(rep,1000000) {
		n=rand()%mxn+1;
		REP(i,n) a[i]=rand()%n+1;
		sort(a,a+n);
		//printf("%d\n",n); REP(i,n) { if(i!=0) printf(" "); printf("%d",a[i]); } puts("");
		solve();
		//printf("%d\n",SZ(ans)); REPSZ(i,ans) printf("%s\n",ans[i].c_str());
		sort(ans.begin(),ans.end());
		FORSZ(i,1,ans) assert(ans[i]!=ans[i-1]);
		if(rep%1000==0) printf(".");
	}
}

int main() {
	run();
	//stress();
	return 0;
}
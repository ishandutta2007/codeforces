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
int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }

int n;
int won[100000];
int summe[100001];
int sumop[100001];

vector<pair<int,int> > ret;

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d",&won[i]);
	summe[0]=0; REP(i,n) summe[i+1]=summe[i]+(won[i]==1?1:0);
	sumop[0]=0; REP(i,n) sumop[i+1]=sumop[i]+(won[i]==2?1:0);
	FORE(t,1,n) {
		int nme=0,nop=0,at=0; bool ok=true,wonlast=false;
		while(at<n) {
			if(summe[n]-summe[at]<t&&sumop[n]-sumop[at]<t) { ok=false; break; }
			int l=at,h=n; // (l,h]
			while(l+1<h) {
				int m=l+(h-l)/2;
				if(summe[m]-summe[at]<t&&sumop[m]-sumop[at]<t) l=m; else h=m;
			}
			wonlast=won[h-1]==1;
			if(wonlast) ++nme; else ++nop; at=h;
		}
		if(!ok) continue;
		if(wonlast&&nop>=nme) continue;
		if(!wonlast&&nme>=nop) continue;
		int s=max(nme,nop);
		ret.PB(MP(s,t));
	}
	sort(ret.begin(),ret.end());
	printf("%d\n",SZ(ret));
	REPSZ(i,ret) printf("%d %d\n",ret[i].first,ret[i].second);

}

int main() {
	run();
	return 0;
}
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

const int MAXN=100000;
const int MAXQ=200000;

int nq;
int qkind[MAXQ],qx[MAXQ],qy[MAXQ],qans[MAXQ];

int n;
map<pair<int,int>,int> mp;
int px[MAXN],py[MAXN],pl[MAXN],pr[MAXN];

map<ll,vector<int>> byrad;

map<pair<int,int>,vector<pair<int,int>>> matches;
map<pair<int,int>,vector<pair<int,int>>> singles;
map<pair<int,int>,vector<int>> queries;


void run() {
	scanf("%d",&nq); REP(i,nq) scanf("%d%d%d",&qkind[i],&qx[i],&qy[i]);

	n=0; mp.clear();
	REP(i,nq) {
		if(qkind[i]==1) { int id=n++; pair<int,int> key=MP(qx[i],qy[i]); assert(!mp.count(key)); mp[key]=id; px[id]=qx[i],py[id]=qy[i],pl[id]=i,pr[id]=-1; }
		if(qkind[i]==2) { pair<int,int> key=MP(qx[i],qy[i]); assert(mp.count(key)); int id=mp[key]; mp.erase(key); pr[id]=i; }
		if(qkind[i]==3) { qans[i]=SZ(mp); }
	}
	for(auto it=mp.begin();it!=mp.end();++it) { int id=it->second; pr[id]=nq; } mp.clear();
	//REP(i,n) printf("%d..%d: (%d,%d)\n",pl[i],pr[i],px[i],py[i]);

	REP(i,n) byrad[(ll)px[i]*px[i]+(ll)py[i]*py[i]].PB(i);
	for(auto it=byrad.begin();it!=byrad.end();++it) {
		vector<int> lst=it->second;
		REPSZ(ii,lst) FORSZ(jj,ii+1,lst) {
			int i=lst[ii],j=lst[jj];
			int l=max(pl[i],pl[j]),r=min(pr[i],pr[j]); if(l>r) continue;
			assert(px[i]!=px[j]||py[i]!=py[j]);
			int cx=px[i]+px[j],cy=py[i]+py[j],g=gcd(cx,cy); cx/=g,cy/=g;
			//printf("found match in [%d..%d] for dir (%d,%d)\n",l,r,cx,cy);
			matches[MP(cx,cy)].PB(MP(l,r));
		}
	}
	REP(i,n) {
		int cx=px[i],cy=py[i],g=gcd(cx,cy); cx/=g,cy/=g;
		singles[MP(cx,cy)].PB(MP(pl[i],pr[i]));
	}
	REP(i,nq) if(qkind[i]==3) { int cx=qx[i],cy=qy[i],g=gcd(cx,cy); cx/=g,cy/=g; queries[MP(cx,cy)].PB(i); }

	for(auto it=queries.begin();it!=queries.end();++it) {
		vector<int> cqueries=it->second;
		vector<pair<int,int>> cmatches=matches[it->first];
		vector<pair<int,int>> csingles=singles[it->first];
		vector<pair<int,int>> evt;
		REPSZ(i,cmatches) evt.PB(MP(cmatches[i].first,-2)),evt.PB(MP(cmatches[i].second+1,+2));
		REPSZ(i,csingles) evt.PB(MP(csingles[i].first,-1)),evt.PB(MP(csingles[i].second+1,+1));
		sort(cqueries.begin(),cqueries.end()); sort(evt.begin(),evt.end());
		int at=0,sum=0;
		REPSZ(i,cqueries) {
			int id=cqueries[i];
			while(at<SZ(evt)&&id>=evt[at].first) sum+=evt[at++].second;
			qans[id]+=sum;
		}
	}
	
	REP(i,nq) if(qkind[i]==3) printf("%d\n",qans[i]);
}

int main() {
	run();
	return 0;
}
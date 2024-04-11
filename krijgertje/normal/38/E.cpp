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
#include <list>
#include <cassert>
#include <climits>
#include <cstring>
#include <stack>
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
typedef vector<int> VI; typedef vector<VI> VVI; typedef vector<VVI> VVVI;

void run() {
	int n; scanf("%d",&n);
	vector<pair<int,int> > tmp(n); REP(i,n) scanf("%d%d",&tmp[i].first,&tmp[i].second); sort(tmp.begin(),tmp.end());
	vector<ll> x(n),c(n); REP(i,n) x[i]=tmp[i].first,c[i]=tmp[i].second;
	vector<ll> xsum(n+1); xsum[0]=0; REP(i,n) xsum[i+1]=xsum[i]+x[i];
	
	int first=-1,last=-1;
	vector<int> prev(n,-1),next(n,-1);
	vector<ll> a(n),b(n); // COST(i,j) = a[i]-j*b[i]+xsum[j+1]
	priority_queue<pair<ll,pair<int,int> > > events;

	vector<ll> best(n);
	REP(i,n) {
		queue<pair<int,int> > toremove;
		queue<pair<int,int> > tocheck;
		{
			a[i]=(i==0?0:best[i-1])+c[i]-xsum[i]+(i-1)*x[i],b[i]=x[i];
			if(first==-1) {
				assert(last==-1);
				first=last=i;
			} else {
				assert(last!=-1);
				tocheck.push(MP(last,i));
				next[last]=i; prev[i]=last; last=i;
			}
		}
		while(SZ(events)>0&&-events.top().first==i) {
			int v=events.top().second.first,w=events.top().second.second; events.pop();
			if(next[v]!=w||prev[w]!=v) continue;
			toremove.push(MP(v,w));
		}
		while(SZ(tocheck)>0||SZ(toremove)>0) {
			while(SZ(tocheck)>0) {
				int v=tocheck.front().first,w=tocheck.front().second; tocheck.pop();
				if(next[v]!=w||prev[w]!=v) continue;
				if(a[v]-i*b[v]>=a[w]-i*b[w]) {
					toremove.push(MP(v,w));
				} else {
					ll when=(a[w]-a[v]+b[w]-b[v]-1)/(b[w]-b[v]);
					assert(when>i);
					events.push(MP(-when,MP(v,w)));
				}
			}
			while(SZ(toremove)>0) {
				int v=toremove.front().first,w=toremove.front().second; toremove.pop();
				if(next[v]!=w||prev[w]!=v) continue;
				prev[w]=prev[v];
				if(prev[w]==-1) first=w; else next[prev[w]]=w;
				prev[v]=next[v]=-1;
				if(prev[w]!=-1) tocheck.push(MP(prev[w],w));
			}
		}
		
		best[i]=a[first]-i*b[first]+xsum[i+1];
		//printf("%d => %lld (%d)\n",i,best[i],first);
	}
	cout<<best[n-1]<<endl;
}


int main() {
//	freopen ("input.txt","r",stdin);
//	freopen ("output.txt","w",stdout);
//	int n; scanf("%d",&n); REP(i,n)
	run();
	return 0;
}
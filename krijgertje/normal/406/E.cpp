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

int len,ntot;
int n[2],pref[2][100000];

int maxval;
ll cntmaxval;
void found(int val,ll cnt) {
	//printf("%d (%lld)\n",val,cnt);
	if(cnt<=0) return;
	if(val>maxval) { maxval=val; cntmaxval=0; }
	if(val==maxval) cntmaxval+=cnt;
}

void run() {
	scanf("%d%d",&len,&ntot);
	n[0]=n[1]=0;
	REP(i,ntot) { int s,t; scanf("%d%d",&s,&t); pref[s][n[s]++]=t; }
	REP(i,2) sort(pref[i],pref[i]+n[i]);

	maxval=-1; cntmaxval=0;
	
	REP(t,2) if(n[t]>=3) { // all three start with same dig
		// a<=b<=c -> 2(c-a)
		int a=pref[t][0],c=pref[t][n[t]-1];
		if(pref[t][0]==pref[t][n[t]-1]) { found(2*(c-a),(ll)n[t]*(n[t]-1)*(n[t]-2)/6); continue; }
		int u=0; // first index for which pref[t][u]>pref[t][0]
		int v=0; // first index for which pref[t][v]=pref[t][n[t]-1]
		while(u<n[t]&&pref[t][u]<=pref[t][0]) ++u;
		while(v<n[t]&&pref[t][v]<pref[t][n[t]-1]) ++v;
		int na=u,nc=n[t]-v,nb=n[t]-na-nc;
		found(2*(c-a),(ll)na*nb*nc+(ll)na*(na-1)/2*nc+(ll)na*nc*(nc-1)/2);
	}
	
	REP(t,2) if(n[1-t]>=2) {
		int v=0; // first index for which pref[1-t][v]>=a
		int w=0; // first index for which pref[1-t][w]>pref[1-t][v]
		int u=0; // first index for which pref[1-t][u]=pref[1-t][v-1]
		
		REP(i,n[t]) { // first starts with different dig
			int a=pref[t][i];
			while(v<n[1-t]&&pref[1-t][v]<a) ++v;
			while(w<n[1-t]&&(w<v||pref[1-t][w]<=pref[1-t][v])) ++w;
			while(u<n[1-t]&&v-1>=0&&pref[1-t][u]<pref[1-t][v-1]) ++u;
			///printf("%d,%d:\n",t,a);
			// a<=b<=c -> 2(a+len-b)
			if(v<n[1-t]) {
				int b=pref[1-t][v],nequal=w-v,ngreater=n[1-t]-w;
				found(2*(a+len-b),(ll)nequal*ngreater+(ll)nequal*(nequal-1)/2);
			}
			// b<a<=c -> 2len
			{
				int nb=v,nc=n[1-t]-v;
				found(2*len,(ll)nb*nc);
			}
			// b<=c<a -> 2(c+len-a)
			if(v-1>=0) {
				int c=pref[1-t][v-1],nequal=v-u,nsmaller=u;
				found(2*(c+len-a),(ll)nequal*nsmaller+(ll)nequal*(nequal-1)/2);
			}
		}
	}

	cout<<cntmaxval<<endl;
}

int main() {
	run();
	return 0;
}
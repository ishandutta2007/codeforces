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

int n;
int x[1<<20];
int tmp[1<<20];

ll cur[21],other[21];


void run() {
	scanf("%d",&n);
	REP(i,1<<n) scanf("%d",&x[i]);

	cur[0]=other[0]=0;
	FORE(j,1,n) {
		cur[j]=other[j]=0;
		for(int at=0;at<(1<<n);at+=(1<<j)) {
			int a=at,b=at+(1<<(j-1)),A=b,B=at+(1<<j),c=0,C=(1<<j);
			//printf("\t[%d..%d) [%d..%d)\n",a,A,b,B);
			while(a<A||b<B) {
				int now=a<A&&(b>=B||x[a]<=x[b])?x[a]:x[b];
				int na=a; while(na<A&&x[na]==now) ++na;
				int nb=b; while(nb<B&&x[nb]==now) ++nb;
				//printf("\t\t%d..%d %d..%d\n",a,na,b,nb);
				cur[j]+=(ll)(na-a)*(b-A);
				other[j]+=(ll)(na-a)*(B-nb);
				//cur[j]+=(ll)(nb-b)*(A-na);
				//other[j]+=(ll)(nb-b)*(a-at);
				while(a<na) tmp[c++]=x[a++];
				while(b<nb) tmp[c++]=x[b++];
			}
			REP(i,C) x[at+i]=tmp[i];
		}
		//REP(i,1<<n) printf("%d ",x[i]); printf("[%lld / %lld]\n",cur[j],other[j]);
	}


	int nq; scanf("%d",&nq);
	REP(i,nq) {
		int q; scanf("%d",&q);
		REPE(j,q) swap(cur[j],other[j]);
		ll ret=0; REPE(j,n) ret+=cur[j]; cout<<ret<<endl;
	}
}

int main() {
	run();
	return 0;
}
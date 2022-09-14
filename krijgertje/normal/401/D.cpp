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
#include <climits>
#include <cassert>
#include <ctime>
#include <cstring>
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

ll x; int MOD;

int cnt[10];
int rem[10];
int mult[10];

int calckey() {
	int ret=0;
	REP(i,10) ret=ret*(cnt[i]+1)+rem[i];
	printf("\t"); REP(i,10) printf("%d",rem[i]); printf(" -> %d\n",ret);
	return ret;
}

ll mem[59049][100];

ll go(int key,int offset) {
	//bool done=true; REP(i,10) if(rem[i]>0) done=false; if(done) return offset==0?1:0;
	if(key==0) return offset==0?1:0;
	/*int key=calckey();*/ //assert(key<59049);
	ll &ret=mem[key][offset];
	if(ret==-1) {
		ret=0;
		REP(i,10) if(rem[i]>0) { --rem[i]; ret+=go(key-mult[i],(offset*10+i)%MOD); ++rem[i]; }
		//REP(i,10) printf("%d",rem[i]); printf(" (%d) = %lld\n",offset,ret);
	}
	return ret;
}



void run() {
	cin>>x>>MOD;
	memset(cnt,0,sizeof(cnt)); for(ll y=x;y!=0;y/=10) cnt[y%10]++;
	mult[9]=1; for(int i=8;i>=0;--i) mult[i]=mult[i+1]*(cnt[i+1]+1);
	//REP(i,10) printf("%d",cnt[i]); puts("");
	//REP(i,10) printf(" %d",mult[i]); puts("");
	int skey=0; REP(i,10) skey+=cnt[i]*mult[i];

	memset(mem,-1,sizeof(mem));
	REP(i,10) rem[i]=cnt[i];
	ll ret=0;
	FOR(i,1,10) if(rem[i]>0) {
		--rem[i];
		ll cur=go(skey-mult[i],i%MOD);
		ret+=cur;
		++rem[i];
	}
	cout<<ret<<endl;
}

int main() {
	run();
	return 0;
}
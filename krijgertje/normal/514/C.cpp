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


const int MODS[]={982451501,982451549,982451567,982451579,982451581,982451609,982451629,982451653};
const int NMODS=8;

typedef struct X {
	int len;
	ll val[NMODS];
} X;
bool operator<(const X &p,const X &q) {
	if(p.len!=q.len) return p.len<q.len;
	REP(j,NMODS) if(p.val[j]!=q.val[j]) return p.val[j]<q.val[j];
	return false;
}
void print(const X &p) {
	printf("%d:",p.len); REP(j,NMODS) printf(" %lld",p.val[j]); puts("");
}

int now[NMODS][600000];

int np,nq;
set<X> have;

char s[600001]; int slen;

void run() {
	scanf("%d%d",&np,&nq);

	REP(j,NMODS) now[j][0]=1;
	REP(j,NMODS) FOR(k,1,600000) now[j][k]=((ll)now[j][k-1]*3)%MODS[j];
	REP(i,np) {
		scanf("%s",s); slen=strlen(s);
		X cur; cur.len=slen; REP(j,NMODS) cur.val[j]=0;
		REP(k,slen) REP(times,s[k]-'a') REP(j,NMODS) cur.val[j]+=now[j][k];
		REP(j,NMODS) cur.val[j]%=MODS[j];
		have.insert(cur);
		//print(cur);
	}

	REP(i,nq) {
		scanf("%s",s); slen=strlen(s);
		X cur; cur.len=slen; REP(j,NMODS) cur.val[j]=0;
		REP(k,slen) REP(times,s[k]-'a') REP(j,NMODS) cur.val[j]+=now[j][k];
		REP(j,NMODS) cur.val[j]%=MODS[j];
		bool found=false;
		//print(cur);
		REP(k,slen) {
			if(s[k]=='a') {
				REP(j,NMODS) if((cur.val[j]+=now[j][k])>=MODS[j]) cur.val[j]-=MODS[j];
				//printf("\t"); print(cur);
				if(have.count(cur)) { found=true; break; }
				REP(j,NMODS) if((cur.val[j]+=now[j][k])>=MODS[j]) cur.val[j]-=MODS[j];
				//printf("\t"); print(cur);
				if(have.count(cur)) { found=true; break; }
				REP(j,NMODS) if((cur.val[j]-=now[j][k])<0) cur.val[j]+=MODS[j];
				REP(j,NMODS) if((cur.val[j]-=now[j][k])<0) cur.val[j]+=MODS[j];
			}
			if(s[k]=='b') {
				REP(j,NMODS) if((cur.val[j]-=now[j][k])<0) cur.val[j]+=MODS[j];
				//printf("\t"); print(cur);
				if(have.count(cur)) { found=true; break; }
				REP(j,NMODS) if((cur.val[j]+=now[j][k])>=MODS[j]) cur.val[j]-=MODS[j];
				REP(j,NMODS) if((cur.val[j]+=now[j][k])>=MODS[j]) cur.val[j]-=MODS[j];
				//printf("\t"); print(cur);
				if(have.count(cur)) { found=true; break; }
				REP(j,NMODS) if((cur.val[j]-=now[j][k])<0) cur.val[j]+=MODS[j];
			}
			if(s[k]=='c') {
				REP(j,NMODS) if((cur.val[j]-=now[j][k])<0) cur.val[j]+=MODS[j];
				REP(j,NMODS) if((cur.val[j]-=now[j][k])<0) cur.val[j]+=MODS[j];
				//printf("\t"); print(cur);
				if(have.count(cur)) { found=true; break; }
				REP(j,NMODS) if((cur.val[j]+=now[j][k])>=MODS[j]) cur.val[j]-=MODS[j];
				//printf("\t"); print(cur);
				if(have.count(cur)) { found=true; break; }
				REP(j,NMODS) if((cur.val[j]+=now[j][k])>=MODS[j]) cur.val[j]-=MODS[j];
			}
		}
		printf("%s\n",found?"YES":"NO");
	}
}

void gen() {
	np=30000; nq=30000;
	printf("%d %d\n",np,nq);
	REP(i,np) { REP(j,10) printf("%c",'a'+rand()%3); puts(""); }
	REP(i,nq) { REP(j,10) printf("%c",'a'+rand()%3); puts(""); }
}


int main() {
	//gen();
	run();
	return 0;
}
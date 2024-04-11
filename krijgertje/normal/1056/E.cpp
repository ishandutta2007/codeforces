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
int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }

const int MAXSLEN=100000;
const int MAXTLEN=1000000;

char s[MAXSLEN+1]; int slen;
char t[MAXTLEN+1]; int tlen;

int a[MAXSLEN],na;
int b[MAXSLEN],nb;

const uint64_t MOD = (1ull<<61) - 1;
int MLT;
uint64_t HPW[MAXTLEN+1];
uint64_t HSUM[MAXTLEN+1];

uint64_t modmul(uint64_t a, uint64_t b){
	uint64_t l1 = (uint32_t)a, h1 = a>>32, l2 = (uint32_t)b, h2 = b>>32;
	uint64_t l = l1*l2, m = l1*h2 + l2*h1, h = h1*h2;
	uint64_t ret = (l&MOD) + (l>>61) + (h << 3) + (m >> 29) + (m << 35 >> 3) + 1;
	ret = (ret & MOD) + (ret>>61);
	ret = (ret & MOD) + (ret>>61);
	return ret-1;
}

void hprecalc() {
    mt19937 rng((uint64_t) chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count());
    MLT = uniform_int_distribution<int>(0, 1<<30)(rng);
	HPW[0]=1; FORE(i,1,tlen) HPW[i]=modmul(HPW[i-1],MLT);
	HSUM[0]=0; REP(i,tlen) HSUM[i+1]=(modmul(HSUM[i],MLT)+t[i]-'a')%MOD;
}
uint64_t hget(int l,int r) {
	uint64_t ret=HSUM[r]+MOD-modmul(HSUM[l],HPW[r-l]);
	if(ret>=MOD) ret-=MOD;
	//printf("hget(%d,%d) = %llu\n",l,r,ret);
	return ret;
}



bool ok(int alen,int blen) {
	//printf("checking %d %d\n",alen,blen);
	na=nb=0; int at=0; REP(i,slen) if(s[i]=='0') a[na++]=at,at+=alen; else if(s[i]=='1') b[nb++]=at,at+=blen;

	if(alen==blen&&hget(a[0],a[0]+alen)==hget(b[0],b[0]+blen)) return false;
	FOR(i,1,na) if(hget(a[0],a[0]+alen)!=hget(a[i],a[i]+alen)) return false;
	FOR(i,1,nb) if(hget(b[0],b[0]+blen)!=hget(b[i],b[i]+blen)) return false;
	//printf("ok\n");
	return true;
}

int solve() {
	hprecalc();
	int na=0,nb=0; REP(i,slen) if(s[i]=='0') ++na; else if(s[i]=='1') ++nb; else assert(false); assert(na>=1&&nb>=1);

	int ret=0;
	for(int alen=1;alen*na<tlen;++alen) {
		if((tlen-alen*na)%nb!=0) continue;
		int blen=(tlen-alen*na)/nb;
		if(ok(alen,blen)) ++ret;
	}
	return ret;
}

void run() {
	scanf("%s",s); slen=strlen(s);
	scanf("%s",t); tlen=strlen(t);
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}
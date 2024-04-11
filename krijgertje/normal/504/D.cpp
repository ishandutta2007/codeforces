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
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

int getbit(const ull x[32]) {
	REP(i,32) if(x[i]!=0) REP(j,64) if((x[i]&(1ULL<<j))!=0) return 64*i+j;
	return -1;
}
bool isset(const ull x[32],int idx) {
	int i=idx/64,j=idx%64; return (x[i]&(1ULL<<j))!=0;
}
void convert(char* s,ull x[32]) {
	REP(i,32) {
		ull carry=0;
		for(int j=0;s[j]!='\0';++j) {
			ull ncarry=s[j]-'0'; s[j]='0';
			REP(k,10) {
				if(ncarry<=ULLONG_MAX-carry) ncarry+=carry;
				else s[j]++,ncarry-=ULLONG_MAX-carry+1;
			}
			carry=ncarry;
		}
		x[i]=carry;
	}
	for(int j=0;s[j]!='\0';++j) assert(s[j]=='0');
}

int n;
char s[601];
	
int m;
int bit[2000];
ull val[2000][32];
ull id[2000][32];

int ret[2000],nret;

void run() {
	scanf("%d",&n);
	m=0;
	REP(i,n) {
		scanf("%s",s); 
		convert(s,val[m]); REP(k,32) id[m][k]=0;
		REP(j,m) if(isset(val[m],bit[j])) { REP(k,32) val[m][k]^=val[j][k],id[m][k]^=id[j][k]; }
		bit[m]=getbit(val[m]);
		//REP(k,32) printf("%llu ",val[m][k]); puts("");
		if(bit[m]==-1) {
			int nret=0; REP(j,n) if(isset(id[m],j)) ret[nret++]=j;
			printf("%d",nret); REP(j,nret) printf(" %d",ret[j]); puts("");
		} else {
			printf("0\n");
			id[m][i/64]|=1ULL<<(i%64); m++;
		}
	}
}

int main() {
	run();
	return 0;
}
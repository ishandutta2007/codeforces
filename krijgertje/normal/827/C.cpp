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

const int MAXLEN=100000;
const int MAXQLEN=10;
const int ALPH=4;
const int MAXBIT=MAXLEN*MAXQLEN*ALPH;

char s[MAXLEN+1]; int slen;
int nq; char q[MAXQLEN+1]; int qlen;


vector<int> idx[MAXLEN][4]; int nidx;
int bit[MAXBIT+1];
int off[MAXQLEN+1][MAXQLEN][4];

int conv(char c) { if(c=='A') return 0; if(c=='C') return 1; if(c=='G') return 2; if(c=='T') return 3; assert(false); return -1; }
void bmod(int x,int by) { ++x; while(x<=nidx) { bit[x]+=by; x+=x&-x; } }
int bget(int x) { ++x; int ret=0; while(x>0) { ret+=bit[x]; x-=x&-x; } return ret; }


void run() {
	scanf("%s",s); slen=strlen(s);
	REP(i,slen) REP(c,4) idx[i][c].clear(); nidx=0;
	for(qlen=1;qlen<=MAXQLEN;++qlen) REP(o,qlen) REP(c,4) {
		off[qlen][o][c]=nidx;
		for(int i=o;i<slen;i+=qlen) idx[i][c].PB(nidx++);
	}

	memset(bit,0,sizeof(bit));
	REP(i,slen) { char c=conv(s[i]); REPSZ(j,idx[i][c]) bmod(idx[i][c][j],+1); }

	scanf("%d",&nq);
	REP(qi,nq) {
		int kind; scanf("%d",&kind);
		if(kind==1) {
			int pos; char ch; scanf("%d %c",&pos,&ch); --pos; int oc=conv(s[pos]),nc=conv(ch);
			REPSZ(j,idx[pos][oc]) bmod(idx[pos][oc][j],-1); s[pos]=ch; REPSZ(j,idx[pos][nc]) bmod(idx[pos][nc][j],+1);
		}
		if(kind==2) {
			int l,r; scanf("%d%d%s",&l,&r,q); qlen=strlen(q); --l,--r;
			int ret=0;
			REP(o,qlen) {
				int cl=(l-o+qlen-1)/qlen,cr=r<o?-1:(r-o)/qlen,qidx=((o-l)%qlen+qlen)%qlen,c=conv(q[qidx]); if(cl>cr) continue;
				//printf("\t%d: %d..%d [%d,%d] (%d,%d) {%d}\n",o,off[qlen][o][c]+cl,off[qlen][o][c]+cr,o+cl*qlen,o+cr*qlen,l,r,qidx);
				ret+=bget(off[qlen][o][c]+cr)-bget(off[qlen][o][c]+cl-1);
			}
			printf("%d\n",ret);
		}
	}


}

int main() {
	run();
	return 0;
}
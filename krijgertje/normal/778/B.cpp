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

const int MAXN=5000;
const int MAXD=1000;
const int MAXLEN=10;
const int LIT=0;
const int OP=1;
const int OPAND=0;
const int OPOR=1;
const int OPXOR=2;

int n,d;
char buff[MAXLEN+MAXD+1];
map<string,int> mp;

int typ[MAXN];
int expr[MAXN][3],op[MAXN];
char val[MAXN][MAXD+1];
char mn[MAXD+1],mx[MAXD+1];

int getid(string s) {
	if(s=="?") return -1;
	if(mp.count(s)) return mp[s];
	int ret=SZ(mp); return mp[s]=ret;
}
int parseop(string s) {	if(s=="AND") return OPAND; else if(s=="OR") return OPOR; else if(s=="XOR") return OPXOR; }

int tmp[MAXN];
int getval(int e,int pos,int qval) { if(e==-1) return qval; return tmp[e]; }
int calc(int pos,int qval) {
	int ret=0;
	REP(i,n) {
		int a=expr[i][0],cur;
		if(typ[i]==LIT) {
			cur=val[i][pos]-'0';
		} else {
			int b=getval(expr[i][1],pos,qval),c=getval(expr[i][2],pos,qval);
			cur=op[i]==OPAND?(b&c):op[i]==OPOR?(b|c):op[i]==OPXOR?(b^c):0;
		}
		//printf("\t%d  (%d,%d) = %d\n",i,pos,qval,cur);
		tmp[a]=cur; ret+=cur;
	}
	return ret;
}

void run() {
	scanf("%d%d",&n,&d); mp.clear();
	REP(i,n) {
		scanf("%s",buff); int a=getid(buff);
		scanf("%s",buff); // :=
		scanf("%s",val[i]); if(val[i][0]=='0'||val[i][0]=='1') { typ[i]=LIT; expr[i][0]=a; continue; } int b=getid(val[i]);
		scanf("%s",buff);  int o=parseop(buff);
		scanf("%s",buff); int c=getid(buff);
		typ[i]=OP; expr[i][0]=a; expr[i][1]=b; expr[i][2]=c; op[i]=o;
	}
	//REP(i,n) { printf("%d:",i); if(typ[i]==LIT) printf(" %d %s\n",expr[i][0],val[i]); else printf(" %d %d %d (%d)\n",expr[i][0],expr[i][1],expr[i][2],op[i]); }
	REP(i,d) {
		int a=calc(i,0),b=calc(i,1);
		//printf("%d -> %d / %d\n",i,a,b);
		mn[i]=a<=b?'0':'1'; mx[i]=a>=b?'0':'1';
	}
	mn[d]=mx[d]='\0'; printf("%s\n%s\n",mn,mx);
}

int main() {
	run();
	return 0;
}
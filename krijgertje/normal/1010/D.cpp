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

const int MAXN=1000000;
const int OPAND=2,OPOR=3,OPXOR=4,OPNOT=5;

int n;
int op[MAXN];
vector<int> ch[MAXN];
int res[MAXN];
int ans[MAXN];

int dfsres(int at) {
	if(op[at]==0||op[at]==1) {
		res[at]=op[at];
	} else if(op[at]==OPNOT) {
		res[at]=1-dfsres(ch[at][0]);
	} else if(op[at]==OPAND) {
		int a=dfsres(ch[at][0]),b=dfsres(ch[at][1]);
		res[at]=a==1&&b==1?1:0;
	} else if(op[at]==OPOR) {
		int a=dfsres(ch[at][0]),b=dfsres(ch[at][1]);
		res[at]=a==1||b==1?1:0;
	} else if(op[at]==OPXOR) {
		int a=dfsres(ch[at][0]),b=dfsres(ch[at][1]);
		res[at]=(a==1)^(b==1)?1:0;
	} else {
		assert(false);
	}
	return res[at];
}
void dfsans(int at,int fix,bool neg) {
	if(op[at]==0||op[at]==1) {
		ans[at]=fix!=-1?fix:1-op[at];
		if(fix==-1&&neg) ans[at]=1-ans[at];
	} else if(op[at]==OPNOT) {
		dfsans(ch[at][0],fix,!neg);
	} else if(op[at]==OPAND) {
		REP(i,2) dfsans(ch[at][i],fix!=-1?fix:res[ch[at][1-i]]==0?(neg?1:0):-1,neg);
	} else if(op[at]==OPOR) {
		REP(i,2) dfsans(ch[at][i],fix!=-1?fix:res[ch[at][1-i]]==1?(neg?0:1):-1,neg);
	} else if(op[at]==OPXOR) {
		REP(i,2) dfsans(ch[at][i],fix!=-1?fix:-1,res[ch[at][1-i]]==1?!neg:neg);
	} else {
		assert(false);
	}
}

void run() {
	scanf("%d",&n);
	REP(i,n) {
		char buff[10]; scanf("%s",buff);
		if(strcmp(buff,"AND")==0) { int a,b; scanf("%d%d",&a,&b); --a,--b; op[i]=OPAND; ch[i].PB(a); ch[i].PB(b); }
		else if(strcmp(buff,"OR")==0) { int a,b; scanf("%d%d",&a,&b); --a,--b; op[i]=OPOR; ch[i].PB(a); ch[i].PB(b); }
		else if(strcmp(buff,"XOR")==0) { int a,b; scanf("%d%d",&a,&b); --a,--b; op[i]=OPXOR; ch[i].PB(a); ch[i].PB(b); }
		else if(strcmp(buff,"NOT")==0) { int a; scanf("%d",&a); --a; op[i]=OPNOT; ch[i].PB(a); }
		else if(strcmp(buff,"IN")==0) { int val; scanf("%d",&val); op[i]=val; }
		else { printf("err: %s\n",buff); assert(false); }
	}

	dfsres(0);
	dfsans(0,-1,false);
	REP(i,n) if(op[i]==0||op[i]==1) printf("%d",ans[i]); puts("");
}

int main() {
	run();
	return 0;
}
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

const int MAXWORD=100000;
const int MAXLEN=20;

int nw,nrel,nq;
char w[MAXWORD][MAXLEN+1];
char buff[MAXLEN+1];
map<string,int> dict;

int par[MAXWORD];
int rnk[MAXWORD];
bool same[MAXWORD];

int readw() {
	scanf("%s",buff);
	assert(dict.count(string(buff)));
	return dict[string(buff)];
}

void find(int &a,bool &s) {
	if(par[a]==a) { assert(same[a]); return; }
	//printf("find(%d,%c)\n",a,s?'=':'!');
	int b=par[a]; bool t=same[a]; find(b,t);
	par[a]=b; same[a]=t; 
	//printf("find(%d,%c)=>(%d,%c)\n",a,s?'=':'!',b,(t?s:!s)?'=':'!');
	a=b; s=t?s:!s;
}

bool unite(int a,int b,bool s) {
	//printf("unite(%d,%d,%c)\n",a,b,s?'=':'!');
	find(a,s); find(b,s);
	if(a==b) return s;
	if(rnk[a]<rnk[b]) swap(a,b);
	par[b]=a; same[b]=s; if(rnk[a]==rnk[b]) ++rnk[a];
	return true;
}

void run() {
	scanf("%d%d%d",&nw,&nrel,&nq);
	REP(i,nw) scanf("%s",w[i]);
	dict=map<string,int>(); REP(i,nw) dict[string(w[i])]=i;
	REP(i,nw) par[i]=i,rnk[i]=0,same[i]=true;
	REP(i,nrel) {
		int type; scanf("%d",&type); int a=readw(); int b=readw();
		printf("%s\n",unite(a,b,type==1)?"YES":"NO");
	}
	REP(i,nq) {
		 int a=readw(); int b=readw(); bool s=true;
		 find(a,s); find(b,s);
		 printf("%d\n",a!=b?3:s?1:2);
	}
}

int main() {
	run();
	return 0;
}
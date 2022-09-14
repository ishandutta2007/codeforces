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
int p[200000];
int pos[200001];

int nadd;
int firstadd[200000];
int valadd[2472113];
int nextadd[2472113];

int m;
int l[200000],r[200000];
int ans[200000];

int firstq[200000];
int nextq[200000];

const int treeN=(1<<20)-1;
int treeval[treeN+1];
void addtree(int x) { while(x<=treeN) { treeval[x]++; x+=x&-x; } }
int gettree(int x) { int ret=0; while(x>0) { ret+=treeval[x]; x-=x&-x; } return ret; }

void run(int casenr) {
	scanf("%d%d",&n,&m);
	REP(i,n) scanf("%d",&p[i]);
	REP(i,m) { scanf("%d%d",&l[i],&r[i]); --l[i]; --r[i]; }
	
	nadd=0;
	memset(firstadd,-1,sizeof(firstadd));
	REP(i,n) pos[p[i]]=i;
	FORE(i,1,n) for(int j=i;j<=n;j+=i) {
		int a=pos[i],b=pos[j]; if(a>b) swap(a,b);
		valadd[nadd]=a; nextadd[nadd]=firstadd[b]; firstadd[b]=nadd++;
	}
	
	memset(firstq,-1,sizeof(firstq));
	REP(i,m) { nextq[i]=firstq[r[i]]; firstq[r[i]]=i; }
	
	int treesum=0;
	REP(i,n) {
		for(int x=firstadd[i];x!=-1;x=nextadd[x]) { addtree(valadd[x]+1); ++treesum; }
		for(int x=firstq[i];x!=-1;x=nextq[x]) { ans[x]=treesum-gettree(l[x]-1+1); }
	}

	REP(i,m) printf("%d\n",ans[i]);
}

int main() {
	//int n; scanf("%d",&n); FORE(i,1,n) run(i);
	run(1);
	return 0;
}
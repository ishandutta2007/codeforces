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

int n;
int nme,nopp;

int a[100000],b[100000];
int meorder[100000],opporder[100000],skiporder[100000];
int type[100000];

bool mecmp(const int &p,const int &q) { if(a[p]!=a[q]) return a[p]>a[q]; return b[p]>b[q]; }
bool oppcmp(const int &p,const int &q) { if(b[p]!=b[q]) return b[p]>b[q]; return a[p]<a[q]; }
bool skipcmp(const int &p,const int &q) { return b[p]>b[q]; }

void run(int casenr) {
	scanf("%d%d%d",&n,&nme,&nopp);
	REP(i,n) scanf("%d%d",&a[i],&b[i]);

	REP(i,n) meorder[i]=i; sort(meorder,meorder+n,mecmp);
	REP(i,n) opporder[i]=i; sort(opporder,opporder+n,oppcmp);
	REP(i,n) skiporder[i]=i; sort(skiporder,skiporder+n,skipcmp);

	memset(type,-1,sizeof(type));
	REP(i,nme-nopp) type[opporder[n-i-1]]=0;
	int lefttake=nopp,lasttake=-1; REP(i,n) if(lefttake>0&&type[meorder[i]]==-1) { type[meorder[i]]=1; --lefttake; if(lasttake==-1||oppcmp(lasttake,meorder[i])) lasttake=meorder[i]; }
	int leftskip=nme-nopp; REP(i,n) if(type[skiporder[i]]!=1&&leftskip>0&&!oppcmp(skiporder[i],lasttake)) { type[skiporder[i]]=2; --leftskip; }

//	REP(i,n) printf("%d = %d (%d,%d)\n",i+1,type[i],a[i],b[i]);
	bool first=true; REP(i,n) if(type[i]==1||type[i]==2) { if(first) first=false; else printf(" "); printf("%d",i+1); } puts("");
}


int main() {
//	int n; scanf("%d",&n); FORE(i,1,n) run(i);
	run(1);
	return 0;
}
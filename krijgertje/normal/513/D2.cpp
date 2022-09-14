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


int n,ncond;
bool anyleft[1000000];
bool anyrght[1000000];
int minleft[1000000];
int maxleft[1000000];
int minrght[1000000];
int maxrght[1000000];

int ret[1000000],nret;

// returns nr of nodes in tree, or -1 if impossible
int create(int root,int contained) {
	//printf("\tcreating(%d,%d)\n",root+1,contained+1);
	if(contained<root) return -1;
	if(!anyleft[root]&&!anyrght[root]&&contained==root) { ret[nret++]=root; return 1; }
	int lroot=root+1,rroot,nleft=0,nrght=0;
	if(anyleft[root]&&minleft[root]<lroot) return -1;
	if(anyleft[root]) {
		nleft=create(lroot,maxleft[root]);
		if(nleft==-1) return -1;
		rroot=lroot+nleft;
	} else {
		rroot=lroot;
	}
	if(anyrght[root]&&minrght[root]<rroot) return -1;
	ret[nret++]=root;
	if(anyrght[root]||contained>=rroot) {
		nrght=create(rroot,max(anyrght[root]?maxrght[root]:rroot,contained<rroot?rroot:contained));
		if(nrght==-1) return -1;
	}
	return nleft+1+nrght;
}


void run() {
	scanf("%d%d",&n,&ncond);
	REP(i,n) anyleft[i]=anyrght[i]=false;
	REP(i,ncond) {
		int a,b; char s[10]; scanf("%d%d%s",&a,&b,s); --a,--b;
		if(strcmp(s,"LEFT")==0) {
			if(!anyleft[a]) anyleft[a]=true,minleft[a]=maxleft[a]=b;
			if(b<minleft[a]) minleft[a]=b; if(b>maxleft[a]) maxleft[a]=b;
		} else if(strcmp(s,"RIGHT")==0) {
			if(!anyrght[a]) anyrght[a]=true,minrght[a]=maxrght[a]=b;
			if(b<minrght[a]) minrght[a]=b; if(b>maxrght[a]) maxrght[a]=b;
		}
	}
	nret=0;
	int res=create(0,n-1);
	if(res==-1) { printf("IMPOSSIBLE\n"); return; }
	REP(i,nret) { if(i!=0) printf(" "); printf("%d",ret[i]+1); } puts("");
}

int main() {
	run();
	return 0;
}
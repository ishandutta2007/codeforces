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

int h,w,bound;
int a[100][100];

int type[100]; //row


int calc(int nrows) {
	int ret=0;
	REP(j,w) {
		int cnt=0; REP(i,nrows) if(a[i][j]+type[i]==1) ++cnt;
		ret+=min(cnt,nrows-cnt);
		//printf("\t%d\n",cnt);
	}
//	REP(i,nrows) printf("%d",type[i]); printf(" -> %d\n",ret);
	return ret;
}

int go(int at) {
	int curbound=calc(at);
	if(curbound>bound) return -1;
	if(at>=h) return curbound;
	int ret=-1;
	for(type[at]=0;type[at]<=1;++type[at]) {
		int cur=go(at+1);
		if(cur!=-1&&(ret==-1||cur<ret)) ret=cur;
	}
	return ret;
}

void run() {
	scanf("%d%d%d",&h,&w,&bound);
	if(w>=h) {
		REP(i,h) REP(j,w) scanf("%d",&a[i][j]);
	} else {
		REP(i,h) REP(j,w) scanf("%d",&a[j][i]); swap(h,w);
	}

	type[0]=0; int ret=go(1);
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}
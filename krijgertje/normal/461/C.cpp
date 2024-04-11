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

const int MAXLEN=100000;

int slen,nq;
int cnt[MAXLEN];
int fst,lst;


int sum[1<<17];
void inc(int a,int by) {
	cnt[a]+=by;
	a+=2;
	while(a<(1<<17)) {
		sum[a]+=by;
		a+=a&-a;
	}
}

int get(int a) {
	a+=2; int ret=0;
	while(a!=0) {
		ret+=sum[a];
		a-=a&-a;
	}
	return ret;
}

void printstate() {
	int dir=fst<=lst?+1:-1;
	printf("%d..%d: ",fst,lst); for(int i=fst;;i+=dir) { printf("%d ",cnt[i]); if(i==lst) break; } puts("");
}

void run() {
	scanf("%d%d",&slen,&nq);
	fst=0,lst=slen-1; FORE(i,fst,lst) inc(i,1);
	REP(qi,nq) {
		int type; scanf("%d",&type);
		if(type==1) {
			int idx; scanf("%d",&idx);
			int len=abs(lst-fst)+1,dir=fst<=lst?+1:-1;
			if(2*idx<=len) {
				REP(i,idx) inc(fst+dir*(idx+idx-i-1),cnt[fst+dir*i]);
				fst+=dir*idx;
			} else {
				idx=len-idx;
				REP(i,idx) inc(lst-dir*(idx+idx-i-1),cnt[lst-dir*i]);
				lst-=dir*idx; swap(fst,lst);
			}
			//printstate();
		}
		if(type==2) {
			int l,r; scanf("%d%d",&l,&r);
			int dir=fst<=lst?+1:-1;
			l=fst+l*dir,r=fst+(r-1)*dir; if(l>r) swap(l,r);
			printf("%d\n",get(r)-get(l-1));
		}
	}
}

int main() {
	run();
	return 0;
}
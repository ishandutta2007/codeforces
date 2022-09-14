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


int n,nevents;
int p[300000];
int inv[300000];

int val[1<<19];
int get(int x) {
	++x;
//	printf("get %d\n",x);
	int ret=0; while(x!=0) { ret+=val[x]; x-=x&-x; } return ret;
}
void update(int x,int by) {
	++x;
//	printf("updating %d by %d\n",x,by);
	while(x!=1<<19) { val[x]+=by; x+=x&-x; }
}

void run(int casenr) {
	scanf("%d",&n);
	REP(i,n) { scanf("%d",&p[i]); --p[i]; }
	REP(i,n) inv[p[i]]=i;
	memset(val,0,sizeof(val));
	REP(i,n-1) if(inv[i+1]<inv[i]) update(i,+1);

	scanf("%d",&nevents);
	REP(e,nevents) {
		int type,x,y; scanf("%d%d%d",&type,&x,&y); --x,--y;
		if(type==1) {
			int ans=get(y-1)-get(x-1)+1;
			printf("%d\n",ans);
		}
		if(type==2) {
			int a=p[x],b=p[y];
			int lst[4],nlst=0;
			if(a-1>=0) lst[nlst++]=a-1;
			if(a+1<n) lst[nlst++]=a;
			if(b-1>=0) lst[nlst++]=b-1;
			if(b+1<n) lst[nlst++]=b;
			sort(lst,lst+nlst);
			REP(i,nlst) if(i==0||lst[i]!=lst[i-1]) {
				int xi=lst[i],xj=xi+1,pi=inv[xi],pj=inv[xj],ni=pi==x?y:pi==y?x:pi,nj=pj==x?y:pj==y?x:pj;
				int delta=(nj<ni?1:0)-(pj<pi?1:0);
				if(delta!=0) update(xi,delta);
			}
			swap(p[x],p[y]); inv[p[x]]=x; inv[p[y]]=y;
//			REP(i,n) printf("%d ",p[i]+1); puts(""); REP(i,n) assert(inv[p[i]]==i);
		}
	}
}


int main() {
//	int n; scanf("%d",&n); FORE(i,1,n) run(i);
	run(1);
	return 0;
}
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

int X,Y;

int lstd[2*1000*1000+1];
int prvd[1001*1001];
int dx[1001*1001];
int dy[1001*1001];

int n,m;
int lstn;
int prvn[1001*1001];
int lste[1001*1001];
int prve[1001*1001];
int to[1001*1001];
double len[1001*1001];

int res[4];
double ret;

void addedge(int x1,int y1,int x2,int y2) {
	int a=x1*(Y+1)+y1,b=x2*(Y+1)+y2;
	if(lste[a]==-1) { prvn[a]=lstn; lstn=a; ++n; }
	if(lste[b]==-1) { prvn[b]=lstn; lstn=b; ++n; }
	prve[m]=lste[a],to[m]=b,len[m]=sqrt(1.0*(x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)); lste[a]=m++;
	prve[m]=lste[b],to[m]=a,len[m]=sqrt(1.0*(x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)); lste[b]=m++;
}

void run() {
	scanf("%d%d",&X,&Y);

	memset(lstd,-1,sizeof(lstd));
	REPE(x,X) REPE(y,Y) {
		int i=x*(Y+1)+y,key=x*x+y*y;
		prvd[i]=lstd[key],dx[i]=x,dy[i]=y,lstd[key]=i;
	}

	n=m=0; ret=0; double diag=sqrt(1.0*X*X+Y*Y);
	lstn=-1;
	memset(lste,-1,sizeof(lste));
	for(int key=X*X+Y*Y;key>0;--key) {
		if(lstd[key]==-1) continue;
		if(ret!=0&&2*diag+sqrt(1.0*key)<=ret) break;
		for(int z=lstd[key];z!=-1;z=prvd[z]) {
			REPE(x,X-dx[z]) REPE(y,Y-dy[z]) {
				addedge(x,y,x+dx[z],y+dy[z]);
				if(dx[z]!=0&&dy[z]!=0) addedge(x,y+dy[z],x+dx[z],y);
			}
		}

//		printf("%d\n",key);
//		printf("%d ",lstn);	REP(i,(X+1)*(Y+1)) if(prvn[i]!=-1) printf(" %d->%d",i,prvn[i]); puts("");
//		REP(i,(X+1)*(Y+1)) if(lste[i]!=-1) printf("%d->%d ",i,lste[i]); puts("");
//		REP(i,m) printf("%d->%d ",i,prve[i]); puts("");
//		puts("");

		for(int a=lstn;a!=-1;a=prvn[a]) {
			for(int b=lste[a];b!=-1;b=prve[b]) {
				if(to[b]==a) continue;
				for(int c=lste[to[b]];c!=-1;c=prve[c]) {
					if(to[c]==a||to[c]==to[b]) continue;
					for(int d=lste[to[c]];d!=-1;d=prve[d]) {
						if(to[d]==a||to[d]==to[b]||to[d]==to[c]) continue;
						double cur=len[b]+len[c]+len[d];
						if(cur>ret) ret=cur,res[0]=a,res[1]=to[b],res[2]=to[c],res[3]=to[d];
					}
				}
			}
		}
	}
	if(ret!=0) {
		REP(i,4) printf("%d %d\n",res[i]/(Y+1),res[i]%(Y+1));
		return;
	}
	printf("error\n");
}

int main() {
	run();
	return 0;
}
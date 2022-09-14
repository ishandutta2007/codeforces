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
ll gcd(ll u, ll v) { while ( v != 0) { ll r = u % v; u = v; v = r; } return u; }

int n,want;
int fst[400];
int nxt[800];
int from[800],to[800];
bool up[800];

int mincost[800][401]; // dp[i][j] = minimum number of edges to cut in from[i]+to[i]+to[nxt[i]]+to[nxt[nxt[i]]]+... to make its size j, undefined for j=0
int bestact[800][401]; // the size to[i] gets for it

void calc(int x) {
	up[x^1]=true;

	int y=nxt[x];
	if(y!=-1&&up[y]) y=nxt[y];
	int z=fst[to[x]];
	if(z!=-1&&up[z]) z=nxt[z];

	if(y!=-1) calc(y);
	if(z!=-1) calc(z);

	if(y==-1) {
		mincost[x][1]=1;
		bestact[x][1]=0;
		if(z==-1) {
			mincost[x][2]=0;
			bestact[x][2]=1;
			FORE(i,3,want) mincost[x][i]=INT_MAX;
		} else {
			FORE(i,2,want) if(mincost[z][i-1]!=INT_MAX) {
				mincost[x][i]=mincost[z][i-1];
				bestact[x][i]=i-1;	
			}
		}
	} else {
		FORE(i,1,want) {
			if(mincost[y][i]!=INT_MAX) {
				mincost[x][i]=mincost[y][i]+1;
				bestact[x][i]=0;
			}
			FOR(j,1,i) {
				if(z==-1&&j!=1) continue;
				int a=z==-1?0:mincost[z][j],b=mincost[y][i-j];
				if(a==INT_MAX||b==INT_MAX) continue;
				int cur=a+b;
				if(cur<mincost[x][i]) {
					mincost[x][i]=cur;
					bestact[x][i]=j;
				}
			}
		}
	}
//	printf("%d->%d\n",from[x],to[x]);
//	FORE(i,1,want) if(mincost[x][i]!=INT_MAX) printf("%d:%d(%d) ",i,mincost[x][i],bestact[x][i]); else printf("%d:X ",i); puts("");
}

int ret[400],nret;
void go(int x,int i) {
	int y=nxt[x];
	if(y!=-1&&up[y]) y=nxt[y];
	int z=fst[to[x]];
	if(z!=-1&&up[z]) z=nxt[z];

	int a=bestact[x][i],b=i-a;
	if(a==0) {
		ret[nret++]=x;
	} else if(z==-1) {
		assert(a==1);
	} else {
		go(z,a);
	}
	if(y==-1) {
		assert(b==1);
	} else {
		go(y,b);
	}
}


void run() {
	scanf("%d%d",&n,&want);
	memset(fst,-1,sizeof(fst));
	memset(up,false,sizeof(up));
	REP(i,n-1) {
		int a,b; scanf("%d%d",&a,&b); --a,--b;
		nxt[2*i+0]=fst[a]; from[2*i+0]=a; to[2*i+0]=b; fst[a]=2*i+0;
		nxt[2*i+1]=fst[b]; from[2*i+1]=b; to[2*i+1]=a; fst[b]=2*i+1;
	}

	if(want==1) {
		if(n==1) {
			printf("%d\n\n",0);
		} else {
			REP(i,n) if(nxt[fst[i]]==-1) {
				printf("%d\n%d\n",1,fst[i]/2+1);
				break;
			}
		}
		return;
	}

	REP(x,2*(n-1)) REPE(i,want) mincost[x][i]=INT_MAX;
	calc(fst[0]);

	int bx=-1,bst=INT_MAX;
	REP(i,n) {
		int x=fst[i];
		if(x!=-1&&up[x]) x=nxt[x];
		if(x==-1||mincost[x][want]==INT_MAX) continue;
		int cur=mincost[x][want]+(i==0?0:1);
		if(cur<bst) { bst=cur; bx=x; }
	}
	assert(bx!=-1);
//	printf("%d->%d (%d)\n",from[bx],to[bx],bst);

	nret=0;
	if(from[bx]!=0) {
		for(int y=fst[from[bx]];y!=-1;y=nxt[y]) if(up[y]) ret[nret++]=y^1;
	}
	go(bx,want);
	assert(bst==nret);
	printf("%d\n",nret);
	REP(i,nret) { if(i!=0) printf(" "); printf("%d",ret[i]/2+1); } puts("");


}

int main() {
	run();
	return 0;
}
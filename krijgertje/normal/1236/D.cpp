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
#include <bitset>
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
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXH=100000;
const int MAXW=100000;
const int MAXP=100000;
const int DX[]={0,+1,0,-1},DY[]={+1,0,-1,0};

int h,w,np;
int px[MAXP],py[MAXP];

vector<int> onrow[MAXH];
vector<int> oncol[MAXW];

int calcstepsright(int at,const vector<int> &blocks,int lim) {
	int idx=lower_bound(blocks.begin(),blocks.end(),at)-blocks.begin();
	//if(idx<SZ(blocks)) printf("at=%d blocks[idx]=%d\n",at,blocks[idx]);
	assert(idx>=SZ(blocks)||blocks[idx]!=at);
	if(idx>=SZ(blocks)||blocks[idx]>lim) return lim-at; else return blocks[idx]-at-1;
}
int calcstepsleft(int at,const vector<int> &blocks,int lim) {
	int idx=lower_bound(blocks.begin(),blocks.end(),at)-blocks.begin();
	assert(idx>=SZ(blocks)||blocks[idx]!=at);
	--idx;
	if(idx<0||blocks[idx]<lim) return at-lim; else return at-blocks[idx]-1;
}
bool isblocked(int x,int y) {
	int idx=lower_bound(onrow[x].begin(),onrow[x].end(),y)-onrow[x].begin();
	return idx<SZ(onrow[x])&&onrow[x][idx]==y;
}


bool solve() {
	REP(x,h) onrow[x].clear(); REP(y,w) oncol[y].clear(); REP(i,np) onrow[px[i]].PB(py[i]),oncol[py[i]].PB(px[i]);
	REP(x,h) sort(onrow[x].begin(),onrow[x].end()); REP(y,w) sort(oncol[y].begin(),oncol[y].end());
	ll want=(ll)h*w-np;
	ll have=0;
	int x=0,y=0,k=0,lx=0,hx=h-1,ly=0,hy=w-1;
	while(true) {
		//printf("x=%d y=%d k=%d have=%lld\n",x,y,k,have);
		int nsteps=0;
		if(DY[k]==+1) nsteps=calcstepsright(y,onrow[x],hy);
		if(DY[k]==-1) nsteps=calcstepsleft(y,onrow[x],ly);
		if(DX[k]==+1) nsteps=calcstepsright(x,oncol[y],hx);
		if(DX[k]==-1) nsteps=calcstepsleft(x,oncol[y],lx);
		x+=nsteps*DX[k],y+=nsteps*DY[k],have+=nsteps+1;
		k=(k+1)%4;
		x+=DX[k],y+=DY[k];
		if(DX[k]==+1) lx=x; else if(DX[k]==-1) hx=x; else if(DY[k]==+1) ly=y; else if(DY[k]==-1) hy=y;
		if(x<lx||x>hx||y<ly||y>hy||isblocked(x,y)) break;
	}
	return have==want;
}

void run() {
	scanf("%d%d%d",&h,&w,&np);
	REP(i,np) scanf("%d%d",&px[i],&py[i]),--px[i],--py[i];
	printf("%s\n",solve()?"Yes":"No");
}

int main() {
	run();
	return 0;
}
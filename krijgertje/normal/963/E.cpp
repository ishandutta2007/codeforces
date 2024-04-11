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

const int MOD=1000000007;
const int MAXR=50;
const int MAXP=7845;
const int MAXV=2*MAXR+1;
const int DX[]={-1,0,+1,0},DY[]={0,+1,0,-1};
int pw(int x,int n) { int ret=1; while(true) { if(n&1) ret=(ll)ret*x%MOD; if((n>>=1)==0) return ret; x=(ll)x*x%MOD; } }
int inv(int x) { return pw(x,MOD-2); }


int R,a1,a2,a3,a4;
int pup,plt,prt,pdn;
int prob[4];

map<pair<int,int>,int> mp;
vector<pair<int,int> > p;

int nv;
bool done[MAXP];
int eq[MAXP][MAXV]; int eqcnst[MAXP];
int cur[MAXV]; int curcnst; int curdnid;

void run() {
	scanf("%d%d%d%d%d",&R,&a1,&a2,&a3,&a4);
	
	int pinv=inv(a1+a2+a3+a4); plt=(ll)a1*pinv%MOD,pdn=(ll)a2*pinv%MOD,prt=(ll)a3*pinv%MOD,pup=(ll)a4*pinv%MOD; prob[0]=plt,prob[1]=pup,prob[2]=prt,prob[3]=pdn;
	p.clear(); for(int y=R;y>=-R;--y) FORE(x,-R,+R) if(x*x+y*y<=R*R) mp[MP(x,y)]=SZ(p),p.PB(MP(x,y));
	//printf("np=%d\n",SZ(p));

	nv=2*R+1; REPSZ(i,p) done[i]=false;
	for(int y=R;y>=-R;--y) FORE(x,-R,+R) if(x*x+y*y<=R*R) {
		int id=mp[MP(x,y)];
		REP(j,nv) cur[j]=0; curcnst=1; curdnid=-1;
		REP(k,4) {
			int nx=x+DX[k],ny=y+DY[k],nid=-1;
			if(mp.count(MP(nx,ny))) nid=mp[MP(nx,ny)];
			if(nid==-1) continue;
			if(ny<y) { curdnid=nid; continue; }
			if(nx>x) { cur[nx+R]=(cur[nx+R]+prob[k])%MOD; continue; }
			REP(j,nv) cur[j]=(cur[j]+(ll)prob[k]*eq[nid][j])%MOD; curcnst=(curcnst+(ll)prob[k]*eqcnst[nid])%MOD;
		}
		//printf("cur:"); REP(j,nv) printf(" %d",cur[j]); printf(" / %d\n",curcnst);

		int v=x+R;
		int vmlt=inv((1+MOD-cur[v])%MOD); cur[v]=curdnid==-1?0:prob[3]; REP(j,nv) cur[j]=(ll)cur[j]*vmlt%MOD; curcnst=(ll)curcnst*vmlt%MOD;
		REP(pv,nv) if(pv!=v) {
			int py=pv<v?y:y+1,px=pv-R,pid=-1;
			if(mp.count(MP(px,py))) pid=mp[MP(px,py)]; else continue;
			assert(done[pid]);
			int mlt=eq[pid][v]; eq[pid][v]=0; REP(j,nv) eq[pid][j]=(eq[pid][j]+(ll)cur[j]*mlt)%MOD; eqcnst[pid]=(eqcnst[pid]+(ll)curcnst*mlt)%MOD;
		}
		//REPSZ(i,p) if(done[i]) { int mlt=eq[i][v]; eq[i][v]=0; REP(j,nv) eq[i][j]=(eq[i][j]+(ll)cur[j]*mlt)%MOD; eqcnst[i]=(eqcnst[i]+(ll)curcnst*mlt)%MOD; }
		done[id]=true; REP(j,nv) eq[id][j]=cur[j]; eqcnst[id]=curcnst;

		//printf("after (%d,%d): [%d,%d,%d,%d,%d]\n",x,y,curdnid,vmlt,v,eq[id][v],nv);
		//REPSZ(i,p) if(done[i]) { printf("(%d,%d): %d",p[i].first,p[i].second,eqcnst[i]); REP(j,nv) if(eq[i][j]!=0) printf(" +%d*x%d",eq[i][j],j-R); puts(""); }
		//puts("");
	}
	FORE(y,-R,+R) for(int x=R;x>=-R;--x) if(x*x+y*y<=R*R) {
		int id=mp[MP(x,y)],v=x+R;
		REP(pv,nv) {
			int ny=pv<v?y-2:y-1,nx=pv-R,nid=-1;
			if(mp.count(MP(nx,ny))) nid=mp[MP(nx,ny)]; else continue;
			//printf("(%d,%d)->(%d,%d)\n",x,y,nx,ny);
			int mlt=eq[id][pv]; eq[id][pv]=0; eqcnst[id]=(eqcnst[id]+(ll)mlt*eqcnst[nid])%MOD;
		}
	}

	//REPSZ(i,p) if(done[i]) { printf("(%d,%d): %d",p[i].first,p[i].second,eqcnst[i]); REP(j,nv) if(eq[i][j]!=0) printf(" +%d*x%d",eq[i][j],j-R); puts(""); }
	printf("%d\n",eqcnst[mp[MP(0,0)]]);
}

int main() {
	run();
	return 0;
}
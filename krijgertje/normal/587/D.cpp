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

const int MAXN=50000;
const int MAXM=50000;
const int IMAXN=6*MAXM;
const int IMAXM=4*MAXM+8*MAXM+2*MAXM;

int n,m;
int ghead[MAXN],gnxt[2*MAXM],gto[2*MAXM],gc[MAXM],gt[MAXM],gsame[2*MAXM];
pair<int,int> c[MAXM]; int nc;

int id[MAXM],cid[2*MAXM],nid;

int in,im;
int ihead[IMAXN],inxt[IMAXM],ito[IMAXM];

int idx[IMAXN],mnidx[IMAXN],nidx;
int stck[IMAXM],nstck;
int comp[IMAXN],ncomp;
int chead[IMAXN],cnxt[IMAXN];
int cval[IMAXN];

int ret[MAXM],nret;

void addcond(int a,int b) {
	//printf("add %d or %d\n",a,b);
	int aa=a>=nid?a-nid:a+nid,bb=b>=nid?b-nid:b+nid;
	inxt[im]=ihead[aa]; ihead[aa]=im; ito[im]=b; ++im;
	if(a!=b) { inxt[im]=ihead[bb]; ihead[bb]=im; ito[im]=a; ++im; }
}
void strongconnect(int at) {
	idx[at]=mnidx[at]=nidx++;
	stck[nstck++]=at;
	for(int x=ihead[at];x!=-1;x=inxt[x]) {
		int to=ito[x];
		if(idx[to]==-1) {
			strongconnect(to);
			if(mnidx[to]<mnidx[at]) mnidx[at]=mnidx[to];
		} else if(comp[to]==-1) {
			if(idx[to]<mnidx[at]) mnidx[at]=idx[to];
		}
	}
	if(idx[at]==mnidx[at]) {
		chead[ncomp]=-1;
		while(stck[nstck-1]!=at) {
			int to=stck[--nstck];
			cnxt[to]=chead[ncomp]; chead[ncomp]=to;
			comp[to]=ncomp;
		}
		{
			int to=stck[--nstck];
			cnxt[to]=chead[ncomp]; chead[ncomp]=to;
			comp[to]=ncomp++;
		}
	}
}

bool can(int tmx) {
	//printf("testing %d\n",tmx);
	memset(id,-1,sizeof(id)); memset(cid,-1,sizeof(cid));
	nid=0; REP(i,m) if(gt[i]<=tmx) id[i]=nid++,cid[2*i+0]=nid++,cid[2*i+1]=nid++;
	in=2*nid,im=0; REP(i,in) ihead[i]=-1;
	REP(i,m) if(id[i]!=-1) addcond(cid[2*i+0],nid+id[i]),addcond(cid[2*i+1],nid+id[i]);
	REP(i,n) { int lst=-1; for(int x=ghead[i];x!=-1;x=gnxt[x]) if(id[x>>1]!=-1) { if(lst!=-1) addcond(nid+id[lst>>1],nid+cid[x]),addcond(cid[lst],nid+cid[x]); lst=x; } }
	REP(i,n) for(int x=ghead[i];x!=-1;x=gnxt[x]) if(gsame[x]!=-1&&x<gsame[x]) {
		if(id[x>>1]==-1&&id[gsame[x]>>1]==-1) return false;
		else if(id[x>>1]==-1) addcond(id[gsame[x]>>1],id[gsame[x]>>1]);
		else if(id[gsame[x]>>1]==-1) addcond(id[x>>1],id[x>>1]);
		else addcond(id[x>>1],id[gsame[x]>>1]);
	}
	//REP(i,in) { printf("%d:",i); for(int x=ihead[i];x!=-1;x=inxt[x]) printf(" %d",ito[x]); puts(""); }
	nidx=nstck=ncomp=0; REP(i,in) idx[i]=comp[i]=cval[i]=-1;
	REP(i,in) if(comp[i]==-1) strongconnect(i);
	//REP(i,in) printf("%d ",comp[i]); puts("");
	REP(i,nid) if(comp[i]==comp[i+nid]) return false;
	REP(i,ncomp) if(cval[chead[i]]==-1) for(int x=chead[i];x!=-1;x=cnxt[x]) cval[x]=1,cval[x>=nid?x-nid:x+nid]=0;
	//REP(i,in) printf("%d ",cval[i]); puts("");
	nret=0; REP(i,m) if(id[i]!=-1&&cval[id[i]]==1) ret[nret++]=i;
	return true;
}

void run() {
	scanf("%d%d",&n,&m);
	REP(i,n) ghead[i]=-1;
	REP(i,m) {
		int a,b; scanf("%d%d%d%d",&a,&b,&gc[i],&gt[i]); --a,--b;
		gnxt[2*i+0]=ghead[a]; ghead[a]=2*i+0; gto[2*i+0]=b;
		gnxt[2*i+1]=ghead[b]; ghead[b]=2*i+1; gto[2*i+1]=a;
	}

	REP(i,n) {
		nc=0; for(int x=ghead[i];x!=-1;x=gnxt[x]) c[nc++]=MP(gc[x>>1],x);
		sort(c,c+nc);
		int at=0;
		while(at<nc) {
			int to=at; while(to<nc&&c[at].first==c[to].first) ++to;
			if(to-at>=3) { printf("No\n"); return; }
			if(to-at==2) { gsame[c[at].second]=c[at+1].second; gsame[c[at+1].second]=c[at].second; }
			if(to-at==1) { gsame[c[at].second]=-1; }
			at=to;
		}
	}
	//REP(i,n) { printf("%d:",i); for(int x=ghead[i];x!=-1;x=gnxt[x]) printf(" %d:%d(c%dx%d=%d)",x,gto[x],gc[x>>1],gt[x>>1],gsame[x]); puts(""); }

	int tmx=gt[0]; FOR(i,1,m) if(gt[i]>tmx) tmx=gt[i];
	int l=-1,r=tmx+1; //(l,r]
	while(l+1<r) {
		int m=l+(r-l)/2;
		if(can(m)) r=m; else l=m;
	}
	if(r==tmx+1) { printf("No\n"); return; }
	assert(can(r));

	printf("Yes\n%d %d\n",r,nret);
	REP(i,nret) { if(i!=0) printf(" "); printf("%d",ret[i]+1); } puts("");
}

int main() {
	run();
	return 0;
}
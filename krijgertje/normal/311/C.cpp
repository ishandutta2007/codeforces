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

ll ncells; int ntreasures,nops,basestep;
ll cell[100000]; int amount[100000];

int order[100000];
bool mycmp (int i,int j) { return cell[i]<cell[j]; }
int first[10000],nxt[100000];

ll t[10000];

int nh;
int h[100000];
int hpos[100000];

bool better(int x,int y) {
	if(amount[x]!=amount[y]) return amount[x]>amount[y];
	return x<y;
}

void down(int x) {
	while(2*x+1<nh) {
		int y=2*x+1;
		if(y+1<nh&&better(h[y+1],h[y])) ++y;
		if(!better(h[y],h[x])) break;
		swap(h[x],h[y]); hpos[h[x]]=x; hpos[h[y]]=y; x=y;
	}
}

void up(int x) {
	while(x!=0) {
		int y=(x-1)/2;
		if(!better(h[x],h[y])) break;
		swap(h[x],h[y]); hpos[h[x]]=x; hpos[h[y]]=y; x=y;
	}
}

int nh2;
int h2[10000];
int hpos2[10000];

bool better2(int x,int y) {
	return t[x]<t[y];
}

void down2(int x) {
	while(2*x+1<nh2) {
		int y=2*x+1;
		if(y+1<nh2&&better2(h2[y+1],h2[y])) ++y;
		if(!better2(h2[y],h2[x])) break;
		swap(h2[x],h2[y]); hpos2[h2[x]]=x; hpos2[h2[y]]=y; x=y;
	}
}

void up2(int x) {
	while(x!=0) {
		int y=(x-1)/2;
		if(!better2(h2[x],h2[y])) break;
		swap(h2[x],h2[y]); hpos2[h2[x]]=x; hpos2[h2[y]]=y; x=y;
	}
}


void addcells(int offset) {
	while(t[offset]!=-1&&first[offset]!=-1&&cell[first[offset]]>=t[offset]) {
		int at=first[offset]; h[nh]=at; hpos[at]=nh; ++nh; up(hpos[at]); first[offset]=nxt[at];
	}
}

void run(int casenr) {
	cin>>ncells; scanf("%d%d%d",&ntreasures,&nops,&basestep);
	REP(i,ntreasures) { cin>>cell[i]; scanf("%d",&amount[i]); --cell[i]; }
	
	REP(i,ntreasures) order[i]=i; sort(order,order+ntreasures,mycmp);
	memset(first,-1,sizeof(first));
	REP(i,ntreasures) { int at=order[i]; int offset=cell[at]%basestep; nxt[at]=first[offset]; first[offset]=at; }
	
//	REP(i,basestep) if(first[i]!=-1) { printf("%d:",i); for(int x=first[i];x!=-1;x=nxt[x]) printf(" %d=[%lld,%d]",x,cell[x],amount[x]); puts(""); }
	
	nh=0; memset(hpos,-1,sizeof(hpos));
	memset(t,-1,sizeof(t));
	t[0]=0; addcells(0);
	
	REP(op,nops) {
//		printf("\t"); REP(i,nh) printf("%d[%d] ",h[i],hpos[h[i]]); puts("");
		int type; scanf("%d",&type);
		if(type==1) {
			ll nstep; cin>>nstep;
			nh2=0; memset(hpos2,-1,sizeof(hpos2));
			REP(i,basestep) if(t[i]!=-1) { h2[nh2]=i; hpos2[i]=nh2; ++nh2; up2(hpos2[i]); }
			while(nh2>0) {
				int at=h2[0]; hpos2[at]=-1;
				if(nh2==1) --nh2; else  { h2[0]=h2[--nh2]; hpos2[h2[0]]=0; down2(0); }
				int to=(int)((at+nstep)%basestep); ll nt=t[at]+nstep;
				if((t[to]==-1||nt<t[to])&&nt<=ncells) {
					t[to]=nt; addcells(to);
					if(hpos2[to]==-1) { h2[nh2]=to; hpos2[to]=nh2; ++nh2; up2(hpos2[to]); }
					else up2(hpos2[to]);
				}
			}
//			REP(i,basestep) printf("%d = %lld\n",i,t[i]);
		} else if(type==2) {
			int x,y; scanf("%d%d",&x,&y); --x;
			amount[x]-=y;
			if(hpos[x]!=-1) down(hpos[x]);
		} else if(type==3) {
			int ans;
			if(nh==0) {
				ans=0;
			} else {
				int at=h[0];
				ans=amount[at];
				hpos[at]=-1;
				if(nh==1) --nh; else  { h[0]=h[--nh]; hpos[h[0]]=0; down(0); }
			}
			printf("%d\n",ans);
		}
	}
}

int main() {
	//int n; scanf("%d",&n); FORE(i,1,n) run(i);
	run(1);
	return 0;
}
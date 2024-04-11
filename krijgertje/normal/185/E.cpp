#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<iostream>
#include<cassert>
#include<queue>
#include<limits.h>
using namespace std;

#define PB push_back
#define MP make_pair
#define SZ(v) ((int)(v).size())
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define FORE(i,a,b) for(int i=(a);i<=(b);++i)
#define REPE(i,n) FORE(i,0,n)
#define REPSZ(i,v) REP(i,SZ(v))
#define FORSZ(i,a,v) FOR(i,a,SZ(v))

typedef struct P {
	int x,y,dist;
	P(int x,int y):x(x),y(y) {}
	P() {}
} P;
P convertFromVW(int v,int w) { return P((v+w),(v-w)); }
bool decreasingdistsort (P a,P b) { return a.dist>b.dist; }
int V(const P &a) { return a.x+a.y; }
int W(const P &a) { return a.x-a.y; }
bool xsort(P* a,P* b) { if(a->x!=b->x) return a->x<b->x; return a->y<b->y; }
int dist(P* a,P* b) { return abs(a->x-b->x)+abs(a->y-b->y); }

typedef struct E {
	int lv,lw,hv,hw,dist;
	E(int lv,int lw,int hv,int hw):lv(lv),lw(lw),hv(hv),hw(hw) {}
} E;

typedef struct NoUseSubwayState {
	int t,lv,lw,hv,hw;
	NoUseSubwayState(int t,int lv,int lw,int hv,int hw):t(t),lv(lv),lw(lw),hv(hv),hw(hw) { assert(t>=0); assert(lv<=hv); assert(lw<=hw); }
	NoUseSubwayState(P p):t(0),lv(V(p)),lw(W(p)),hv(V(p)),hw(W(p)) { assert(t>=0); assert(lv<=hv); assert(lw<=hw); }
} TRect;
typedef struct SomeUseSubWayState {
	NoUseSubwayState nousesubwaystate; int usesubwayt; int closestsubway;
	SomeUseSubWayState(NoUseSubwayState nousesubwaystate,int usesubwayt):nousesubwaystate(nousesubwaystate),usesubwayt(usesubwayt),closestsubway(INT_MAX) {}
} SomeUseSubWayState;

bool isPoint(NoUseSubwayState state) { return state.lv==state.hv&&state.lw==state.hw; }
bool isLine(NoUseSubwayState state) { return state.lv==state.hv||state.lw==state.hw; }
NoUseSubwayState grow(NoUseSubwayState a,int dt) { assert(dt>=0); return NoUseSubwayState(a.t+dt,a.lv-dt,a.lw-dt,a.hv+dt,a.hw+dt); }
NoUseSubwayState calc(NoUseSubwayState a,NoUseSubwayState b) {
	assert(b.t<=a.t);
	b=grow(b,a.t-b.t);
	if(a.hv<b.lv) { int dt=(b.lv-a.hv+1)/2; a=grow(a,dt); b=grow(b,dt); }
	if(b.hv<a.lv) { int dt=(a.lv-b.hv+1)/2; a=grow(a,dt); b=grow(b,dt); }
	if(a.hw<b.lw) { int dt=(b.lw-a.hw+1)/2; a=grow(a,dt); b=grow(b,dt); }
	if(b.hw<a.lw) { int dt=(a.lw-b.hw+1)/2; a=grow(a,dt); b=grow(b,dt); }
	NoUseSubwayState ret=NoUseSubwayState(a.t,max(a.lv,b.lv),max(a.lw,b.lw),min(a.hv,b.hv),min(a.hw,b.hw));
	return ret;
}

vector<P*> all;
void go(int l,int h,int d) {
	assert(l<=h);
	if(l==h) return;
	int m=l+(h-l)/2; go(l,m,d+1); go(m+1,h,d+1);
	vector<P*> nval(h-l+1);
	int left=m,right=h,best=-1,at=h-l;
//	printf("\t"); REP(i,d) printf(" "); printf("merging %d..%d and %d..%d\n",l,m,m+1,h);
	while(left>=l||right>=m+1) {
//		if(l==0&&h==8) { printf("\t"); REP(i,d) printf(" "); printf("left=%d right=%d best=%d\n",left,right,best); }
		if(left<l||right>=m+1&&all[right]->y>=all[left]->y) {
			if(left>=l&&all[right]->dist==-1&&(best==-1||dist(all[left],all[right])<dist(all[left],all[best]))) best=right;
			nval[at--]=all[right--];
		} else {
			if(all[left]->dist!=-1&&best!=-1) { int cur=dist(all[left],all[best]); if(cur<all[left]->dist) all[left]->dist=cur; }
			nval[at--]=all[left--];
		}
	}
	assert(at==-1);
	REPSZ(i,nval) all[l+i]=nval[i];
//	FORE(i,l,h) { printf("\t"); REP(j,d) printf(" "); printf("%d: (%d,%d) -> %d\n",i,all[i]->x,all[i]->y,all[i]->dist); }
}

void calculateclosest(vector<P> &from,vector<P> &to) {	// Order of from can not change
	if(SZ(from)==0) return;
	REPSZ(i,from) from[i].dist=INT_MAX;
	REPSZ(i,to) to[i].dist=-1;
	REP(xdir,2) {
		REP(ydir,2) {
			all.clear();
			REPSZ(i,from) all.PB(&from[i]);
			REPSZ(i,to) all.PB(&to[i]);
			sort(all.begin(),all.end(),xsort);
//			printf("closestP %d,%d\n",xdir,ydir);
//			REPSZ(i,all) printf("%d: (%d,%d) -> %d\n",i,all[i]->x,all[i]->y,all[i]->dist);
			go(0,SZ(all)-1,0);
//			REPSZ(i,all) printf("%d: (%d,%d) -> %d\n",i,all[i]->x,all[i]->y,all[i]->dist);
			REPSZ(i,from) from[i].y=-from[i].y;
			REPSZ(i,to) to[i].y=-to[i].y;
		}
		REPSZ(i,from) from[i].x=-from[i].x;
		REPSZ(i,to) to[i].x=-to[i].x;
	}
}


typedef struct Event {
	int ind,a,b,b1,b2;
	Event(int ind,int a,int b1,int b2):ind(ind),a(a),b1(b1),b2(b2) {}
	Event(int a,int b):ind(-1),a(a),b(b) {}
} Event;
bool operator<(const Event &p,const Event &q) {
	if(p.a!=q.a) return !(p.a<q.a);
	if(p.ind!=q.ind) return !(p.ind==-1);
	return false;
}

vector<int> segkeys,segvalues;
int initSeg(int x,int l,int h) {
	if(l==h) {
		while(x>=SZ(segvalues)) segvalues.PB(0);
		return segvalues[x]=INT_MIN;
	} else {
		int m=l+(h-l)/2;
		int a=initSeg(2*x+1,l,m);
		int b=initSeg(2*x+2,m+1,h);
		return segvalues[x]=max(a,b);
	}
}

int setSeg(int x,int l,int h,int key,int val) {
	if(key<l||key>h) return segvalues[x];
	if(l==h) {
		return segvalues[x]=val;
	} else {
		int m=l+(h-l)/2;
		int a=setSeg(2*x+1,l,m,key,val);
		int b=setSeg(2*x+2,m+1,h,key,val);
		return segvalues[x]=max(a,b);
	}
}

int getSeg(int x,int l,int h,int lkey,int hkey) {
	if(lkey<l) lkey=l; if(hkey>h) hkey=h;
	if(lkey>hkey) return INT_MIN;
	if(l==lkey&&h==hkey) {
		return segvalues[x];
	} else {
		int m=l+(h-l)/2;
		int a=getSeg(2*x+1,l,m,lkey,hkey);
		int b=getSeg(2*x+2,m+1,h,lkey,hkey);
		return max(a,b);
	}
}

void calculateclosest(vector<E> &from,vector<P> &to) { // Order of from can not change
	REPSZ(i,from) from[i].dist=INT_MAX;
	REP(coord,2) REP(dir,2) { // coord -> v/w, dir -> +/-
		vector<int> allb;
		if(coord==0) REPSZ(i,from) { allb.PB(from[i].lw); allb.PB(from[i].hw); }
		if(coord==1) REPSZ(i,from) { allb.PB(from[i].lv); allb.PB(from[i].hv); }
		if(coord==0) REPSZ(i,to) allb.PB(W(to[i]));
		if(coord==1) REPSZ(i,to) allb.PB(V(to[i]));
		if(SZ(allb)==0) continue;
		sort(allb.begin(),allb.end()); allb.erase(unique(allb.begin(),allb.end()),allb.end());
		map<int,int> bmap; REPSZ(i,allb) bmap[allb[i]]=i;
//		printf("calcedges (%d,%d) -> %d\n",coord,dir,SZ(allb));

		segkeys=allb; segvalues.clear(); int n=SZ(segkeys);
		initSeg(0,0,n-1);

		priority_queue<Event> q;
		if(coord==0) REPSZ(i,from) if(from[i].lv==from[i].hv) q.push(Event(i,dir==0?+from[i].lv:-from[i].lv,bmap[from[i].lw],bmap[from[i].hw]));
		if(coord==1) REPSZ(i,from) if(from[i].lw==from[i].hw) q.push(Event(i,dir==0?+from[i].lw:-from[i].lw,bmap[from[i].lv],bmap[from[i].hv]));
		if(coord==0) REPSZ(i,to) q.push(Event(dir==0?+V(to[i]):-V(to[i]),bmap[W(to[i])]));
		if(coord==1) REPSZ(i,to) q.push(Event(dir==0?+W(to[i]):-W(to[i]),bmap[V(to[i])]));
		while(!q.empty()) {
			Event at=q.top(); q.pop();
			if(at.ind==-1) {
//				printf("\t%d: %d\n\b",at.a,at.b);
				setSeg(0,0,n-1,at.b,at.a);
			} else {
				int a2=getSeg(0,0,n-1,at.b1,at.b2);
//				printf("\t%d: %d..%d ->%d\n",at.a,at.b1,at.b2,a2);
				assert(a2<=at.a);
				if(a2!=INT_MIN) {
					int cur=at.a-a2;
					assert(cur>=0);
					if(cur<from[at.ind].dist) from[at.ind].dist=cur;
				}
			}
		}
	}
}

void run() {
	// read input
	int ndwarves,nsubways; scanf("%d%d",&ndwarves,&nsubways);
	vector<P> dwarves(ndwarves); REP(i,ndwarves) scanf("%d %d",&dwarves[i].x,&dwarves[i].y);
	vector<P> subways(nsubways); REP(i,nsubways) scanf("%d %d",&subways[i].x,&subways[i].y);

	// for each dwarf, determine distance to closest subway
	calculateclosest(dwarves,subways);
	sort (dwarves.begin(), dwarves.end(), decreasingdistsort);
//	REPSZ(i,dwarves) printf("(%d,%d) -> %d\n",dwarves[i].x,dwarves[i].y,dwarves[i].dist);

	// enumerate all options
	int ret_allusesubway=dwarves[0].dist; // all dwarves go to subway
	vector<SomeUseSubWayState> someusesubwaystates;
	NoUseSubwayState nousesubwaystate=NoUseSubwayState(dwarves[0]);
	FOR(i,1,ndwarves) { // i dwarves that are farthest from subway dont use it, others do
//		if(i<10) printf("%d: %d -> (%d,%d)-(%d,%d) l=(%d,%d)\n",i,nousesubwaystate.t,nousesubwaystate.lv,nousesubwaystate.lw,nousesubwaystate.hv,nousesubwaystate.hw,dwarves[i-1].x,dwarves[i-1].y);
		if(dwarves[i].dist!=INT_MAX) someusesubwaystates.PB(SomeUseSubWayState(nousesubwaystate,dwarves[i].dist));
		nousesubwaystate=calc(nousesubwaystate,NoUseSubwayState(dwarves[i]));
	}
	int ret_noneusesubway=nousesubwaystate.t; // no dwarves go to subway

	// calculate distances to corners
	vector<P> corners;
	REPSZ(i,someusesubwaystates) 
	REP(v,someusesubwaystates[i].nousesubwaystate.lv==someusesubwaystates[i].nousesubwaystate.hv?1:2)
	REP(w,someusesubwaystates[i].nousesubwaystate.lw==someusesubwaystates[i].nousesubwaystate.hw?1:2) {
		int vv=v==0?someusesubwaystates[i].nousesubwaystate.lv:someusesubwaystates[i].nousesubwaystate.hv;
		int ww=w==0?someusesubwaystates[i].nousesubwaystate.lw:someusesubwaystates[i].nousesubwaystate.hw;
		corners.PB(convertFromVW(vv,ww));
	}
	REPSZ(i,subways) { subways[i].x*=2; subways[i].y*=2; }
	calculateclosest(corners,subways);
	REPSZ(i,corners) { assert(corners[i].dist%2==0); corners[i].dist/=2; }
	REPSZ(i,subways) { subways[i].x/=2; subways[i].y/=2; }
	int atcorner=0;
	REPSZ(i,someusesubwaystates) 
	REP(v,someusesubwaystates[i].nousesubwaystate.lv==someusesubwaystates[i].nousesubwaystate.hv?1:2)
	REP(w,someusesubwaystates[i].nousesubwaystate.lw==someusesubwaystates[i].nousesubwaystate.hw?1:2) {
		int vv=v==0?someusesubwaystates[i].nousesubwaystate.lv:someusesubwaystates[i].nousesubwaystate.hv;
		int ww=w==0?someusesubwaystates[i].nousesubwaystate.lw:someusesubwaystates[i].nousesubwaystate.hw;
		if(corners[atcorner].dist<someusesubwaystates[i].closestsubway) {
//				printf("some[%d] -> corner %d -> %d\n",i,atcorner,corners[atcorner].dist);
			someusesubwaystates[i].closestsubway=corners[atcorner].dist;
		}
		++atcorner;
	}

	// calculate distances to edges
	vector<E> edges;
	REPSZ(i,someusesubwaystates) {
		assert(someusesubwaystates[i].nousesubwaystate.hv-someusesubwaystates[i].nousesubwaystate.lv<=1||someusesubwaystates[i].nousesubwaystate.hw-someusesubwaystates[i].nousesubwaystate.lw<=1);
		if(someusesubwaystates[i].nousesubwaystate.hw-someusesubwaystates[i].nousesubwaystate.lw>=2) FORE(v,someusesubwaystates[i].nousesubwaystate.lv,someusesubwaystates[i].nousesubwaystate.hv) {
			edges.PB(E(v,someusesubwaystates[i].nousesubwaystate.lw,v,someusesubwaystates[i].nousesubwaystate.hw));
		}
		if(someusesubwaystates[i].nousesubwaystate.hv-someusesubwaystates[i].nousesubwaystate.lv>=2) FORE(w,someusesubwaystates[i].nousesubwaystate.lw,someusesubwaystates[i].nousesubwaystate.hw) {
			edges.PB(E(someusesubwaystates[i].nousesubwaystate.lv,w,someusesubwaystates[i].nousesubwaystate.hv,w));
		}
	}
	calculateclosest(edges,subways);
	int atedge=0;
	REPSZ(i,someusesubwaystates) {
		if(someusesubwaystates[i].nousesubwaystate.hw-someusesubwaystates[i].nousesubwaystate.lw>=2) FORE(v,someusesubwaystates[i].nousesubwaystate.lv,someusesubwaystates[i].nousesubwaystate.hv) {
			if(edges[atedge].dist<someusesubwaystates[i].closestsubway) {
//				printf("some[%d] -> edge %d -> %d\n",i,atedge,edges[atedge].dist);
				someusesubwaystates[i].closestsubway=edges[atedge].dist;
			}
			++atedge;
		}
		if(someusesubwaystates[i].nousesubwaystate.hv-someusesubwaystates[i].nousesubwaystate.lv>=2) FORE(w,someusesubwaystates[i].nousesubwaystate.lw,someusesubwaystates[i].nousesubwaystate.hw) {
			if(edges[atedge].dist<someusesubwaystates[i].closestsubway) {
//				printf("some[%d] -> edge %d -> %d\n",i,atedge,edges[atedge].dist);
				someusesubwaystates[i].closestsubway=edges[atedge].dist;
			}
			++atedge;
		}
	}

/*	FORE(i,4,4) {
		int found=INT_MAX;
		FORE(v,someusesubwaystates[i].nousesubwaystate.lv,someusesubwaystates[i].nousesubwaystate.hv) FORE(w,someusesubwaystates[i].nousesubwaystate.lw,someusesubwaystates[i].nousesubwaystate.hw) if((v+w)%2==0) {
			P p=convertFromVW(v,w); p.x/=2; p.y/=2;
			int cur=dist(&p,&subways[58]);
			if((v==someusesubwaystates[i].nousesubwaystate.lv||v==someusesubwaystates[i].nousesubwaystate.hv)&&(w==someusesubwaystates[i].nousesubwaystate.lw||w==someusesubwaystates[i].nousesubwaystate.hw)||cur<found) printf("(%d,%d)->(%d,%d) = %d\n",v,w,p.x,p.y,cur);
			if(cur<found) found=cur;
		} else {
//			if((v==someusesubwaystates[i].nousesubwaystate.lv||v==someusesubwaystates[i].nousesubwaystate.hv)&&(w==someusesubwaystates[i].nousesubwaystate.lw||w==someusesubwaystates[i].nousesubwaystate.hw)) printf("(%d,%d) [%d,%d]\n",v,w,someusesubwaystates[i].nousesubwaystate.lw,someusesubwaystates[i].nousesubwaystate.hw);
		}
		printf("[%d,%d][%d,%d]\n",someusesubwaystates[i].nousesubwaystate.lv,someusesubwaystates[i].nousesubwaystate.hv,someusesubwaystates[i].nousesubwaystate.lw,someusesubwaystates[i].nousesubwaystate.hw);
	} */

	// calculate answer
	int ret_someusesubway=INT_MAX;
	REPSZ(i,someusesubwaystates) {
		int t1=someusesubwaystates[i].nousesubwaystate.t;
		int t2=someusesubwaystates[i].usesubwayt;
		int t3=someusesubwaystates[i].closestsubway;
		if(t1<t2) { int dt=min(t3,t2-t1); assert(dt>=0); t1+=dt; t3-=dt; }
		if(t2<t1) { int dt=min(t3,t1-t2); assert(dt>=0); t2+=dt; t3-=dt; }
		int t=max(t1,t2)+(t3+1)/2;
//		if(i<20||t<ret_someusesubway) printf("%d: (%d,%d,%d,%d) -> %d\n",i,someusesubwaystates[i].nousesubwaystate.t,someusesubwaystates[i].usesubwayt,someusesubwaystates[i].closestsubway,someusesubwaystates[i].nousesubwaystate.t+someusesubwaystates[i].closestsubway,t);
		if(t<ret_someusesubway) ret_someusesubway=t;
	}
//	printf("%d / %d -> %lf\n",dist(&dwarves[0],&subways[58]),someusesubwaystates[4].usesubwayt,(dist(&dwarves[0],&subways[58])+someusesubwaystates[4].usesubwayt)/2.0);

	int ret=min(ret_noneusesubway,min(ret_someusesubway,ret_allusesubway));
//	printf("%d %d %d\n",ret_noneusesubway,ret_someusesubway,ret_allusesubway);
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}
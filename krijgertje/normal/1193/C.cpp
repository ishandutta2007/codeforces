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
int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }

const double eps=1e-9;

struct P { double x,y; P() {} P(double x,double y):x(x),y(y) {} };
P operator-(const P &a,const P &b) { return P(a.x-b.x,a.y-b.y); }
P operator+(const P &a,const P &b) { return P(a.x+b.x,a.y+b.y); }
P operator*(const double &a,const P &b) { return P(a*b.x,a*b.y); }
double len(const P &a) { return sqrt(a.x*a.x+a.y*a.y); }
double dist(const P &a,const P &b) { return len(b-a); }
double cross(const P &a,const P &b) { return a.x*b.y-a.y*b.x; }
double dot(const P &a,const P &b) { return a.x*b.x+a.y*b.y; }
bool operator==(const P &a,const P &b) { return fabs(a.x-b.x)<eps&&fabs(a.y-b.y)<eps; }
double signedlinepointdist(const P &a,const P &b,const P &c) { P d=b-a; return cross(c-a,d)/len(d); }
double projectlength(const P &a,const P &b,const P &c) { P d=b-a; return fabs(dot(c-a,d))/len(d); }
double side(const P &a,const P &b,const P &c) { return cross(b-a,c-a); }
bool inside(const P &a,const P &b,const P &c,const P &d) { return side(a,b,d)>=0&&side(b,c,d)>=0&&side(c,a,d)>=0; }
P mid(const P &a,const P &b) { return P((a.x+b.x)/2,(a.y+b.y)/2); }
P perp(const P &d) { P u=(1/len(d))*d; return P(-u.y,u.x); }
struct Pol {
	vector<P> p; int outputid;
	bool isrect() { if(SZ(p)!=4) return false; double w=p[2].x,h=p[2].y; return p[0]==P(0,0)&&p[1]==P(w,0)&&p[2]==P(w,h)&&p[3]==P(0,h); } // (0,0)-(w,0)-(w,h)-(h,0)
	bool istri() { return SZ(p)==3; }
	bool issquare() { if(SZ(p)!=4) return false; double sz=p[2].x; return p[0]==P(0,0)&&p[1]==P(sz,0)&&p[2]==P(sz,sz)&&p[3]==P(0,sz); }
	void add(double x,double y) { p.PB(P(x,y)); }
	void add(const P &a) { p.PB(a); }
	Pol translate(double dx,double dy) { Pol ret; REPSZ(i,p) ret.add(p[i].x+dx,p[i].y+dy); return ret; }
	void print() { REPSZ(i,p) printf("(%.5lg,%0.5lg)",p[i].x,p[i].y); }
};
bool operator==(const Pol &a,const Pol &b) { return a.p==b.p; }
struct Op { char kind; int full; vector<int> parts; };


Op cutintotwo(int full,int part1,int part2) { Op ret; ret.kind='S'; ret.full=full; ret.parts.PB(part1); ret.parts.PB(part2); return ret; }
Op mergetwo(int part1,int part2,int full) { Op ret; ret.kind='T'; ret.parts.PB(part1); ret.parts.PB(part2); ret.full=full; return ret; }
Op cutintothree(int full,int part1,int part2,int part3) { Op ret; ret.kind='S'; ret.full=full; ret.parts.PB(part1); ret.parts.PB(part2); ret.parts.PB(part3); return ret; }
Op mergethree(int part1,int part2,int part3,int full) { Op ret; ret.kind='T'; ret.parts.PB(part1); ret.parts.PB(part2); ret.parts.PB(part3); ret.full=full; return ret; }
Op mergefour(int part1,int part2,int part3,int part4,int full) { Op ret; ret.kind='T'; ret.parts.PB(part1); ret.parts.PB(part2); ret.parts.PB(part3); ret.parts.PB(part4); ret.full=full; return ret; }
Op mergefive(int part1,int part2,int part3,int part4,int part5,int full) { Op ret; ret.kind='T'; ret.parts.PB(part1); ret.parts.PB(part2); ret.parts.PB(part3); ret.parts.PB(part4); ret.parts.PB(part5); ret.full=full; return ret; }
Op move(int from,int to) { Op ret; ret.kind='M'; ret.parts.PB(from); ret.full=to; return ret;  }
struct Sequence {
	vector<Pol> pols;
	vector<Op> ops;
	
	void init() { pols.clear(); ops.clear(); }
	int add(Pol pol) { int ret=SZ(pols); pols.PB(pol); return ret; }

	int rect2square(int id) {
		//printf("id=%d\n",id);
		assert(pols[id].isrect());
		double w=pols[id].p[2].x,h=pols[id].p[2].y;
		if(fabs(w-h)<eps) return id;
		if(w>2*h) {
			Pol a; a.add(0,0); a.add(w/2,0); a.add(w/2,h); a.add(0,h); int aid=add(a);
			Pol b; b.add(w/2,0); b.add(w,0); b.add(w,h); b.add(w/2,h); int bid=add(b);
			Pol bb=b.translate(-w/2,h); int bbid=add(bb);
			Pol c; c.add(0,0); c.add(w/2,0); c.add(w/2,2*h); c.add(0,2*h); int cid=add(c);
			ops.PB(cutintotwo(id,aid,bid));
			ops.PB(move(bid,bbid));
			ops.PB(mergetwo(aid,bbid,cid));
			return rect2square(cid);
		} else if(h>2*w) {
			Pol a; a.add(0,0); a.add(w,0); a.add(w,h/2); a.add(0,h/2); int aid=add(a);
			Pol b; b.add(0,h/2); b.add(w,h/2); b.add(w,h); b.add(0,h); int bid=add(b);
			Pol bb=b.translate(w,-h/2); int bbid=add(bb);
			Pol c; c.add(0,0); c.add(2*w,0); c.add(2*w,h/2); c.add(0,h/2); int cid=add(c);
			ops.PB(cutintotwo(id,aid,bid));
			ops.PB(move(bid,bbid));
			ops.PB(mergetwo(aid,bbid,cid));
			return rect2square(cid);			
		} else if(w<h) {
			double side=sqrt(w*h),y=h*(side-w)/side,x=side*(h-side)/h;
			Pol a; a.add(0,0); a.add(w,0); a.add(w,y); a.add(x,side); a.add(0,side); int aid=add(a);
			Pol b; b.add(w,y); b.add(w,h); b.add(0,h); int bid=add(b);
			Pol bb=b.translate(side-w,-y); int bbid=add(bb);
			Pol c; c.add(0,side); c.add(x,side); c.add(0,h); int cid=add(c);
			Pol cc=c.translate(w,-side); int ccid=add(cc);
			Pol d; d.add(0,0); d.add(side,0); d.add(side,side); d.add(0,side); int did=add(d);
			ops.PB(cutintothree(id,aid,bid,cid));
			ops.PB(move(bid,bbid)); ops.PB(move(cid,ccid));
			ops.PB(mergethree(aid,bbid,ccid,did));
			return did;
		} else {
			double side=sqrt(w*h),y=side*(w-side)/w,x=w*(side-h)/side;
			Pol a; a.add(0,0); a.add(side,0); a.add(side,y); a.add(x,h); a.add(0,h); int aid=add(a);
			Pol b; b.add(x,h); b.add(w,0); b.add(w,h); int bid=add(b);
			Pol bb=b.translate(-x,y); int bbid=add(bb);
			Pol c; c.add(side,0); c.add(w,0); c.add(side,y); int cid=add(c);
			Pol cc=c.translate(-side,h); int ccid=add(cc);
			Pol d; d.add(0,0); d.add(side,0); d.add(side,side); d.add(0,side); int did=add(d);
			ops.PB(cutintothree(id,aid,bid,cid));
			ops.PB(move(bid,bbid)); ops.PB(move(cid,ccid));
			ops.PB(mergethree(aid,bbid,ccid,did));
			return did;
		}
	}
	int tri2rect(int id) {
		assert(pols[id].istri());
		P A=pols[id].p[0],B=pols[id].p[1],C=pols[id].p[2];
		FORE(i,1,2) { P AA=pols[id].p[i],BB=pols[id].p[(i+1)%3],CC=pols[id].p[(i+2)%3]; if(dist(AA,BB)>dist(A,B)) A=AA,B=BB,C=CC; }
		//printf("A=(%lg,%lg) B=(%lg,%lg) C=(%lg,%lg)\n",A.x,A.y,B.x,B.y,C.x,C.y);
		double w=dist(A,B),h=signedlinepointdist(A,B,C),x=projectlength(A,B,C);
		//printf("w=%lg h=%lg x=%lg\n",w,fabs(h),x);
		Pol a; a.add(A); a.add(B); a.add(mid(B,C)); a.add(mid(A,C)); int aid=add(a);
		Pol b; b.add(mid(B,C)); b.add(C); b.add(C+(h/2)*perp(B-A)); int bid=add(b);
		Pol c; c.add(mid(A,C)); c.add(C+(h/2)*perp(B-A)); c.add(C); int cid=add(c);
		ops.PB(cutintothree(id,aid,bid,cid));
		Pol aa; aa.add(0,0); aa.add(w,0); aa.add((w+x)/2,fabs(h)/2); aa.add(x/2,fabs(h)/2); int aaid=add(aa);
		Pol bb; bb.add((w+x)/2,fabs(h)/2); bb.add(w,0); bb.add(w,fabs(h/2)); int bbid=add(bb);
		Pol cc; cc.add(x/2,fabs(h)/2); cc.add(0,fabs(h)/2); cc.add(0,0); int ccid=add(cc);
		Pol d; d.add(0,0); d.add(w,0); d.add(w,fabs(h)/2); d.add(0,fabs(h)/2); int did=add(d);
		ops.PB(move(aid,aaid)); ops.PB(move(bid,bbid)); ops.PB(move(cid,ccid));
		ops.PB(mergethree(aaid,bbid,ccid,did));
		return did;
	}
	int joinsquares(int id1,int id2) {
		assert(pols[id1].issquare()&&pols[id2].issquare());
		double sz1=pols[id1].p[2].x,sz2=pols[id2].p[2].x,sz=sqrt(sz1*sz1+sz2*sz2);
		if(sz1<sz2) { swap(id1,id2); swap(sz1,sz2); }
		if(fabs(sz1-sz2)<eps) {
			Pol a; a.add(0,0); a.add(sz1,0); a.add(0,sz1); int aid=add(a);
			Pol aa; aa.add(sz/2,sz/2); aa.add(sz,sz); aa.add(0,sz); int aaid=add(aa);
			Pol b; b.add(sz1,0); b.add(sz1,sz1); b.add(0,sz1); int bid=add(b);
			Pol bb; bb.add(sz,0); bb.add(sz/2,sz/2); bb.add(0,0); int bbid=add(bb);
			Pol c; c.add(0,0); c.add(sz2,sz2); c.add(0,sz2); int cid=add(c);
			Pol cc; cc.add(sz,0); cc.add(sz,sz); cc.add(sz/2,sz/2); int ccid=add(cc);
			Pol d; d.add(0,0); d.add(sz2,0); d.add(sz2,sz2); int did=add(d);
			Pol dd; dd.add(0,0); dd.add(sz/2,sz/2); dd.add(0,sz); int ddid=add(dd);
			Pol e; e.add(0,0); e.add(sz,0); e.add(sz,sz); e.add(0,sz); int eid=add(e);
			ops.PB(cutintotwo(id1,aid,bid)); ops.PB(cutintotwo(id2,cid,did));
			ops.PB(move(aid,aaid)); ops.PB(move(bid,bbid)); ops.PB(move(cid,ccid)); ops.PB(move(did,ddid));
			ops.PB(mergefour(aaid,bbid,ccid,ddid,eid));
			return eid;
		} else {
			//printf("joinsquares\n"); 
			//printf("sz1=%lf sz2=%lf\n",sz1,sz2);
			double y=sz2*(sz1-sz2)/sz1;
			Pol a; a.add(sz2,0); a.add(sz1,y); a.add(sz1,sz1); a.add(0,sz1); int aid=add(a);
			Pol b; b.add(0,0); b.add(sz2,0); b.add(0,sz1); int bid=add(b);
			Pol bb=b.translate(+sz1,+sz2); int bbid=add(bb);
			Pol c; c.add(sz2,0); c.add(sz1,0); c.add(sz1,y); int cid=add(c);
			Pol cc=c.translate(-sz2,+sz1); int ccid=add(cc);
			Pol d; d.add(0,y); d.add(sz2,sz2); d.add(0,sz2); int did=add(d);
			Pol dd=d.translate(+sz1,0); int ddid=add(dd);
			Pol e; e.add(0,0); e.add(sz2,0); e.add(sz2,sz2); e.add(0,y); int eid=add(e);
			Pol ee=e.translate(sz1-sz2,+sz1); int eeid=add(ee);
			Pol f; f.add(sz2,0); f.add(sz1+sz2,sz2); f.add(sz1,sz1+sz2); f.add(0,sz1); int fid=add(f);
			Pol g; g.add(0,0); g.add(sz,0); g.add(sz,sz); g.add(0,sz); int gid=add(g);
			ops.PB(cutintothree(id1,aid,bid,cid));
			ops.PB(cutintotwo(id2,did,eid));
			ops.PB(move(bid,bbid)); ops.PB(move(cid,ccid)); ops.PB(move(did,ddid)); ops.PB(move(eid,eeid));
			ops.PB(mergefive(aid,bbid,ccid,ddid,eeid,fid));
			ops.PB(move(fid,gid));
			return gid;
		}
	}
	vector<int> triangulate(int id) {
		//vector<int> ret; FORSZ(i,2,pols[id].p) { Pol a; a.add(pols[id].p[0]); a.add(pols[id].p[i-1]); a.add(pols[id].p[i]); int aid=add(a); ret.PB(aid); }
		vector<int> ret;
		vector<P> rem=pols[id].p;
		while(SZ(rem)>3) {
			bool found=false;
			REPSZ(i,rem) {
				P A=rem[(i+SZ(rem)-1)%SZ(rem)],B=rem[i],C=rem[(i+1)%SZ(rem)];
				if(side(A,B,C)<=0) continue;
				bool ok=true; REP(j,SZ(rem)-3) if(inside(A,B,C,rem[(i+2+j)%SZ(rem)])) { ok=false; break; } if(!ok) continue;
				rem.erase(rem.begin()+i);
				Pol a; a.add(A); a.add(B); a.add(C); ret.PB(add(a));
				found=true; break;
			}
			assert(found);
		}
		Pol last; last.p=rem; ret.PB(add(last));
		//printf("here %d vertexes -> %d triangles\n",SZ(pols[id].p),SZ(ret));
		Op op; op.kind='S'; op.full=id; op.parts=ret; ops.PB(op); return ret;
	}
	int tosquare(int id) {
		if(pols[id].isrect()) return rect2square(id); 
		if(pols[id].istri()) return rect2square(tri2rect(id));
		vector<int> tri=triangulate(id); int ret=rect2square(tri2rect(tri[0])); FORSZ(i,1,tri) ret=joinsquares(ret,rect2square(tri2rect(tri[i]))); return ret;
	}
	void print() {
		REPSZ(i,ops) {
			if(ops[i].kind=='S') { printf("cut "); pols[ops[i].full].print(); printf(" into"); REPSZ(j,ops[i].parts) { printf(" "); if(j!=0&&j==SZ(ops[i].parts)-1) printf("and "); pols[ops[i].parts[j]].print(); } puts(""); }
			if(ops[i].kind=='M') { printf("move"); REPSZ(j,ops[i].parts) { printf(" "); if(j!=0&&j==SZ(ops[i].parts)-1) printf("and "); pols[ops[i].parts[j]].print(); } printf(" to "); pols[ops[i].full].print(); puts(""); }
			if(ops[i].kind=='T') { printf("merge"); REPSZ(j,ops[i].parts) { printf(" "); if(j!=0&&j==SZ(ops[i].parts)-1) printf("and "); pols[ops[i].parts[j]].print(); } printf(" into "); pols[ops[i].full].print(); puts(""); }
		}
	}
};


Pol a,b;

Sequence seqa,seqb;
Sequence ans;
vector<int> src;


void solve() {
	seqa.init(); int aid=seqa.add(a); int said=seqa.tosquare(aid);
	seqb.init(); int bid=seqb.add(b); int sbid=seqb.tosquare(bid);
	assert(seqa.pols[said]==seqb.pols[sbid]);
	
	ans.init();
	REPSZ(i,seqa.pols) ans.pols.PB(seqa.pols[i]);
	REP(i,SZ(seqb.pols)-1) ans.pols.PB(seqb.pols[i]);
	REPSZ(i,seqa.ops) ans.ops.PB(seqa.ops[i]);
	for(int i=SZ(seqb.ops)-1;i>=0;--i) {
		Op op=seqb.ops[i];
		if(op.full!=sbid) op.full+=SZ(seqa.pols); else op.full=said;
		REPSZ(j,op.parts) if(op.parts[j]!=sbid) op.parts[j]+=SZ(seqa.pols); else op.parts[j]=sbid;
		if(op.kind=='M') swap(op.full,op.parts[0]);
		if(op.kind=='S') op.kind='T'; else if(op.kind=='T') op.kind='S';
		ans.ops.PB(op);
	}
	int noutputid=0;
	src=vector<int>(SZ(ans.pols),-1);
	ans.pols[0].outputid=noutputid++; src[0]=0;
	vector<Op> ops=ans.ops; ans.ops.clear();
	REPSZ(i,ops) {
		Op op=ops[i];
		if(op.kind=='M') { assert(src[op.parts[0]]!=-1); src[op.full]=src[op.parts[0]]; }
		if(op.kind=='S') { 
			assert(src[op.full]!=-1); 
			if(src[op.full]!=op.full) { ans.ops.PB(move(src[op.full],op.full)); ans.pols[op.full].outputid=noutputid++; src[op.full]=op.full; }
			REPSZ(j,op.parts) { ans.pols[op.parts[j]].outputid=noutputid++; src[op.parts[j]]=op.parts[j]; }
			ans.ops.PB(op);
		}
		if(op.kind=='T') {
			REPSZ(j,op.parts) assert(src[op.parts[j]]!=-1); 
			ans.pols[op.full].outputid=noutputid++; src[op.full]=op.full;
			ans.ops.PB(op);
		}
	}
	//ans.print();
}

void output(const Pol &pol) { printf("%d",SZ(pol.p)); REPSZ(i,pol.p) printf(" %.15lf %.15lf",pol.p[i].x,pol.p[i].y); puts(""); }
void run() {
	a.p.clear(); int na; scanf("%d",&na); REP(i,na) { double x,y; scanf("%lf%lf",&x,&y); a.add(x,y); }
	b.p.clear(); int nb; scanf("%d",&nb); REP(i,nb) { double x,y; scanf("%lf%lf",&x,&y); b.add(x,y); }
	solve();
	REPSZ(i,ans.ops) {
		Op op=ans.ops[i];
		if(op.kind=='M') { printf("tape\n"); printf("1 %d\n",ans.pols[src[op.parts[0]]].outputid); output(ans.pols[op.full]); output(ans.pols[op.full]); }
		if(op.kind=='S') { printf("scissors\n"); printf("%d %d\n",ans.pols[op.full].outputid,SZ(op.parts)); REPSZ(j,op.parts) output(ans.pols[op.parts[j]]); }
		if(op.kind=='T') { printf("tape\n"); printf("%d",SZ(op.parts)); REPSZ(j,op.parts) printf(" %d",ans.pols[src[op.parts[j]]].outputid); puts(""); REPSZ(j,op.parts) output(ans.pols[op.parts[j]]); output(ans.pols[op.full]); }
	}
}

void research() {
	Pol pol; REP(i,4) { double x,y; scanf("%lf%lf",&x,&y); pol.add(x,y); }
	Sequence seq; seq.pols.PB(pol); int res=seq.rect2square(0); seq.print();
}

int main() {
	run();
	//research();
	return 0;
}
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
#include <unordered_map>
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
typedef long double ld;
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MOD=1000000007;
const int MAXN=100000;
const int MAXM=100000;
const int MAXD=18;
const int MAXBIT=1<<(MAXD-1);
const int MAXNODE=2*MAXD+2*MAXM*MAXD;


struct myhash { unsigned int operator()(const pair<unsigned int,unsigned int> &c) const { return hash<unsigned int>()(c.first)^(hash<unsigned int>()(c.second)<<1); } };
unordered_map<pair<unsigned int,unsigned int>, int, myhash> id;
int getid(unsigned int a,unsigned int b) {
	pair<unsigned int,unsigned int> c=MP(a,b);
	if(id.find(c)==id.end()) { int ret=SZ(id); return id[c]=ret; } else return id[c];
}

typedef struct S { int lft,rgt; unsigned int id; } S;
S node[MAXNODE]; int nnode;
int createleaf(unsigned int id) { assert(nnode<MAXNODE); node[nnode].lft=node[nnode].rgt=-1,node[nnode].id=id; return nnode++; }
int createnode(int lft,int rgt) { assert(nnode<MAXNODE); node[nnode].lft=lft,node[nnode].rgt=rgt,node[nnode].id=getid(node[lft].id,node[rgt].id); return nnode++; }


bool slower(int a,int b,int n=MAXBIT) {
	if(node[a].id==node[b].id) return false;
	if(n==32) return node[a].id<node[b].id;
	if(node[node[a].rgt].id!=node[node[b].rgt].id) return slower(node[a].rgt,node[b].rgt,n>>1);
	return slower(node[a].lft,node[b].lft,n>>1);
}
int zero[MAXBIT+1];
int one[MAXBIT+1];
pair<int,bool> sadd(int a,int pw,int n=MAXBIT) {
	if(pw==0&&node[a].id==node[one[n]].id) {
		return MP(zero[n],true);
	} else if(n==32) {
		unsigned int nid=node[a].id+(((unsigned int)1)<<pw);
		return MP(createleaf(nid),node[a].id>nid);
	} else if(pw<(n>>1)) {
		pair<int,bool> reslft=sadd(node[a].lft,pw,n>>1);
		if(!reslft.second) return MP(createnode(reslft.first,node[a].rgt),false);
		pair<int,bool> resrgt=sadd(node[a].rgt,0,n>>1);
		return MP(createnode(reslft.first,resrgt.first),resrgt.second);
	} else {
		pair<int,bool> resrgt=sadd(node[a].rgt,pw-(n>>1),n>>1);
		return MP(createnode(node[a].lft,resrgt.first),resrgt.second);
	}
}
int p2[MAXBIT+1];
int slen(int a,int n=MAXBIT) {
	if(n==32) return node[a].id%MOD;
	return (slen(node[a].lft,n>>1)+(ll)p2[n>>1]*slen(node[a].rgt,n>>1))%MOD;
}
int szero(int n=MAXBIT) {
	return zero[n];
}



int nh;
int h[MAXN];
int hpos[MAXN];
int val[MAXN];
bool done[MAXN];
int prv[MAXN];

void hswap(int a,int b) {
	swap(h[a],h[b]);
	swap(hpos[h[b]],hpos[h[a]]);
}
void hup(int pos) {
	while(pos!=0) {
		int npos=(pos-1)/2;
		if(!slower(val[h[pos]],val[h[npos]])) break;
		hswap(pos,npos);
		pos=npos;
	}
}
void hdown(int pos) {
	while(true) {
		int npos=pos;
		if(2*pos+1<nh&&slower(val[h[2*pos+1]],val[h[npos]])) npos=2*pos+1;
		if(2*pos+2<nh&&slower(val[h[2*pos+2]],val[h[npos]])) npos=2*pos+2;
		if(pos==npos) break;
		hswap(pos,npos);
		pos=npos;
	}
}
void hadd(int id) {
	assert(hpos[id]==-1);
	hpos[id]=nh; h[nh]=id; ++nh;
	hup(nh-1);
}
void hrem(int id) {
	int pos=hpos[id]; assert(pos!=-1);
	hswap(pos,nh-1);
	hpos[id]=-1; --nh;
	if(pos<nh) { hup(pos); hdown(pos); }
}




int n,m,s,t;
int fst[MAXN];
int nxt[2*MAXM],to[2*MAXM],len[MAXM];
int ret[MAXN],nret;

void run() {
	p2[0]=1; FORE(i,1,MAXBIT) p2[i]=2*p2[i-1]%MOD;
	zero[32]=createleaf(0); for(int i=64;i<=MAXBIT;i*=2) zero[i]=createnode(zero[i>>1],zero[i>>1]);
	//for(unordered_map<pair<unsigned int,unsigned int>, int, myhash>::iterator it=id.begin();it!=id.end();++it) printf("(%u,%u)->%d\n",it->first.first,it->first.second,it->second);
	one[32]=createleaf((1LL<<32)-1); for(int i=64;i<=MAXBIT;i*=2) one[i]=createnode(one[i>>1],one[i>>1]);

	scanf("%d%d",&n,&m);
	REP(i,n) fst[i]=-1;
	REP(i,m) {
		int a,b; scanf("%d%d%d",&a,&b,&len[i]); --a,--b;
		nxt[2*i+0]=fst[a]; fst[a]=2*i+0; to[2*i+0]=b;
		nxt[2*i+1]=fst[b]; fst[b]=2*i+1; to[2*i+1]=a;
	}
	scanf("%d%d",&s,&t); --s,--t;

	nh=0; REP(i,n) hpos[i]=-1,done[i]=false,prv[i]=-2;
	val[s]=szero(); prv[s]=-1; hadd(s);
	while(nh>0) {
		//REP(i,nh) printf("h%d: %d %d %d\n",i,h[i],slen(val[h[i]]),hpos[h[i]]);
		int at=h[0]; hrem(at); done[at]=true;
		//printf("at %d = %d\n",at,slen(val[at]));
		for(int x=fst[at];x!=-1;x=nxt[x]) if(!done[to[x]]) {
			int nval=sadd(val[at],len[x/2]).first;
			//printf("\t-> %d = %d\n",to[x],slen(nval));
			if(hpos[to[x]]==-1||slower(nval,val[to[x]])) { val[to[x]]=nval; prv[to[x]]=at; if(hpos[to[x]]==-1) hadd(to[x]); else hup(hpos[to[x]]); }
		}
	}

	if(!done[t]) { printf("-1\n"); return; }
	printf("%d\n",slen(val[t]));
	nret=0; for(int x=t;x!=-1;x=prv[x]) ret[nret++]=x;
	printf("%d\n",nret);
	for(int i=nret-1;i>=0;--i) { printf("%d",ret[i]+1); if(i!=0) printf(" "); } puts("");

	
}

int main() {
	run();
	return 0;
}
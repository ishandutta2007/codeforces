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

const int MAXN=100000;
struct Rect { int lx,ly,hx,hy,id; };
bool operator<(const Rect &a,const Rect &b) { return a.lx<b.lx; }

struct LinkInfo { int prv[MAXN],nxt[MAXN]; };
struct LinkedList { int head,tail,sz; LinkedList() { head=-1,tail=-1,sz=0; } };
struct State { LinkedList lst[4]; };

LinkInfo link[4];
LinkInfo curlink[4];
int lval[MAXN][4];
int rval[MAXN][4];
int col[MAXN];

State clone(State orig) {
	REP(i,4) for(int x=orig.lst[i].head;x!=-1;x=link[i].nxt[x]) curlink[i].prv[x]=link[i].prv[x],curlink[i].nxt[x]=link[i].nxt[x];
	return orig;
}
void remove(LinkInfo &info,LinkedList &lst,int x) {
	--lst.sz;
	if(info.prv[x]==-1) { assert(lst.head==x); lst.head=info.nxt[x]; } else info.nxt[info.prv[x]]=info.nxt[x];
	if(info.nxt[x]==-1) { assert(lst.tail==x); lst.tail=info.prv[x]; } else info.prv[info.nxt[x]]=info.prv[x];
}
void append(LinkInfo &info,LinkedList &lst,int x) {
	//static int tmp=0; if(++tmp>100) exit(0);
	//printf("append %d\n",x+1);
	++lst.sz;
	info.prv[x]=lst.tail; info.nxt[x]=-1; lst.tail=x;
	if(info.prv[x]==-1) { assert(lst.head==-1); lst.head=x; } else info.nxt[info.prv[x]]=x;
}
void setcol(State &cur,int x,int c) {
	assert(col[x]==-1); col[x]=c;
	REP(i,4) remove(curlink[i],cur.lst[i],x);
}
void move(State &a,State &b,int i,int x) {
	remove(link[i],a.lst[i],x);
	append(link[i],b.lst[i],x);
}


bool solve(State orig) {
	//printf("solve:\n");
	//REP(i,4) { printf("by%d:",i); for(int x=orig.lst[i].head;x!=-1;x=link[i].nxt[x]) printf(" %d",x+1); puts(""); }
	State cur=clone(orig);
	for(int x=cur.lst[0].head;x!=-1;x=curlink[0].nxt[x]) col[x]=-1;
	int ncol=0;
	while(true) {
		int sz=cur.lst[0].sz;
		if(sz==1) break;
		//printf("sz=%d\n",sz);
		//REP(i,4) { printf("by%d:",i); for(int x=cur.lst[i].head;x!=-1;x=curlink[i].nxt[x]) printf(" %d",x+1); puts(""); }
		int at[4],mx[4];
		REP(i,4) at[i]=cur.lst[i].head,mx[i]=INT_MIN;
		bool found=false;
		REP(pos,sz-1) {
			REP(i,4) {
				//printf("pos=%d i=%d\n",pos,i);
				mx[i]=max(mx[i],rval[at[i]][i]);
				at[i]=curlink[i].nxt[at[i]];
				if(mx[i]<=lval[at[i]][i]) {
					//printf("found!\n");
					int x=cur.lst[i].head; while(x!=at[i]) { int y=curlink[i].nxt[x]; setcol(cur,x,ncol); x=y; }
					++ncol;
					found=true;
					break;
				}
			}
			if(found) break;
		}
		if(!found) return false;
	}
	//printf("here\n");
	vector<State> nstate(ncol);
	REP(i,4) { int x=orig.lst[i].head; while(x!=-1) { int y=link[i].nxt[x]; if(col[x]!=-1) move(orig,nstate[col[x]],i,x); x=y; } }
	REPSZ(i,nstate) if(!solve(nstate[i])) return false;
	return true;
}

int n;
Rect rect[MAXN];

bool solve() {
	State all;
	REP(a,2) {
		REP(b,2) {
			sort(rect,rect+n);
			REP(i,n) lval[rect[i].id][2*a+b]=rect[i].lx,rval[rect[i].id][2*a+b]=rect[i].hx,append(link[2*a+b],all.lst[2*a+b],rect[i].id);
			REP(i,n) swap(rect[i].lx,rect[i].hx),rect[i].lx=-rect[i].lx,rect[i].hx=-rect[i].hx;
		}
		REP(i,n) swap(rect[i].lx,rect[i].ly),swap(rect[i].hx,rect[i].hy);
	}
	return solve(all);
}


void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d%d%d%d",&rect[i].lx,&rect[i].ly,&rect[i].hx,&rect[i].hy),rect[i].id=i;
	printf("%s\n",solve()?"YES":"NO");
}

int main() {
	run();
	return 0;
}
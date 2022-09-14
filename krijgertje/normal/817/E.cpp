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

const int MAXQ=100000;
const int MAXBIT=27;
const int MAXZ=1+MAXQ*(MAXBIT+1);

typedef struct Z { int l,r,cnt; } Z;

int nq;
Z z[MAXZ]; int nz;

int createnode() { z[nz].l=z[nz].r=-1,z[nz].cnt=0; return nz++; }
void upd(int at,int id,int bit,int by) {
	z[at].cnt+=by;
	if(bit==-1) return;
	if((id&(1<<bit))==0) {
		if(z[at].l==-1) z[at].l=createnode();
		upd(z[at].l,id,bit-1,by);
	} else {
		if(z[at].r==-1) z[at].r=createnode();
		upd(z[at].r,id,bit-1,by);
	}
}
int query(int at,int id,int bit,int lim) {
	if(bit==-1) return 0;
	int ret=0;
	if((id&(1<<bit))==0) {
		if((lim&(1<<bit))==0) {
			if(z[at].l!=-1) ret+=query(z[at].l,id,bit-1,lim);
		} else {
			if(z[at].l!=-1) ret+=z[z[at].l].cnt;
			if(z[at].r!=-1) ret+=query(z[at].r,id,bit-1,lim);
		}
	} else {
		if((lim&(1<<bit))==0) {
			if(z[at].r!=-1) ret+=query(z[at].r,id,bit-1,lim);
		} else {
			if(z[at].l!=-1) ret+=query(z[at].l,id,bit-1,lim);
			if(z[at].r!=-1) ret+=z[z[at].r].cnt;
		}
	}
	return ret;
}
void printtree(int at,int bit,int last=-1) {
	REP(i,MAXBIT-bit) printf(" "); printf("%c: %d (%d)\n",last==-1?'-':'0'+last,z[at].cnt,at);
	if(z[at].l!=-1) printtree(z[at].l,bit-1,0);
	if(z[at].r!=-1) printtree(z[at].r,bit-1,1);
}


void run() {
	nz=0; int root=createnode();
	scanf("%d",&nq);
	REP(i,nq) {
		int tp; scanf("%d",&tp);
		if(tp==1) { int id; scanf("%d",&id); upd(root,id,MAXBIT,+1); }
		if(tp==2) { int id; scanf("%d",&id); upd(root,id,MAXBIT,-1); }
		if(tp==3) { int id,lim; scanf("%d%d",&id,&lim); int ret=query(root,id,MAXBIT,lim); printf("%d\n",ret); }
		//printtree(root,MAXBIT);
	}
}

int main() {
	run();
	return 0;
}
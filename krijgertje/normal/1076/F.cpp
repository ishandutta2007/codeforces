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

const int MAXN=300000;

int n,lim;
int a[MAXN],b[MAXN];

int calcsame(int x,int y) {
	if(x==1) return -1;
	int remx=x-2,remy=y-1;
	int cur=min(remx,remy); remx-=cur,remy-=cur;
	if(remx>0) {
		ll nfree=(ll)(x-remx-2)*(lim-1);
		if(remx<=nfree) return 2; else remx-=nfree;
		if(remx<=2*(lim-1)) return 2+remx;
		return -1;
	} else {
		ll nfree=(ll)(y-remy)*(lim-1);
		if(remy<=nfree) return 2;
		return -1;
	}
}
pair<int,int> calcdiff(int x,int y) {
	int remx=x-1,remy=y-1;
	int cur=min(remx,remy); remx-=cur,remy-=cur;
	if(remx>0) {
		ll nfree=(ll)(x-remx-1)*(lim-1);
		if(remx<=nfree) return MP(1,1); else remx-=nfree;
		if(remx<=lim-1) return MP(1+remx,1);
		return MP(-1,-1);
	} else {
		ll nfree=(ll)(y-remy-1)*(lim-1);
		if(remy<=nfree) return MP(1,1); else remy-=nfree;
		if(remy<=lim-1) return MP(1,1+remy);
		return MP(-1,-1);
	}
}

int amn[MAXN+1],bmn[MAXN+1];

void upd(int &res,int val) { if(val<=lim) res=min(res,val); }
bool solve() {
	amn[0]=bmn[0]=0;
	REP(i,n) {
		int resa=calcsame(a[i],b[i]),resb=calcsame(b[i],a[i]);
		pair<int,int> resab=calcdiff(a[i],b[i]),resba=calcdiff(b[i],a[i]);
		//printf("(%d,%d) -> resa=%d resb=%d resab=(%d,%d) resba=(%d,%d)\n",a[i],b[i],resa,resb,resab.first,resab.second,resba.first,resba.second);
		amn[i+1]=bmn[i+1]=INT_MAX;
		if(amn[i]<lim) {
			if(resa!=-1) {
				upd(amn[i+1],max(1,amn[i]+resa-lim));
			}
			if(resab.first!=-1&&resab.second!=-1) {
				if(amn[i]+resab.first<=lim) upd(bmn[i+1],resab.second);
			}
		}
		if(amn[i]<=lim) {
			if(resb!=-1) {
				upd(bmn[i+1],max(1,resb-lim));
			}
			if(resba.first!=-1&&resba.second!=-1) {
				upd(amn[i+1],resba.second);
			}
		}
		if(bmn[i]<lim) {
			if(resb!=-1) {
				upd(bmn[i+1],max(1,bmn[i]+resb-lim));
			}
			if(resba.first!=-1&&resba.second!=-1) {
				if(bmn[i]+resba.first<=lim) upd(amn[i+1],resba.second);
			}
		}
		if(bmn[i]<=lim) {
			if(resa!=-1) {
				upd(amn[i+1],max(1,resa-lim));
			}
			if(resab.first!=-1&&resab.second!=-1) {
				upd(bmn[i+1],resab.second);
			}
		}
		//printf("-> %d %d\n",amn[i+1],bmn[i+1]);
	}
	return amn[n]<=lim||bmn[n]<=lim;
}

void run() {
	scanf("%d%d",&n,&lim); REP(i,n) scanf("%d",&a[i]); REP(i,n) scanf("%d",&b[i]);
	printf("%s\n",solve()?"YES":"NO");
}

int main() {
	run();
	return 0;
}
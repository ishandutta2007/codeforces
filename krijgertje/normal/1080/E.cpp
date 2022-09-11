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

const int MAXH=250;
const int MAXW=250;
const int HMOD=999999937;
const int HMLT=171923;

struct Manacher {
	vector<int> a; int n;
	void init(int *lst,int nlst) { n=2*nlst+3; a=vector<int>(n,-1); a[0]=-2,a[n-1]=-3; REP(i,nlst) a[2+2*i]=lst[i]; }
	int calc() {
		//printf("a:"); REP(i,n) printf(" %d",a[i]); puts("");
		vector<int> len(n,0);
		int center=0,right=0;
		FOR(i,1,n-1) {
			int mirror=2*center-i;
			if(right>i) len[i]=min(right-i,len[mirror]);
			while(a[i+(1+len[i])]==a[i-(1+len[i])]) ++len[i];
			if(i+len[i]>right) center=i,right=i+len[i];
		}
		//printf("len:"); REP(i,n) printf(" %d",len[i]); puts("");
		int ret=0;
		FOR(i,1,n-1) {
			int cur=len[i],now=0;
			if(i%2==0) { if(cur%2==1) --cur; cur=2*cur+1; cur=(cur+1)/2; now+=(cur+1)/2; } else { if(cur%2==0) --cur; if(cur<0) continue; cur=2*cur+1; cur=(cur+1)/2; now+=cur/2; }
			//printf("%d: now=%d\n",i,now);
			ret+=now;
		}
		//printf("ret=%d\n",ret);
		return ret;
	}
};
Manacher man;

int h,w;
char g[MAXH][MAXW+1];

int hmlt[26];
int ccnt[26],chash,codd;

void upd(int x) {
	chash=(chash+HMOD-(ll)hmlt[x]*ccnt[x]%HMOD)%HMOD;
	if(ccnt[x]%2==1) --codd;
	++ccnt[x];
	if(ccnt[x]%2==1) ++codd;
	chash=(chash+HMOD+(ll)hmlt[x]*ccnt[x]%HMOD)%HMOD;
}

int tmp[MAXW+1][MAXH];
int cur[MAXH],ncur;

int calc() {
	//printf("cur:"); REP(i,ncur) printf(" %d",cur[i]); puts("");
	man.init(cur,ncur);
	return man.calc();
}

ll solve() {
	hmlt[0]=1; FOR(i,1,26) hmlt[i]=(ll)hmlt[i-1]*HMLT%HMOD;

	ll ret=0;
	REP(col,w) {
		REP(row,h) {
			codd=chash=0; REP(i,26) ccnt[i]=0;
			FORE(len,1,w-col) {
				upd(g[row][col+len-1]-'a');
				//printf("(%d,%d): %d -> odd=%d hash=%d\n",row,col,len,codd,chash);
				tmp[len][row]=codd<=1?chash:-1;
			}
		}
		FORE(len,1,w-col) {
			//printf("(%d,%d):",col,len); REP(i,h) printf(" %d",tmp[len][i]); puts("");
			for(int l=0,r=l;l<h;l=r) {
				while(r<h&&(tmp[len][l]==-1)==(tmp[len][r]==-1)) ++r;
				if(tmp[len][l]==-1) continue;
				ncur=0; FOR(i,l,r) cur[ncur++]=tmp[len][i];
				ret+=calc();
			}

		}
	}
	return ret;
}

void run() {
	scanf("%d%d",&h,&w);
	REP(x,h) scanf("%s",g[x]);
	printf("%lld\n",solve());
}

int main() {
	run();
	return 0;
}
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

const int MAXCOLOR=500;
const int MAXLEN=1000000;
const int MAXLG=19;
const int MOD=998244353;

int ncolor,len;
int a[MAXLEN];


int mn[MAXLEN][MAXLG+1];
int nxt[MAXLEN];
pair<int,int> o[MAXLEN];
int fst[MAXCOLOR+1];

int getmn(int l,int r) {
	int len=r-l+1,ret=INT_MAX,at=l; for(int k=MAXLG;k>=0;--k) if(len&(1<<k)) ret=min(ret,mn[at][k]),at+=1<<k; return ret;
}

vector<int> calc(int l,int r,int lim) {
	int v=getmn(l,r);
	//printf("[%d..%d] v=%d\n",l,r,v);
	vector<int> pos; for(int x=fst[v];x!=-1;x=nxt[x]) { if(x<l||x>r) throw 1; pos.PB(x); } assert(SZ(pos)>=1);
	vector<int> lres; if(pos[0]!=l) lres=calc(l,pos[0]-1,lim+1); else lres=vector<int>(lim+2,1); assert(SZ(lres)==lim+2);
	vector<int> rres; if(pos.back()!=r) rres=calc(pos.back()+1,r,lim+1); else rres=vector<int>(lim+2,1); assert(SZ(rres)==lim+2);
	int mlt=1;
	FORSZ(i,1,pos) if(pos[i-1]+1!=pos[i]) { vector<int> mres=calc(pos[i-1]+1,pos[i]-1,0); assert(SZ(mres)==1); mlt=(ll)mlt*mres[0]%MOD; }
	vector<int> res(lim+1,0);
	FORE(i,1,lim+1) FORE(j,1,lim-i+2) { assert(j<=lim+1&&i+j-2<=lim); res[i+j-2]=(res[i+j-2]+(ll)lres[i]*rres[j])%MOD; }
	REPSZ(i,res) res[i]=(ll)res[i]*mlt%MOD;
	return res;
}


int solve() {
	REP(i,len) mn[i][0]=a[i];
	REP(k,MAXLG) REP(i,len) { mn[i][k+1]=mn[i][k]; if(i+(1<<k)<len) mn[i][k+1]=min(mn[i][k+1],mn[i+(1<<k)][k]); }
	REP(i,len) o[i]=MP(a[i],i); sort(o,o+len); REP(i,len) nxt[o[i].second]=i+1<len&&o[i+1].first==o[i].first?o[i+1].second:-1;
	FORE(i,1,ncolor) fst[i]=-1; REP(i,len) if(fst[a[i]]==-1) fst[a[i]]=i;

	try {
		vector<int> res=calc(0,len-1,0);
		return res[0];
	} catch(int e) { return 0; }
	return -1;
}

void run() {
	scanf("%d%d",&ncolor,&len);
	REP(i,len) scanf("%d",&a[i]);
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}
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
int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }

const int MOD=1000000007;
int n,k;
int x[50],y[50],w[50];
int xx[50],yy[50],nx,ny;

vector<int> combine(const vector<int> &a,const vector<int> &b) {
	if(SZ(a)==0||SZ(b)==0) return vector<int>();
	vector<int> c(SZ(a)+SZ(b)-1,0);
	REPSZ(i,a) REPSZ(j,b) c[i+j]=(c[i+j]+(ll)a[i]*b[j])%MOD;
	return c;
}
vector<int> add(const vector<int> &a,const vector<int> &b) {
	vector<int> c(max(SZ(a),SZ(b)),0);
	REPSZ(i,a) c[i]=(c[i]+a[i])%MOD;
	REPSZ(i,b) c[i]=(c[i]+b[i])%MOD;
	return c;
}
vector<int> add(const pair<vector<int>,vector<int> > &pr) {
	return add(pr.first,pr.second);
}
vector<int> inc(const vector<int> &a,int val) {
	vector<int> c(SZ(a)+1,0);
	REPSZ(i,a) c[i+1]=(ll)a[i]*val%MOD;
	return c;
}

int q[50],qhead,qtail;
int root,fst[100],nxt[100],val[100];

void printtree(int at,int d) {
	REP(i,d) printf("  "); printf("%d\n",at);
	for(int x=fst[at];x!=-1;x=nxt[x]) printtree(x,d+1);
}

pair<vector<int>,vector<int> > dfstree(int at,ll xmask,ll ymask) {
	vector<int> rootfree(1,0),roottaken(1,0);

	bool isrootfree=true;
	if(at<nx) if(xmask&(1LL<<at)) isrootfree=false;
	if(at>=nx) if(ymask&(1LL<<(at-nx))) isrootfree=false;
	if(isrootfree) ++rootfree[0]; else ++roottaken[0];

	for(int to=fst[at];to!=-1;to=nxt[to]) {
		pair<vector<int>, vector<int> > cur=dfstree(to,xmask,ymask);
		roottaken=add(combine(roottaken,add(cur)),inc(combine(rootfree,cur.first),val[to]));
		rootfree=combine(rootfree,add(cur));
	}
	//printf("dfsed %2d %lld %lld:",at,xmask,ymask); REPSZ(i,rootfree) printf(" %d",rootfree[i]); printf(" |"); REPSZ(i,roottaken) printf(" %d",roottaken[i]); puts("");
	return MP(rootfree,roottaken);
}

vector<int> treecalc(ll comp,ll tree) {
	vector<int> ret;
	ll other=comp-tree;
	//printtree(root,0);
	for(ll useother=0;;useother=(useother+(1LL<<k)-1-other+1)&other) {
		//printf("\tuseother:%lld (other=%lld)\n",useother,other);
		ll xmask=0,ymask=0; int cur=1,cnt=0; bool ok=true;
		REP(i,k) if(useother&(1LL<<i)) {
			if(xmask&(1LL<<x[i])) ok=false; else xmask|=1LL<<x[i];
			if(ymask&(1LL<<y[i])) ok=false; else ymask|=1LL<<y[i];
			cur=(ll)cur*w[i]%MOD; ++cnt;
		}
		if(ok) {
			vector<int> fixed(cnt+1,0); fixed[cnt]=cur;
			vector<int> nonfixed=add(dfstree(root,xmask,ymask));
			vector<int> now=combine(fixed,nonfixed); REPSZ(i,now) { while(i>=SZ(ret)) ret.PB(0); ret[i]=(ret[i]+now[i])%MOD; }
		}
		if(useother==other) break;
	}

	return ret;
}

pair<int,pair<int,int> > ordered[50];
int dp[51][18][1<<17];
int bit[50],nbit;

vector<int> xcalc(ll comp,ll xmask) {
	memset(bit,-1,sizeof(bit)); nbit=0; REP(i,nx) if(xmask&(1LL<<i)) bit[i]=nbit++;
	int m=0; REP(i,k) if(comp&(1LL<<i)) ordered[m++]=MP(y[i],MP(x[i],w[i])); sort(ordered,ordered+m);
	REPE(i,m) REPE(j,nbit) REP(mask,1<<nbit) dp[i][j][mask]=i==m&&j==0?1:0;
	for(int i=m-1;i>=0;--i) {
		int cy=ordered[i].first,cx=ordered[i].second.first,cw=ordered[i].second.second,cbit=bit[cx];
		REPE(j,nbit) REP(mask,1<<nbit) {
			dp[i][j][mask]=dp[i+1][j][mask];
			if(j>=1&&mask&(1LL<<cbit)) {
				int ni=i+1; while(ni<m&&cy==ordered[ni].first) ++ni;
				dp[i][j][mask]=(dp[i][j][mask]+(ll)cw*dp[ni][j-1][mask-(1LL<<cbit)])%MOD;
			}
		}
	}
	vector<int> ret(nbit+1); REPE(j,nbit) ret[j]=dp[0][j][(1<<nbit)-1]; return ret;
}

vector<int> ycalc(ll comp,ll ymask) {
	memset(bit,-1,sizeof(bit)); nbit=0; REP(i,ny) if(ymask&(1LL<<i)) bit[i]=nbit++;
	int m=0; REP(i,k) if(comp&(1LL<<i)) ordered[m++]=MP(x[i],MP(y[i],w[i])); sort(ordered,ordered+m);
	REPE(i,m) REPE(j,nbit) REP(mask,1<<nbit) dp[i][j][mask]=i==m&&j==0?1:0;
	for(int i=m-1;i>=0;--i) {
		int cx=ordered[i].first,cy=ordered[i].second.first,cw=ordered[i].second.second,cbit=bit[cy];
		REPE(j,nbit) REP(mask,1<<nbit) {
			dp[i][j][mask]=dp[i+1][j][mask];
			if(j>=1&&mask&(1LL<<cbit)) {
				int ni=i+1; while(ni<m&&cx==ordered[ni].first) ++ni;
				dp[i][j][mask]=(dp[i][j][mask]+(ll)cw*dp[ni][j-1][mask-(1LL<<cbit)])%MOD;
			}
		}
	}
	vector<int> ret(nbit+1); REPE(j,nbit) ret[j]=dp[0][j][(1<<nbit)-1]; return ret;
}


vector<int> calc(ll comp) {
	//printf("comp(%llx)\n",comp);
	ll xmask=0,ymask=0,tree=0; int xcnt=0,ycnt=0,remcnt=0;
	REP(i,k) if(comp&(1LL<<i)) ++remcnt;
	REP(i,k) if(comp&(1LL<<i)) {
		qhead=qtail=0; tree|=1LL<<i; xmask|=1LL<<x[i]; ymask|=1LL<<y[i]; ++xcnt,++ycnt,--remcnt; q[qhead++]=i;
		root=x[i]; fst[x[i]]=nx+y[i]; nxt[x[i]]=-1;  fst[nx+y[i]]=-1; nxt[nx+y[i]]=-1; val[nx+y[i]]=w[i];
		while(qtail<qhead) {
			int at=q[qtail++];
			REP(j,k) if(comp&(1LL<<j)) {
				if(x[j]==x[at]&&(ymask&(1LL<<y[j]))==0) { tree|=1LL<<j; ymask|=1LL<<y[j]; --remcnt,++ycnt; q[qhead++]=j; nxt[nx+y[j]]=fst[x[j]]; fst[x[j]]=nx+y[j]; fst[nx+y[j]]=-1; val[nx+y[j]]=w[j]; }
				if(y[j]==y[at]&&(xmask&(1LL<<x[j]))==0) { tree|=1LL<<j; xmask|=1LL<<x[j]; --remcnt,++xcnt; q[qhead++]=j; nxt[x[j]]=fst[nx+y[j]]; fst[nx+y[j]]=x[j]; fst[x[j]]=-1; val[x[j]]=w[j]; }
			}
		}
		break;
	}
	//printf("\tx=%d,y=%d,rem=%d\n",xcnt,ycnt,remcnt);
	if(remcnt<=xcnt&&remcnt<=ycnt) return treecalc(comp,tree);
	if(xcnt<=ycnt) return xcalc(comp,xmask);
	return ycalc(comp,ymask);
}


vector<int> calc() {
	vector<int> ret(1,1);
	ll left=(1LL<<k)-1;
	REP(i,k) if(left&(1LL<<i)) {
		ll cur=1LL<<i; left-=1LL<<i;
		qhead=qtail=0; q[qhead++]=i;
		while(qtail<qhead) {
			int at=q[qtail++];
			REP(j,k) if(left&(1LL<<j)) {
				if(x[j]==x[at]) { cur|=1LL<<j; left-=1LL<<j; q[qhead++]=j; }
				else if(y[j]==y[at]) { cur|=1LL<<j; left-=1LL<<j; q[qhead++]=j; }
			}
		}
		ret=combine(ret,calc(cur));
	}
	return ret;
}

int fact[100001];

void run() {
	scanf("%d%d",&n,&k);
	REP(i,k) { scanf("%d%d%d",&x[i],&y[i],&w[i]); --x[i],--y[i],--w[i]; }
	REP(i,k) xx[i]=x[i]; sort(xx,xx+k); nx=0; REP(i,k) if(i==0||xx[i]!=xx[nx-1]) xx[nx++]=xx[i];
	REP(i,k) yy[i]=y[i]; sort(yy,yy+k); ny=0; REP(i,k) if(i==0||yy[i]!=yy[ny-1]) yy[ny++]=yy[i];
	REP(i,k) REP(j,nx) if(x[i]==xx[j]) { x[i]=j; break; }
	REP(i,k) REP(j,ny) if(y[i]==yy[j]) { y[i]=j; break; }
	fact[0]=1; FORE(i,1,n) fact[i]=(ll)fact[i-1]*i%MOD;

	//REP(i,k) printf("%d %d %d\n",x[i],y[i],w[i]);
	
	vector<int> ways=calc();
	//REPSZ(i,ways) printf("%d: %d\n",i,ways[i]);
	int ret=0;
	REPSZ(i,ways) { // use i of the k special edges, other edges are 1
		ret=(ret+(ll)fact[n-i]*ways[i])%MOD;
	}
	printf("%d\n",ret);



}

int main() {
	run();
	return 0;
}
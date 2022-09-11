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
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a%b); }

const int MAXN = 100000;

int n;
vector<int> adj[MAXN];
int ans[MAXN + 1];

int par[MAXN], dep[MAXN], sz[MAXN], heavy[MAXN];
int mxpathlen[MAXN], mxdesclen[MAXN];

void dfsinit(int at) {
	dep[at] = par[at] == -1 ? 0 : dep[par[at]] + 1, sz[at] = 1, heavy[at] = -1, mxpathlen[at] = 1, mxdesclen[at] = 1;
	REPSZ(i, adj[at]) {
		int to = adj[at][i]; if (to == par[at]) continue;
		par[to] = at; dfsinit(to);
		sz[at] += sz[to]; if (heavy[at] == -1 || sz[to] > sz[heavy[at]]) heavy[at] = to; mxpathlen[at] = max(max(mxpathlen[at], mxpathlen[to]), mxdesclen[at] + mxdesclen[to]), mxdesclen[at] = max(mxdesclen[at], mxdesclen[to] + 1);
	}
}

int remlen[MAXN];



void upd2(int &mx, int &mx2, int val) { if (val > mx) mx2 = mx, mx = val; else if (val > mx2) mx2 = val; }
void upd2idx(vector<int> &v, int &mxidx, int &mxidx2, int idx) { if (mxidx == -1 || v[idx] > v[mxidx]) mxidx2 = mxidx, mxidx = idx; else if (mxidx2 == -1 || v[idx] > v[mxidx2]) mxidx2 = idx; }
void upd2idx2(vector<int> &v,int &mxidx, int &mxidx2, int idx1, int idx2) { if(idx1!=-1) upd2idx(v,mxidx,mxidx2,idx1); if(idx2!=-1) upd2idx(v,mxidx,mxidx2,idx2); }
struct HP {
	vector<int> nodes;

	vector<int> dep2val, val2dep;
	vector<int> a; // mxdesclen+dep, use for tail 
	vector<int> b; // mxdesclen-dep, use for head

	vector<int> lg;
	vector<vector<int>> armq,armq2;
	vector<vector<int>> brmq,brmq2;

	vector<int> red; // ordered indices of red nodes
	vector<vector<int>> redchilds;
	vector<int> mxblackchild, mxblackchild2;

	void init() {
		dep2val.clear(), val2dep.clear(), a.clear(), b.clear(), red.clear(), redchilds = vector<vector<int>>(SZ(nodes)), mxblackchild = mxblackchild2 = vector<int>(SZ(nodes), 0);
		REPSZ(i, nodes) { 
			int at = nodes[i]; dep2val.PB(SZ(a)); red.PB(i); a.PB(i); b.PB(-i); val2dep.PB(i); a.PB(i); b.PB(-i); val2dep.PB(i);
			REPSZ(j, adj[at]) { 
				int to = adj[at][j]; if (to == par[at] || to == heavy[at]) continue;
				a.PB(mxdesclen[to] + i); b.PB(mxdesclen[to] - i); val2dep.PB(i); redchilds[i].PB(to);
			}
		}
		dep2val.PB(SZ(a));
		lg=vector<int>(SZ(a)+1); lg[1]=0; FORSZ(i,2,lg) { lg[i]=lg[i-1]; while((2<<lg[i])<=i) ++lg[i]; }
		armq=armq2=vector<vector<int>>(SZ(a)); REPSZ(i,a) { armq[i]=armq2[i]=vector<int>(lg[i+1]+1,-1); upd2idx(a,armq[i][0],armq2[i][0],i); FORE(k,1,lg[i+1]) { armq[i][k]=armq[i][k-1],armq2[i][k]=armq2[i][k-1]; upd2idx2(a,armq[i][k],armq2[i][k],armq[i-(1<<(k-1))][k-1],armq2[i-(1<<(k-1))][k-1]); } }
		brmq=brmq2=vector<vector<int>>(SZ(b)); REPSZ(i,b) { brmq[i]=brmq2[i]=vector<int>(lg[i+1]+1,-1); upd2idx(b,brmq[i][0],brmq2[i][0],i); FORE(k,1,lg[i+1]) { brmq[i][k]=brmq[i][k-1],brmq2[i][k]=brmq2[i][k-1]; upd2idx2(b,brmq[i][k],brmq2[i][k],brmq[i-(1<<(k-1))][k-1],brmq2[i-(1<<(k-1))][k-1]); } }
	}

	int makepath(int ol, int oor,int len) { // returns depth of found path, use only black nodes of path in [l..r)
		if(ol>=oor) return -1;
		int l = dep2val[ol], r = dep2val[oor] - 1;
		int ret = -1, amxidx = -1, amxidx2 = -1, bmxidx = -1, bmxidx2 = -1;
		//REPSZ(i,armq) { printf("armq%d:",i); REPSZ(j,armq[i]) printf(" %d/%d",armq[i][j],armq2[i][j]); puts(""); }
		//REPSZ(i,brmq) { printf("brmq%d:",i); REPSZ(j,brmq[i]) printf(" %d/%d",brmq[i][j],brmq2[i][j]); puts(""); }
		for(int k=lg[r-l+1];k>=0;--k) {
			if(r-(1<<k)+1<l) continue;
			int camxidx=amxidx,camxidx2=amxidx2,cbmxidx=bmxidx,cbmxidx2=bmxidx2;
			upd2idx2(a,camxidx,camxidx2,armq[r][k],armq2[r][k]);
			upd2idx2(b,cbmxidx,cbmxidx2,brmq[r][k],brmq2[r][k]);
			int cur=camxidx!=cbmxidx?(a[camxidx]+b[cbmxidx]+1>=len?min(camxidx,cbmxidx):-1):(cbmxidx2!=-1&&a[camxidx]+b[cbmxidx2]+1>=len?min(camxidx,cbmxidx2):camxidx2!=-1&&a[camxidx2]+b[cbmxidx]+1>=len?min(camxidx2,cbmxidx):-1);
			//printf("r=%d l=%d k=%d -> (%d,%d) (%d,%d) [%d,%d] [%d,%d]\n",r,l,k,camxidx,camxidx2,cbmxidx,cbmxidx2,armq[r][k],armq2[r][k],brmq[r][k],brmq2[r][k]);
			if(cur!=-1) ret=val2dep[cur],l=cur+1; else amxidx=camxidx,amxidx2=camxidx2,bmxidx=cbmxidx,bmxidx2=cbmxidx2,r-=(1<<k);
		}
		/*int chk=-1;
		{
			int amxidx = -1, amxidx2 = -1, bmxidx = -1, bmxidx2 = -1;
			for (int i = dep2val[oor] - 1; i >= dep2val[ol]; --i) {
				upd2idx(a, amxidx, amxidx2, i);
				upd2idx(b, bmxidx, bmxidx2, i);
				if (amxidx != bmxidx) { if (a[amxidx] + b[bmxidx] + 1 >= len) { chk=val2dep[i]; break; } }
				else { if (bmxidx2 != -1 && a[amxidx] + b[bmxidx2] + 1 >= len || amxidx2 != -1 && a[amxidx2] + b[bmxidx] + 1 >= len) { chk=val2dep[i]; break; } }
			}
		}
		if(chk!=ret) { printf("error: makepath(%d,%d,%d) [%d..%d] -> ret=%d chk=%d\n",ol,oor,len,dep2val[ol],dep2val[oor]-1,ret,chk); exit(0); }*/
		return ret;
	}
	int makehead(int ol, int oor, int len) { // returns depth of found path
		if(ol>=oor) return -1;
		int l = dep2val[ol], r = dep2val[oor] - 1;
		int ret=-1;
		for(int k=lg[r-l+1];k>=0;--k) {
			if(r-(1<<k)+1<l) continue;
			int cur=b[brmq[r][k]]+oor>=len?brmq[r][k]:-1;
			if(cur!=-1) ret=val2dep[cur],l=cur+1; else r-=(1<<k);
		}
		/*int chk=-1;
		for (int i = dep2val[oor] - 1; i >= dep2val[ol]; --i) {
			if (b[i] + oor >= len) { chk=val2dep[i]; break; }
		}
		if(chk!=ret) { printf("error: makehead(%d,%d,%d) -> ret=%d chk=%d\n",ol,oor,len,ret,chk); exit(0); }*/
		return ret;
	}
	int mxtaillen(int ol, int oor) { // returns maximum length of tail
		if(ol>=oor) return 0;
		int l = dep2val[ol], r = dep2val[oor] - 1;
		int k=lg[r-l+1],ret=max(a[armq[l+(1<<k)-1][k]],a[armq[r][k]])-ol+1;
		/*int chk = 0;
		for (int i = dep2val[oor] - 1; i >= dep2val[ol]; --i) {
			chk = max(chk, a[i] - ol + 1);
		}
		if(chk!=ret) { printf("error: mxtaillen(%d,%d) [%d..%d] -> ret=%d chk=%d\n",ol,oor,l,r,ret,chk); exit(0); }*/
		return ret;
	}


	pair<int, int> calc(int wantlen) { // (#paths,remaining length)
		vector<int> nred;
		REPSZ(i, red) {
			int idx = red[i]; vector<int> nredchilds;
			REPSZ(j, redchilds[idx]) { int to = redchilds[idx][j]; if (mxpathlen[to] >= wantlen) nredchilds.PB(to); else upd2(mxblackchild[idx], mxblackchild2[idx], mxdesclen[to]); }
			redchilds[idx] = nredchilds;
			if (idx == 0 || SZ(nredchilds)>0) nred.PB(idx);
		}
		red = nred;
		/*if (wantlen == 5) {
			printf("here\n");
			REPSZ(i, red) { printf("red%d:", nodes[red[i]] + 1); REPSZ(j, redchilds[red[i]]) printf(" %d", redchilds[red[i]][j] + 1); puts(""); } 
			printf("a:"); REPSZ(i, a) printf(" %2d", a[i]); puts("");
			printf("b:"); REPSZ(i, b) printf(" %2d", b[i]); puts("");
		}*/

		int npaths = 0, rem = 0;
		for (int i = SZ(red) - 1; i >= 0; --i) {
			int idx = red[i], lim = i + 1 < SZ(red) ? red[i + 1] : SZ(nodes);
			int opt1 = makepath(idx + 1, lim, wantlen); // use only black nodes
			int opt2 = rem > 0 ? makehead(idx + 1, lim, wantlen - rem) : -1;
			//printf("opt1=%d opt2=%d\n", opt1, opt2);
			int cur = max(opt1, opt2);
			while (cur != -1) {
				++npaths, lim = cur, rem = 0;
				cur = makepath(idx + 1, lim, wantlen);
				//printf("lim=%d -> %d\n", lim, cur);
			}
			int mxlen = mxblackchild[idx], mxlen2 = mxblackchild2[idx];
			int taillen1 = mxtaillen(idx + 1, lim), taillen2 = lim - idx - 1 + rem; upd2(mxlen, mxlen2, max(taillen1, taillen2));
			REPSZ(j, redchilds[idx]) { int to = redchilds[idx][j]; upd2(mxlen, mxlen2, remlen[to]); }
			if (mxlen + mxlen2 + 1 >= wantlen) ++npaths, rem = 0; else rem = mxlen + 1;
		}
		//if (wantlen == 4) printf(" -> (%d,%d)\n", npaths, rem);
		return MP(npaths, rem);
	}
};

vector<HP> hp;

void dfshp(int at) {
	REPSZ(i, adj[at]) { int to = adj[at][i]; if (to == par[at]) continue; dfshp(to); }
	if (par[at] == -1 || heavy[par[at]] != at) {
		int idx = SZ(hp); hp.PB(HP());
		for (int x = at; x != -1; x = heavy[x]) hp[idx].nodes.PB(x);
	}
}

void solve() {
	par[0] = -1; dfsinit(0);
	hp.clear(); dfshp(0); REPSZ(i, hp) hp[i].init();

	vector<int> active; REPSZ(i, hp) active.PB(i);
	FORE(len, 1, n) {
		//printf("processing len=%d\n", len);
		ans[len] = 0;
		vector<int> nactive; REPSZ(i, active) { int idx = active[i], root = hp[idx].nodes[0]; if (mxpathlen[root] >= len) nactive.PB(idx); } active = nactive;
		REPSZ(i, active) {
			int idx = active[i], root = hp[idx].nodes[0];
			pair<int, int> cur = hp[idx].calc(len);
			ans[len] += cur.first; remlen[root] = cur.second;
		}
	}
}

void run() {
	scanf("%d", &n);
	REP(i, n - 1) { int a, b; scanf("%d%d", &a, &b); --a, --b; adj[a].PB(b); adj[b].PB(a); }
	solve();
	FORE(i, 1, n) printf("%d\n", ans[i]);
}

void stress() {
	REP(rep,1000) {
		n=MAXN;
		REP(i,n) adj[i].clear();
		int at=1; while(at<n) { int len=rand()%min(n/10,n-at)+1,par=rand()%at; adj[at].PB(par),adj[par].PB(at); REP(i,len-1) adj[at+i].PB(at+i+1),adj[at+i+1].PB(at+i); at+=len; }
		solve();
		printf(".");
	}
}

int main() {
	run();
	//stress();
	return 0;
}
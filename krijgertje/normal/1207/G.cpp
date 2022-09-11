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
#include <functional>
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

struct SuffixArray {
	vector<int> sa; // sa[idx] = offset of idx-th suffix
	vector<int> pos; // pos[off] = index in suffix array of suffix at off
	vector<int> lcp; // lcp[idx] = longest common prefix of idth-th suffix and (idx+1)-th suffix

	vector<int> id; int nid; // id[0] = value of the empty suffix, id[off+1] = value of the suffix at off
	vector<int> tmp;
	vector<int> cnt;
	vector<int> rmq;

	template<typename T,typename U> void buildsalcp(int n,int alph,T val,U nxt) { // val(off) -> value at given offset, nxt(off,k) -> offset that is 2^k away
		cnt=vector<int>(max(alph,n+1),0); sa=tmp=pos=lcp=vector<int>(n); id=vector<int>(n+1); rmq=vector<int>(2*(n+1));
		REP(i,n) ++cnt[val(i)];
		for(int i=alph-2;i>=0;--i) cnt[i+1]=cnt[i]; cnt[0]=0;
		REP(i,alph-1) cnt[i+1]+=cnt[i];
		REP(i,n) sa[cnt[val(i)]++]=i;
		REP(i,n) pos[sa[i]]=i;
		nid=0; id[0]=nid++; REP(i,n) if(i==0||val(sa[i])!=val(sa[i-1])) id[sa[i]+1]=nid++; else id[sa[i]+1]=nid-1;
		REP(i,n) lcp[i]=i+1<n&&id[sa[i]+1]==id[sa[i+1]+1]?1:0;
		for(int k=0;;++k) {
			bool done=true; REP(i,n) if(lcp[i]==1<<k) done=false; if(done) break;
			REP(i,nid) cnt[i]=0;
			REP(i,n) ++cnt[id[nxt(i,k)+1]];
			for(int i=nid-2;i>=0;--i) cnt[i+1]=cnt[i]; cnt[0]=0;
			REP(i,nid-1) cnt[i+1]+=cnt[i];
			REP(i,n) tmp[cnt[id[nxt(i,k)+1]]++]=i;
			REP(i,nid) cnt[i]=0;
			REP(i,n) ++cnt[id[i+1]];
			for(int i=nid-2;i>=0;--i) cnt[i+1]=cnt[i]; cnt[0]=0;
			REP(i,nid-1) cnt[i+1]+=cnt[i];
			REP(i,n) sa[cnt[id[tmp[i]+1]]++]=tmp[i];
			REP(i,n) pos[sa[i]]=i;
			REP(i,n) rmq[n+i]=lcp[i]; for(int i=n-1;i>=1;--i) rmq[i]=min(rmq[2*i+0],rmq[2*i+1]);
			auto getrmq=[&](int l,int r) { int ret=INT_MAX; for(l+=n,r+=n;l<r;l>>=1,r>>=1) { if(l&1) ret=min(ret,rmq[l++]); if(r&1) ret=min(ret,rmq[--r]); } return ret; };
			REP(i,n) if(lcp[i]==1<<k) { int ii=nxt(sa[i],k),jj=nxt(sa[i+1],k); if(ii==-1||jj==-1) continue; ii=pos[ii],jj=pos[jj]; if(ii>jj) swap(ii,jj); lcp[i]+=id[sa[ii]+1]==id[sa[jj]+1]?1<<k:getrmq(ii,jj); }
			nid=0; id[0]=nid++; REP(i,n) if(i==0||id[sa[i]+1]!=id[sa[i-1]+1]||id[nxt(sa[i],k)+1]!=id[nxt(sa[i-1],k)+1]) tmp[sa[i]]=nid++; else tmp[sa[i]]=nid-1;
			REP(i,n) id[i+1]=tmp[i];
		}
	}
	void buildsalcp(const string &s) { buildsalcp(SZ(s),256,[&](int off) { return (int)s[off]; },[&](int off,int k) { return off+(1<<k)<SZ(s)?off+(1<<k):-1; }); }


	/*template<typename T> void buildlcp(T getlcp) { // getlcp(i,j,k) -> longest common prefix of two offsets (first k are guaranteed to match)
		int k=0; lcp=vector<int>(SZ(sa)); lcp.back()=-1;
		REPSZ(i,sa) {
			if(pos[i]+1>=SZ(sa)) { k=0; continue; }
			int j=sa[pos[i]+1];
			k=getlcp(i,j,k);
			lcp[pos[i]]=k; if(k>0) --k;
		}
	}
	void buildlcp(const string &s) { buildlcp([&](int i,int j,int k) { while(i+k<SZ(s)&&j+k<SZ(s)&&s[i+k]==s[j+k]) ++k; return k; }); }*/

	vector<int> bsllcp,bsrlcp; // bsllcp[m] and bsrlcp[m] are the lcps of (l,m) and (m,r) in binary search in find-method

	void buildbs() {
		bsllcp=bsrlcp=vector<int>(SZ(sa));
		std::function<int(int,int)> rec=[&](int l,int r)->int {
			if(r-l==1) return l==-1||r==SZ(sa)?0:lcp[l];
			int m=l+(r-l)/2;
			bsllcp[m]=rec(l,m); bsrlcp[m]=rec(m,r);
			return min(bsllcp[m],bsrlcp[m]);
		};
		rec(-1,SZ(sa));
	}

	template<typename T,typename U> int find(T getlcp,U cmp,bool upperbound=false) { // getlcp(off,k) -> longest common prefix with suffix starting at off (first k is guaranteed to match), cmp(off,k) -> comparison of k-th character with suffix starting at off
		int l=-1,r=SZ(sa),llcp=0,rlcp=0;
		while(r-l>=2) {
			int m=l+(r-l)/2;
			if(llcp>=rlcp) { if(bsllcp[m]>llcp) l=m; else if(bsllcp[m]<llcp) r=m,rlcp=bsllcp[m]; else { int nlcp=getlcp(sa[m],llcp); if(cmp(sa[m],nlcp)<(!upperbound?0:1)) l=m,llcp=nlcp; else r=m,rlcp=nlcp; } }
				      else { if(bsrlcp[m]<rlcp) l=m,llcp=bsrlcp[m]; else if(bsrlcp[m]>rlcp) r=m; else { int nlcp=getlcp(sa[m],rlcp); if(cmp(sa[m],nlcp)<(!upperbound?0:1)) l=m,llcp=nlcp; else r=m,rlcp=nlcp; } }
		}
		return r;
	}
	int find(const string &s,const string &p,bool upperbound=false) { return find([&](int i,int k) { while(i+k<SZ(s)&&k<SZ(p)&&s[i+k]==p[k]) ++k; return k; },[&](int i,int k){ if(k==SZ(p)) return 0; if(i+k==SZ(s)) return -1; char a=s[i+k],b=p[k]; if(a!=b) return a<b?-1:+1; assert(false); return 0; },upperbound); }
	template<typename T,typename U> pair<int,int> findrange(T getlcp,U cmp) { return MP(find(getlcp,cmp,false),find(getlcp,cmp,true)); }
	pair<int,int> findrange(const string &s,const string &p) { return findrange([&](int i,int k) { while(i+k<SZ(s)&&k<SZ(p)&&s[i+k]==p[k]) ++k; return k; },[&](int i,int k){ if(k==SZ(p)) return 0; if(i+k==SZ(s)) return -1; if(k==SZ(p)) return +1; char a=s[i+k],b=p[k]; if(a!=b) return a<b?-1:+1; assert(false); return 0; }); }
};


const int MAXSONG=400000;
const int MAXQ=400000;
const int MAXNODE=MAXSONG+1;
const int MAXQLEN=400000;
const int MAXLG=18;


int nsong;
int par[MAXSONG];
char parc[MAXSONG];
int nq;
int qidx[MAXQ],qoff[MAXQ+1],qlen[MAXQ]; char qs[MAXQLEN+1]; int qans[MAXQ];

SuffixArray suff;


int up[MAXSONG][MAXLG+1];

int ql[MAXQ],qr[MAXQ];
vector<int> qat[MAXSONG];

vector<int> ch[MAXSONG];

int bit[MAXSONG+1];
int bget(int idx) { ++idx; int ret=0; while(idx>0) { ret+=bit[idx]; idx-=idx&-idx; } return ret; }
void bmod(int idx,int by) { ++idx; while(idx<=nsong) { bit[idx]+=by; idx+=idx&-idx; } }

void print() {
	REP(i,nsong) { int at=suff.sa[i]; printf("%2d:",at); while(at!=-1) { printf("%c",parc[at]); at=par[at]; } printf(" (%d)\n",suff.lcp[i]); }
}

void dfs(int at) {
	bmod(suff.pos[at],+1);
	//printf("inc(%d)\n",suff.pos[at]);
	REPSZ(_,qat[at]) {
		int id=qat[at][_],l=ql[id],r=qr[id];
		//printf("q[%d..%d)\n",l,r);
		qans[id]=bget(r-1)-bget(l-1);
	}
	REPSZ(i,ch[at]) {
		int to=ch[at][i];
		dfs(to);
	}
	//printf("dec(%d)\n",suff.pos[at]);
	bmod(suff.pos[at],-1);
}

int walk(int i,int steps) { for(int k=MAXLG;k>=0;--k) if(steps&(1<<k)) if(i!=-1) i=up[i][k]; return i; }

void solve() {
	//REP(i,nsong) printf("par=%d parc=%c\n",par[i],parc[i]);

	REP(i,nsong) up[i][0]=par[i];
	REP(k,MAXLG) REP(i,nsong) up[i][k+1]=up[i][k]==-1?-1:up[up[i][k]][k];

	suff.buildsalcp(nsong,26,[&](int off) { return (int)(parc[off]-'a'); },[&](int off,int k) { return up[off][k]; });
	suff.buildbs();

	//print();

	REP(i,nsong) qat[i].clear();
	REP(i,nq) {
		string s(qs+qoff[i],qs+qoff[i]+qlen[i]);
		reverse(s.begin(),s.end());
		int l,r; tie(l,r)=suff.findrange([&](int i,int k) { i=walk(i,k); while(i!=-1&&k<SZ(s)&&parc[i]==s[k]) i=par[i],++k; return k; },[&](int i,int k) { i=walk(i,k); if(k==SZ(s)) return 0; if(i==-1) return -1; char a=parc[i],b=s[k]; if(a!=b) return a<b?-1:+1; assert(false); return 0; });
		//printf("%d=%s [%d..%d)\n",i,s.c_str(),l,r);
		ql[i]=l,qr[i]=r; qat[qidx[i]].PB(i);
	}

	REP(i,nsong) ch[i].clear();
	REP(i,nsong) if(par[i]!=-1) ch[par[i]].PB(i);
	REPE(i,nsong) bit[i]=0;
	REP(i,nsong) if(par[i]==-1) dfs(i);
}


void run() {
	scanf("%d",&nsong);
	REP(i,nsong) { int kind; scanf("%d",&kind); if(kind==1) par[i]=-1; else scanf("%d",&par[i]),--par[i]; scanf(" %c",&parc[i]); }
	scanf("%d",&nq);
	qoff[0]=0; REP(i,nq) { scanf("%d%s",&qidx[i],qs+qoff[i]),--qidx[i]; qlen[i]=strlen(qs+qoff[i]); qoff[i+1]=qoff[i]+qlen[i]; }
	solve();
	REP(i,nq) printf("%d\n",qans[i]);
}

int qansstupid[MAXQ];

void solvestupid() {
	
	REP(i,nq) {
		vector<char> tmp;
		for(int at=qidx[i];at!=-1;at=par[at]) tmp.PB(parc[at]);
		reverse(tmp.begin(),tmp.end());
		qansstupid[i]=0;
		REPE(j,SZ(tmp)-qlen[i]) {
			bool ok=true; REP(k,qlen[i]) if(tmp[j+k]!=qs[qoff[i]+k]) { ok=false; break; } if(ok) ++qansstupid[i];
		}
	}
}

void stress() {
	int mxsong=1000,mxalph=3,mxqlen=5; nq=1000;
	REP(rep,100000) {
		nsong=rand()%mxsong+1;
		int alph=rand()%mxalph+1;
		REP(i,nsong) { par[i]=rand()%(i+1)-1; parc[i]='a'+rand()%alph; }
		qoff[0]=0; REP(i,nq) { qidx[i]=rand()%nsong; qlen[i]=rand()%mxqlen+1; REP(j,qlen[i]) qs[qoff[i]+j]='a'+rand()%alph; qoff[i+1]=qoff[i]+qlen[i]; } qs[qoff[nq]]='\0';
		//if(rep!=8889) continue;
		solve();
		solvestupid();
		bool ok=true; REP(i,nq) if(qans[i]!=qansstupid[i]) ok=false;
		//bool allzero=true; REP(i,nq) if(qans[i]!=0) allzero=false; printf("%c",allzero?'0':'+');
		if(ok) { if(rep%100==0) printf("."); continue; }
		printf("err rep=%d\n",rep);
		printf("%d\n",nsong);
		REP(i,nsong) if(par[i]==-1) printf("%d %c\n",1,parc[i]); else printf("%d %d %c\n",2,par[i]+1,parc[i]);
		printf("%d\n",nq);
		REP(i,nq) { printf("%d ",qidx[i]+1); REP(j,qlen[i]) printf("%c",qs[qoff[i]+j]); puts(""); }
		printf("have:"); REP(i,nq) printf(" %d",qans[i]); puts("");
		printf("want:"); REP(i,nq) printf(" %d",qansstupid[i]); puts("");
		break;
	}
}

int main() {
	run();
	//stress();
	return 0;
}
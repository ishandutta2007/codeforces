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

const int IMAGROOTID=0;
const int ZEROROOTID=1;
const int ALPH=26;
struct PalTreeNode { int firststart,len,suff,nxt[ALPH]; PalTreeNode() { firststart=len=suff=-1; memset(nxt,-1,sizeof(nxt)); } };
struct PalTree {
	char *s; int slen; int lg;
	vector<PalTreeNode> nodes; int nnodes;
	vector<int> longest;
	vector<vector<int>> up;
	void init(char *_s) { s=_s; slen=strlen(s); nodes=vector<PalTreeNode>(slen+2); nodes[IMAGROOTID].len=-1,nodes[IMAGROOTID].suff=IMAGROOTID; nodes[ZEROROOTID].len=0,nodes[ZEROROOTID].suff=IMAGROOTID,nnodes=2; longest=vector<int>(slen); }
	int augment(int at,int idx) {
		while(s[idx]!=s[idx-nodes[at].len-1]) at=nodes[at].suff;
		int &to=nodes[at].nxt[s[idx]-'a'];
		if(to==-1) { to=nnodes++; nodes[to].firststart=idx-nodes[at].len-1; nodes[to].len=nodes[at].len+2; at=nodes[at].suff; while(s[idx]!=s[idx-nodes[at].len-1]) at=nodes[at].suff; nodes[to].suff=nodes[to].len==1?ZEROROOTID:nodes[at].nxt[s[idx]-'a']; }
		return to;
	}
	void build() {
		REP(i,slen) longest[i]=augment(i==0?IMAGROOTID:longest[i-1],i);
		lg=0; while((2<<lg)<nnodes) ++lg; up=vector<vector<int>>(nnodes,vector<int>(lg+1)); REP(i,nnodes) up[i][0]=nodes[i].suff; REP(k,lg) REP(i,nnodes) up[i][k+1]=up[up[i][k]][k];
		//REP(j,nnodes) { printf("%d: firststart=%d len=%d suff=%d",j,nodes[j].firststart,nodes[j].len,nodes[j].suff); REP(k,ALPH) if(nodes[j].nxt[k]!=-1) printf(" %c=%d",'a'+k,nodes[j].nxt[k]); puts(""); }
	}
	int query(int idx,int lim) const {
		int at=longest[idx];
		if(nodes[at].len<=lim) return nodes[at].len;
		for(int k=lg;k>=0;--k) if(nodes[up[at][k]].len>lim) at=up[at][k];
		return nodes[nodes[at].suff].len;
	}
};

const int HMOD[]={1000000007,1000000009};
const int HMLT=2333;
struct HashNode { int a,b; HashNode() {} HashNode(int a,int b):a(a),b(b) {} ll val() { return (ll)a*HMOD[1]+b; } };
HashNode operator*(const HashNode &p,const int &x) { return HashNode((ll)p.a*x%HMOD[0],(ll)p.b*x%HMOD[1]); }
HashNode operator+(const HashNode &p,const int &x) { return HashNode((p.a+x)%HMOD[0],(p.b+x)%HMOD[1]); }
HashNode operator*(const HashNode &p,const HashNode &q) { return HashNode((ll)p.a*q.a%HMOD[0],(ll)p.b*q.b%HMOD[1]); }
HashNode operator+(const HashNode &p,const HashNode &q) { return HashNode((p.a+q.a)%HMOD[0],(p.b+q.b)%HMOD[1]); }
HashNode operator-(const HashNode &p,const HashNode &q) { return HashNode((p.a+HMOD[0]-q.a)%HMOD[0],(p.b+HMOD[1]-q.b)%HMOD[1]); }
struct Hash {
	char *s; int slen;
	vector<HashNode> hval,hpw;
	void init(char *_s) { s=_s; slen=strlen(s); hval=hpw=vector<HashNode>(slen+1); } 
	void build() { hval[0]=HashNode(0,0),hpw[0]=HashNode(1,1); REP(i,slen) hval[i+1]=hval[i]*HMLT+(s[i]-'a'+1),hpw[i+1]=hpw[i]*HMLT; }
	HashNode get(int l,int r) const { return hval[r+1]-hval[l]*hpw[r-l+1]; }
};

HashNode gettrihash(const Hash &h,int al,int ar,int bl,int br,int cl,int cr) { return (h.get(al,ar)*h.hpw[br-bl+1]+h.get(bl,br))*h.hpw[cr-cl+1]+h.get(cl,cr); }

bool decompose(const PalTree &fw,const PalTree &bw,int len,int al,int ar,int &bl,int &br,int &cl,int &cr) {
	int palsuff=fw.query(ar,ar-al+1),wantpref=ar-al+1-palsuff;
	if(wantpref!=0&&bw.query(len-al-1,wantpref)==wantpref) { bl=al,br=al+wantpref-1,cl=al+wantpref,cr=ar; return true; }
	int palpref=bw.query(len-al-1,ar-al+1),wantsuff=ar-al+1-palpref;
	if(wantpref!=0&&fw.query(ar,wantsuff)==wantsuff) { bl=al,br=al+palpref-1,cl=al+palpref,cr=ar; return true; }
	return false;
}


const int MAXLEN=200000;

char a[MAXLEN+1]; int alen;
char b[MAXLEN+1]; int blen;

char arev[MAXLEN+1];
char brev[MAXLEN+1];

PalTree ta,tb,tarev,tbrev;
Hash ha,hb;
map<ll,int> acnt; // The palindromes in A
map<ll,int> bcnt; // The palindromes in B
map<ll,int> asuff; // For each v the number of palindromes uv in A with border u
map<ll,int> bpref; // For each v the number of palindromes vu in B with border u

int safeget(const map<ll,int> &mp,ll key) { auto it=mp.find(key); return it!=mp.end()?it->second:0; }
ll solve() {
	REP(i,alen) arev[alen-i-1]=a[i]; arev[alen]='\0';
	REP(i,blen) brev[blen-i-1]=b[i]; brev[blen]='\0';
	ta.init(a); ta.build();
	tb.init(b); tb.build();
	tarev.init(arev); tarev.build();
	tbrev.init(brev); tbrev.build();
	ha.init(a); ha.build();
	hb.init(b); hb.build();
	acnt.clear(); bcnt.clear(); asuff.clear(); bpref.clear();
	ll ret=(ll)(ta.nnodes-2)*(tb.nnodes-2);
	// foreach palindrome in A uv with border u: subtract palindromes in B of the form vx with x also a palindrome in B
	// -> when |v|<=|x| then x must be its border (v is not a power), otherwise v=yw,x=y with y and w both palindromes (uniquely determinable) and the palindrome has form ywy
	// foreach palindrome in B vu with border u: subtract palindromes in A of the form xv with x also a palindrome in A
	// -> when |v|<=|x| then x must be its border (v is not a power), otherwise v=wy,x=y with y ans w both palindromes (uniquely determinable) and the palindrome has form ywy
	// foreach palindrome in A uv with border u: add palindromes in B of the form vx with border x

	FOR(i,2,ta.nnodes) {
		int pl=ta.nodes[i].firststart,pr=ta.nodes[i].firststart+ta.nodes[i].len-1;
		acnt[ha.get(pl,pr).val()]++;
		if(ta.nodes[i].suff<2) continue;
		int vl=pl+ta.nodes[ta.nodes[i].suff].len,vr=pr;
		//printf("ta%d %.*s -> %.*s (%lld)\n",i,ta.nodes[i].len,a+ta.nodes[i].firststart,vr-vl+1,a+vl,ha.get(vl,vr).val());
		asuff[ha.get(vl,vr).val()]++;
	}
	FOR(i,2,tb.nnodes) {
		int pl=tb.nodes[i].firststart,pr=tb.nodes[i].firststart+tb.nodes[i].len-1;
		bcnt[hb.get(pl,pr).val()]++;
		if(tb.nodes[i].suff<2) continue;
		int vl=pl,vr=pr-tb.nodes[tb.nodes[i].suff].len;
		//printf("tb%d %.*s -> %.*s (%lld)\n",i,tb.nodes[i].len,b+tb.nodes[i].firststart,vr-vl+1,b+vl,hb.get(vl,vr).val());
		bpref[hb.get(vl,vr).val()]++;
	}
	FOR(i,2,ta.nnodes) {
		int pl=ta.nodes[i].firststart,pr=ta.nodes[i].firststart+ta.nodes[i].len-1;
		if(ta.nodes[i].suff<2) continue;
		int vl=pl+ta.nodes[ta.nodes[i].suff].len,vr=pr,xl=pl,xr=vl-1;
		if(vr-vl<=xr-xl) ret-=safeget(bpref,ha.get(vl,vr).val());
		int wl,wr,yl,yr; if(decompose(ta,tarev,alen,vl,vr,yl,yr,wl,wr)) ret-=safeget(bcnt,gettrihash(ha,yl,yr,wl,wr,yl,yr).val());
	}
	FOR(i,2,tb.nnodes) {
		int pl=tb.nodes[i].firststart,pr=tb.nodes[i].firststart+tb.nodes[i].len-1;
		if(tb.nodes[i].suff<2) continue;
		int vl=pl,vr=pr-tb.nodes[tb.nodes[i].suff].len,xl=vr+1,xr=pr;
		if(vr-vl<=xr-xl) ret-=safeget(asuff,hb.get(vl,vr).val());
		int wl,wr,yl,yr; if(decompose(tb,tbrev,blen,vl,vr,wl,wr,yl,yr)) ret-=safeget(acnt,gettrihash(hb,yl,yr,wl,wr,yl,yr).val());
	}
	for(auto it=asuff.begin();it!=asuff.end();++it) ret+=(ll)it->second*safeget(bpref,it->first);

	return ret;
}

void run() {
	scanf("%s",a); alen=strlen(a);
	scanf("%s",b); blen=strlen(b);
	printf("%lld\n",solve());
}



bool ispal(char *s,int i,int j) { while(i<=j) { if(s[i]!=s[j]) return false; ++i,--j; } return true; }
ll bfsolve() {
	set<string> apal; REP(i,alen) FOR(j,i,alen) if(ispal(a,i,j)) apal.insert(string(a+i,a+j+1));
	set<string> bpal; REP(i,blen) FOR(j,i,blen) if(ispal(b,i,j)) bpal.insert(string(b+i,b+j+1));
	set<string> ret; for(auto ait=apal.begin();ait!=apal.end();++ait) for(auto bit=bpal.begin();bit!=bpal.end();++bit) ret.insert(*ait+*bit); return SZ(ret);
}

void stress1() {
	int t=0;
	for(alen=1;alen<=10;++alen) for(blen=1;blen<=10;++blen) REP(amask,1<<alen) REP(bmask,1<<blen) {
		REP(i,alen) a[i]=(amask&(1<<i))==0?'x':'y'; a[alen]='\0';
		REP(i,blen) b[i]=(bmask&(1<<i))==0?'x':'y'; b[blen]='\0';
		ll have=solve();
		ll want=bfsolve();
		if(have==want) { if(++t%1000==0) printf("."); continue; }
		printf("err a=%s b=%s have=%lld want=%lld\n",a,b,have,want);
		return;
	}
}

void stress2() {
	REP(rep,10) {
		alen=MAXLEN; REP(i,alen) a[i]='a'+rand()%26; a[alen]='\0';
		blen=MAXLEN; REP(i,blen) b[i]='a'+rand()%26; b[blen]='\0';
		ll have=solve();
		printf("%lld\n",have);
	}
}

int main() {
	run();
	//stress2();
	return 0;
}
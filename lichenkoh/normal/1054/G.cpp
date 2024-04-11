#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,tune=native")
#include "bits/stdc++.h"
#include <smmintrin.h>
#include <nmmintrin.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
const int MOD=1000000007;
#define endl "\n"
#define fst first
#define snd second
const int UNDEF = -1;
const int INF=1<<30;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;typedef vector<ll> vll;typedef pair<int,int> pii;typedef vector<int> vi;typedef vector<vi> vvi;
#ifdef ONLINE_JUDGE
#define assert(...) /* nothing */
#endif
#define DEBUG_CAT
#ifdef DEBUG_CAT
#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif
const int mn=2000;


class bs {
public:
	static const int WORD=64;
	static const int LOGWORD=6;
	typedef unsigned long long T;
	static const T zero=0ULL;
	vector<T> v;
	int bsz;
	int vsz;
	T lastmask;
	void init (int _bsz, bool zero=true) {
		bsz=_bsz;
		vsz=(bsz+WORD-1)>>LOGWORD;
		v.resize(vsz);
		{
			int szr=bsz&(WORD-1);
			if (szr==0) lastmask=-1ULL;
			else {
				lastmask=(1ULL<<szr)-1;
				
			}
			
		}
		if (zero) reset();
	}
	int size() {
		return bsz;
	}
	void reset() {
		for (int i=0;i<vsz;i++) v[i]=zero;
	}

	void set() {
		for (int i=0;i<vsz-1;i++) v[i]=~zero;
		v[vsz-1]=lastmask;
	
	}

	void flip() {
		for (int i=0;i<vsz;i++) v[i]=~v[i];
		v[vsz-1]&=lastmask;
	
	}

	int count() {
		v[vsz-1]=v[vsz-1]&lastmask;
		int ans=0;
		for (int i=0;i<vsz;i++) {
			ans+=__builtin_popcountll(v[i]);
		}
		return ans;
	}
	
	bool operator==(const bs& b){
		for (int i=0;i<vsz;i++) {
			if (this->v[i]!=b.v[i]) return false;
		}
		return true;
	}

	bool operator!=(const bs& b){
		for (int i=0;i<vsz;i++) {
			if (this->v[i]!=b.v[i]) return true;
		}
		return false;
	}

	bs& operator&=(const bs& b){
		for (int i=0;i<vsz;i++) {
			this->v[i] &= b.v[i];
		}
	  return *this;
	}
	bs& operator|=(const bs& b){
		for (int i=0;i<vsz;i++) {
			this->v[i] |= b.v[i];
		}
	  return *this;
	}
	bs& operator^=(const bs& b){
		for (int i=0;i<vsz;i++) {
			this->v[i] ^= b.v[i];
		}
	  return *this;
	}

	
	bs& operator<<=(const int k) {
		int q=k>>LOGWORD,r=k&(WORD-1);
		if (r==0) {
			for (int x=vsz-1;x>=q;x--) {
				v[x]=v[x-q];
			}
			for (int x=0;x<q;x++) v[x]=zero;
		}
		else {
			for (int x=vsz-1;x>=q+1;x--) {
				v[x]=(v[x-q]<<r)|(v[x-q-1]>>(WORD-r));
			}
			v[q]=v[0]<<r;
			for (int x=0;x<q;x++) v[x]=zero;
		}
	
		v[vsz-1]&=lastmask;
		
		return *this;
	}
	
	bs& operator>>=(const int k) {
		v[vsz-1]&=lastmask;
		int q=k>>LOGWORD,r=k&(WORD-1);
		if (r==0) {
			for (int x=0;x<=vsz-1-q;x++) {
				v[x]=v[x+q];
			}
			for (int x=vsz-q;x<vsz;x++) v[x]=zero;
		}
		else {
			for (int x=0;x<=vsz-2-q;x++) {
				v[x]=(v[x+q]>>r)|(v[x+q+1]<<(WORD-r));
			}
			v[vsz-1-q]=v[vsz-1]>>r;
			for (int x=vsz-q;x<vsz;x++) v[x]=zero;
		}
		return *this;
	}


  bs operator&(const bs& b) const {
		bs res; res.init(bsz,false);
		for (int i=0;i<vsz;i++) {
			res.v[i] = this->v[i] & b.v[i];
		}
		return res;
  }
  bs operator|(const bs& b) const {
		bs res; res.init(bsz,false);
		for (int i=0;i<vsz;i++) {
			res.v[i] = this->v[i] | b.v[i];
		}
		return res;
  }
  bs operator^(const bs& b) const {
		bs res; res.init(bsz,false);
		for (int i=0;i<vsz;i++) {
			res.v[i] = this->v[i] ^ b.v[i];
		}
		return res;
  }
  bs operator~() const {
		bs res; res.init(bsz,false);
		for (int i=0;i<vsz;i++) {
			res.v[i] = ~this->v[i];
		}
		res.v[vsz-1]&=lastmask;
		
		return res;
  }

  static int _Find_in_T(T a, const int r) {
  	// Given a!=0, returns the least bit > r that is set.
  	if (r==WORD-1) return -1;
  	a&=~((1ULL<<(r+1))-1ULL);
  	if (a==0) return -1;
  	return __builtin_ctzll(a);
  }

  int _Find_next_q(int q) {
  	for (int x=q;x<vsz;x++) {
  		T m=v[x];
  		if (m!=0) {
  			return x*WORD+__builtin_ctzll(m);
  		}
  	}
  	return bsz;
  }

  int _Find_first() {
  	return _Find_next_q(0);
  }

  int _Find_next(int i) {
  	int q=i>>LOGWORD;
  	int r=i&(WORD-1);
  	int cand=_Find_in_T(v[q],r);
  	if (cand!=-1) return q*WORD+cand;
  	return _Find_next_q(q+1);
  }

  void set(int i, bool b) {
  	int q=i>>LOGWORD;
  	int r=i&(WORD-1);
  	if (b) v[q]=v[q]|(1ULL<<r);
  	else v[q]&=(~(1ULL<<r));
  }

  class reference {
  public:
  	bs *b; int i;
  	reference(bs *_b, int _i) {
  		b=_b;i=_i;
  	}
  	operator bool() const {
  		bool ans=b->get(i);
  		return ans;
  	}
  	reference &operator=(bool x) {
  		b->set(i,x);
  		return *this;
  	}
  };

  bool get(int i) const {
  	int q=i>>LOGWORD;
  	int r=i&(WORD-1);
  	bool ans=((v[q]>>r)&1)!=0;
  	return ans;
  }

  bool operator [](int i) const {
  	return get(i);
  }

  reference operator[](int i) {
  	return reference(this, i);
  }

  void readString(const string &a) {
  	int alen=a.length();
  	int idx=0;
  	for (int x=0;x<vsz;x++) {
			T got=0;
			for (int b=0;b<32;b++) {
				T bit= idx<alen?a[idx]-'0':zero;
				got |= bit<<b;
			}
  		v[x]=got;
  	}
  }
};





bs a[mn],origa[mn];
vi g[mn];
bs seen;
bool iscyc;
bs induced;
int b2cnt[mn],r2cnt[mn];
bs x2b[mn];

priority_queue<pii,vector<pii>,greater<pii> > pq;
bs cvalid,rvalid;

void init(int rn, int cn) {
	cvalid.init(cn,false);
	cvalid.set();
	rvalid.init(rn,false);
	rvalid.set();
	for (int x=0;x<rn;x++) {
		a[x].init(cn);
	}
	for (int x=0;x<cn;x++){
		x2b[x].init(cn);
	}
	for (int x=0;x<cn;x++) g[x].clear();
	seen.init(cn);
	iscyc=false;
	memset(b2cnt,0,sizeof b2cnt);
	memset(r2cnt,0,sizeof r2cnt);
	pq=priority_queue<pii,vector<pii>,greater<pii> >();
}


void dfs(int x, int p) {
	if (seen[x]) {
		iscyc=true;
		return;
	}
	seen[x]=true;
	for (auto &y:g[x]) {
		if (y!=p) dfs(y,x);
		if (iscyc) return;
	}
}


void dfs2(int x) {
	if (seen[x]||!induced[x]) return;
	seen[x]=true;
	for (auto &y:g[x]) {
		dfs2(y);
	}
}

void makeb(int x, int rn) {
		auto &group=x2b[x]; group.set();
		//for (int r=0;r<rn;r++) if (rvalid[r]) printf("ar:%d\n",r);
		for (int r=rvalid._Find_first();r<rn;r=rvalid._Find_next(r)) {
			//printf("r:%d\n",r);
			if (a[r][x]) {
				group&=a[r];
			}
		}
		group[x]=false;
		int cnt=group.count();
		//printf("x:%d cnt:%d\n",x,cnt);
		if (cnt==0) {
			b2cnt[x]=INF;
		}
		else {
			pq.push(MP(cnt,x));
			b2cnt[x]=cnt;
		}
}

void solve(int rn,int cn) {
  for (int r=0;r<rn;r++) {
    string s; cin>>s;
    int ones=0;
    for (auto &c:s) ones+=c-'0';
    if (ones<=1) rvalid[r]=false;
  	r2cnt[r]=ones;
    for (int c=0;c<cn;c++) a[r][c]=(s[c]=='1');
    origa[r]=a[r];
  }

	for (int x=0;x<cn;x++) {
		makeb(x,rn);
	}

	while(!pq.empty()) {
		pii top=pq.top(); int cnt=top.fst,x=top.snd; pq.pop();
		if (b2cnt[x]!=cnt||!cvalid[x]) continue;
  	int y;
  	for (y=x2b[x]._Find_first();y<cn;y=x2b[x]._Find_next(y)) {
  		//printf("x:%d try y:%d\n",x,y);
  		if (cvalid[y]&&y!=x) break;
  	}
  	// x is not attached to anything. Process remaining connected components.
  	if (y>=cn) continue;
  	cvalid[x]=false;
  	//printf("x:%d -> y:%d\n",x,y);
  	// x is a leaf connecting to y.
  	g[x].PB(y); g[y].PB(x);
  	assert(cvalid[y]);
  	{
  		for (int r=rvalid._Find_first();r<rn;r=rvalid._Find_next(r)) {
  			auto &group=a[r];
  			if (group[x]) {
  				group[x]=false;
  				if (group[y]) {
  					r2cnt[r]--;
  					if (r2cnt[r]<=1) {
  						rvalid[r]=false;
  					}
  				}
  				else group[y]=true;
  			}
  		}
  	}
  	makeb(y,rn);
  	for (int z=cvalid._Find_first();z<cn;z=cvalid._Find_next(z)) {
  		if (z==y) continue;
  		auto &group=x2b[z];
  		if (group[x]) {
  			group[x]=false;
  			if (group[y]) {
  				b2cnt[z]--;
  				if (b2cnt[z]==0) {
  					b2cnt[z]=INF;
  				}
  				else {
  					pq.push(MP(b2cnt[z],z));
  				}
  			}
  			else {
  				group[y]=true;
  			}
  		}
  	}
	}
  int prev=-1;
  vector<pii> join;
  for (int x=0;x<cn;x++) {
  	if (!seen[x]) {
  		dfs(x,-1);
  		if (iscyc) {
  			//fflush(stdout);assert(0); 
  			printf("NO\n");
  			return;
  		}
  		if (prev!=-1) {
  			join.PB(MP(prev,x));
  		}
  		prev=x;
  	}
  }
  for (auto &w:join) {
  	int x=w.fst,y=w.snd; g[x].PB(y); g[y].PB(x);
  }
  for (int r=0;r<rn;r++) {
  	if (origa[r].count()) {
  		seen.reset();
  		induced=origa[r];
  		dfs2(induced._Find_first());
  		if (induced!=seen) {
  			//fflush(stdout);assert(0);
  			printf("NO\n");
  			return;
  		}
  	}
  }
  printf("YES\n");
  //for (auto &w:join) printf("%d %d\n",w.fst+1,w.snd+1);
  for (int x=0;x<cn;x++) {
  	for (auto &y:g[x]) {
  		if (y>x) printf("%d %d\n",x+1,y+1);
  	}
  }
}

int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int T; cin>>T;
  for(int i=0;i<T;i++) {
  	int rn,cn; cin>>cn>>rn;
  	init(rn,cn);
  	solve(rn,cn);
  }
}
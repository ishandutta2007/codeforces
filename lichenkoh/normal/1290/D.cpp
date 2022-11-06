#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,mmx,avx")
#include "bits/stdc++.h"
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
const int MOD=1000000007;
#define fst first
#define snd second
const int UNDEF = -1;
const int INF=1<<30;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;typedef vector<ll> vll;typedef pair<int,int> pii;typedef vector<int> vi;typedef vector<vi> vvi;
// mt19937 rng; rng.seed(std::chrono::high_resolution_clock::now().time_since_epoch().count());
// template<typename T> int bins(vector<T> &v, T key) {int imin=0,imax=v.size();while(imin<imax) {int imid=(imin+imax)>>1;if (v[imid]<key) imin=imid+1;else imax=imid;}return imin;}


int ask(int x) {
	cout<<"? "<<x<<endl<<flush; cout.flush();
	string s; cin>>s;
	assert(s[0]=='N'||s[0]=='Y');
	return (s[0]=='Y')?1:0;
}
void rst() {
	cout<<"R"<<endl<<flush; cout.flush();
}
void answer(int d) {
	cout<<"! "<<d<<endl<<flush; cout.flush();
}

/*
vi que;
vi h;
int globk;
int numask=0;
int globSeed;
int ask(int p) {
	int pval=h[p];
	int ans=0;
	for (auto &y:que) if (pval==y) ans=1;
	que.PB(pval);
	if (que.size()>globk) que.erase(que.begin());
	numask++;
	//printf("Ask p:%d seen:%d\n",p,ans);
	return ans;
}

void rst() {
	//printf("Reset\n");
	que.clear();
}

void answer(int ans) {
	int n=h.size()-1;
	set<int> s; for (int i=1;i<=n;i++) s.insert(h[i]);
	if (s.size() != ans) {
		printf("Wrong answer:%d Correct ans:%d k:%d globSeed:%d\n",ans,(int)s.size(),globk,globSeed);
		for (int i=1;i<=n;i++) printf("%d ",h[i]);
		printf("end h\n");
		exit(1);
	}
	int k=globk;
	int lim=(3*n*n)/(2*k);
	if (numask>lim) {
		printf("Query limit exceeded n:%d k:%d globSeed:%d queries:%d query limit:%d\n",n,k,globSeed,numask,lim);
		for (int i=1;i<=n;i++) printf("%d ",h[i]);
		printf("end h\n");
		//exit(1);
		//exit(1);
	}
	//printf("Answered: %d correct\n\n\n",ans);
	que.clear();
	numask=0;
}
*/

vector<int> askv(vi const & v) {
	vector<int> vans;
	for (auto &x:v) {
		vans.PB(ask(x));
	}
	return vans;
}

vvi splitblocks(vi const & d, int dstep) {
	vvi blocks;
	for (int l=0;l<d.size();) {
		int r=min(l+dstep-1, ((int)d.size()) - 1);
		vi block;
		for (int i=l;i<=r;i++) {
			block.PB(d[i]);
		}
		blocks.PB(block);
		l=r+1;
	}
	return blocks;
}

const int mn=1024+64;
bitset<mn> okForNewD;

void solve(int n, int k) {
	++k;
	vi d;
	int initp=min(n,k);
	{
		vi vask;
		for (int x=1;x<=initp;x++) vask.PB(x);
		vector<int> vres=askv(vask);
		for (int i=0;i<initp;i++) {
			if (!vres[i]) {
				d.PB(vask[i]);
			}
		}
	}
	int x=initp+1;
	while(x<=n) {
		int ulim=n-x+1;
		//int u=optimize(n,k,x-1,ulim);
		//printf("n:%d k:%d before:%d ulim:%d bestU:%d\n",n,k,x-1,ulim,u);

		int u=min(k/2,ulim);

		/* New unknowns*/
		vi vu;
		for (int y=x;y<=n&&(((int)vu.size())<u);y++) {
			vu.PB(y);
		}
		if (vu.size()==0) break;

		/* U-D0-D1-U-D2-D3-U */
		okForNewD.reset();
		for (auto &p:d) okForNewD[p]=true;
		for (auto &p:vu) okForNewD[p]=true;

		int dstep=k-((int)vu.size());
		vvi blocks = splitblocks(d, dstep);

		for (int bi=0;bi<(int)blocks.size();bi+=2) {
			rst();
			if (bi+1<(int)blocks.size()) {
				
				for (auto &p:blocks[bi]) {
					bool res=ask(p);
					if (res) okForNewD[p]=false;
				}
				for (auto &p:vu) {
					bool res=ask(p);
					if (res) okForNewD[p]=false;
				}
				for (auto &p:blocks[bi+1]) {
					bool res=ask(p);
					if (res) okForNewD[p]=false;
				}
			} else {
				for (auto &p:blocks[bi]) {
					bool res=ask(p);
					if (res) okForNewD[p]=false;
				}
				for (auto &p:vu) {
					bool res=ask(p);
					if (res) okForNewD[p]=false;
				}
			}
		}
		d.clear();
		for (int p=1;p<=n;p++) {
			if (okForNewD[p]) {
				d.PB(p);
				//printf("%d ",p);
			}
		}
		//printf("End round\n");
		x=vu.back()+1;
	}
	answer((int)d.size());
}

/*void bf() {
	int logn=rand()%7;
	int logk=rand()%(logn+1);
	int n=1<<logn,k=1<<logk;
	globk=k;
	h.resize(n+1);
	for (int i=1;i<=n;i++) h[i]=i;//rand()%(2*n);
	que.clear();
	numask=0;
	solve(n,k);
}*/

int main() 
{
	int n,k; cin>>n>>k;
	solve(n,k);
	/*for (int i=0;i<1000000;i++) {
		globSeed=i;
		srand(globSeed);
		bf();
	}*/
}
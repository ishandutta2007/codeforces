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

int getTries(int n, int k, int d, int u) {
	int nd=k-u;
	int fullTries=d/nd;
	d-=fullTries*nd;
	int ans=(fullTries*k) + d + u;
	return ans;
}

int optimize(int n, int k, int d, int ulim) {
	chkmin(ulim,k-1);
	pair<double,int> bestu = MP(-1,-1);
	for (int u=1;u<=ulim;u++) {
		int t=getTries(n,k,d,u);
		double eff=u/((double)(t));
		chkmax(bestu, MP(eff,u));
	}
	return bestu.snd;
}

vector<int> askv(vi const & v) {
	rst();
	vector<int> vans;
	for (auto &x:v) {
		vans.PB(ask(x));
	}
	return vans;
}

void solve(int n, int k) {
	vi d;
	int p=min(n,k);
	{
		vi vask;
		for (int x=1;x<=p;x++) vask.PB(x);
		vector<int> vres=askv(vask);
		assert(vres.size()==p);
		assert(vask.size()==p);
		for (int i=0;i<p;i++) {
			assert(0<=i&&i<p);
			if (!vres[i]) {
				d.PB(vask[i]);
			}
		}
	}
	int x=p+1;
	while(x<=n) {
		int ulim=n-x+1;
		int u=optimize(n,k,d.size(),ulim);
		int nd=k-u;
		int dsz=d.size();
		//for (auto &y:d) printf("%d ",y);
		//printf(" end vd. x:%d u:%d nd:%d",x,u,nd);
		vector<int> vu(u);
		for (int i=0;i<u;i++) vu[i]=1;
		for (int l=0;;l+=nd) {
			int r=min(dsz-1,l+nd-1);
			vi vask;
			for (int i=l;i<=r;i++) {
				vask.PB(d[i]);
			}
			if (vask.size()==0) break;
			for (int y=x;y<x+u;y++) {
				vask.PB(y);
			}
			vector<int> vres=askv(vask);
			int sz=vres.size();
			for (int i=0;i<u;i++) {
				if (vres[i+r-l+1]) vu[i]=0;
			}
		}
		for (int i=0;i<u;i++) {
			if (vu[i]) {
				d.PB(x+i);
			}
		}
		x+=u;
	}
	answer(d.size());
}

int main() 
{
	int n,k; cin>>n>>k;
	++k;
	solve(n,k);
}
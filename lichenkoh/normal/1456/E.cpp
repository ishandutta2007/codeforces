#ifdef ONLINE_JUDGE
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,mmx,avx")
#pragma GCC optimize("Ofast")
#endif
#include "bits/stdc++.h"
#ifndef ONLINE_JUDGE
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,mmx,avx")
#pragma GCC optimize("Ofast")
#endif
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
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;typedef vector<ll> vll;typedef pair<int,int> pii;typedef vector<int> vi;typedef vector<vi> vvi;typedef vector<pii> vpii;typedef vector<pll> vpll;
template<typename T> void makeunique(vector<T> &vx) {sort(vx.begin(),vx.end());auto it=unique(vx.begin(),vx.end());vx.resize(std::distance(vx.begin(),it));}
#ifdef ONLINE_JUDGE
#define assert(...) /* nothing */
#endif
#define DEBUG_CAT
#ifdef DEBUG_CAT
#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif
int rint();char rch();long long rlong();
// mt19937 rng; rng.seed(std::chrono::high_resolution_clock::now().time_since_epoch().count());
// template<typename T> int bins(vector<T> &v, T key) {int imin=0,imax=(int)v.size();while(imin<imax) {int imid=(imin+imax)>>1;if (v[imid]<key) imin=imid+1;else imax=imid;}return imin;}
using ull=unsigned long long;

const ll INF=LLONG_MAX/4;
//const ll INF=int(1e6);
const int mn=52;
int n,klim;

ll vbound[mn][2];
ull vcost[mn];
const int FREESQ=4;
ll f[2][mn+1][mn][FREESQ+1][FREESQ+1];
//ll f[k&1][l][r][lsq][rsq];

const int SLO=0,SHI=1,SFREE=2;
int encodesq(int s, int q) {
	return (s<<1)|q;
}
int decodeS(int sq) {return sq>>1;}
int decodeQ(int sq) {return sq&1;}
int s2sign(int s) {
	return 1-2*s;
}
//Claim: For a fixed k, number of possible lstates is small. Either +0 or +1

bool isFree(int p, int s) {
	return s==SFREE||p==0||p==n+1;
}

int getBit(int p, int k, int s, int q) {
	return ((vbound[p][s]>>k)&1) ^ q;
}

ll getCost(int l, int r, int k, int ls, int lq, int rs, int rq) {
	if (isFree(l,ls)||isFree(r,rs)) return 0;
	int lb=getBit(l,k,ls,lq);
	int rb=getBit(r,k,rs,rq);
	assert(rb==0||rb==1);
	assert(lb==0||lb==1);
	return (lb^rb)*(vcost[k]);
}

int getNewQ(int p, int k, int s, int q) {
	if (s==SFREE) {
		assert(q==0);
		return 0;
	}
	ll val=vbound[p][s];
	ll newval=val+((ll(q))<<k)*s2sign(s);
	if (newval<0) return 1;
	return ((val^newval)>>(k+1))&1;
}

int getNewSq(int p, int k, int sq) {
	int s=decodeS(sq);
	int newq=getNewQ(p,k,s,decodeQ(sq));
	int newsq=encodesq(s,newq);
	assert(newsq>=0);
	return newsq;
}

bool isValidEntry(int p, int k, int s, int q) {
	if (isFree(p,s)) return true;
	ll val=vbound[p][s]+((ll(q))<<k)*s2sign(s);
	ll sig=((1LL<<k)-1);
	ll loval=val&(~sig);
	ll hival=val|sig;
	return vbound[p][0] <= loval && hival <= vbound[p][1];
}

void reset(int k) {
	k&=1;
  for (int len=2;len<=n+2;len++) {
  	for (int l=0;l<=n+1;l++) {
  		for (int lsq=0;lsq<=FREESQ;lsq++) {
  			for (int rsq=0;rsq<=FREESQ;rsq++) {
  				f[k][len][l][lsq][rsq]=INF;
  			}
  		}
  	}
  }
}

int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  cin>>n>>klim;
  for (int p=1;p<=n;p++) {
  	cin>>vbound[p][0]>>vbound[p][1];
  }
  for (int k=0;k<klim;k++) cin>>vcost[k];
	{
		const int len=2;
		const int k=klim;
		reset(k);
  	for (int r=len-1;r<=n+1;r++) {
  		int l=r-len+1;
  		// Bit klim should always be 0, thus will match lower vbound[p][0]
  		// So no need to fill in FREESQ
  		for (int ls=SLO;ls<=SHI;ls++) for (int rs=SLO;rs<=SHI;rs++) {
  			const int q=0;
  			f[k&1][len][l][encodesq(ls,q)][encodesq(rs,q)]=getCost(l,r,k,ls,q,rs,q);
  		}
  	}
  }
  // Free at bit k always implies free at bit k-1,k-2,...
  // As you grow, k should be lower, and [l,r] should be wider
  for (int k=klim-1;k>=0;k--) {
  	reset(k);
  	for (int len=2;len<=n+2;len++) {
  		for (int r=len-1;r<=n+1;r++) {
  			int l=r-len+1;
  			for (int lsq=0;lsq<=FREESQ;lsq++) for (int rsq=0;rsq<=FREESQ;rsq++) {
  				// Case 1: (l,r) are free at bit k. So make l,r interact at bit k
	  			int ls=decodeS(lsq),lq=decodeQ(lsq);
	  			int rs=decodeS(rsq),rq=decodeQ(rsq);
	  			ll ans1=INF;
	  			{
	  				// Adjust q
	  				int newlsq=getNewSq(l,k,lsq);
	  				int newrsq=getNewSq(r,k,rsq);
	  				// l,r interact at bit k, recurse on bit k+1
  					ans1=getCost(l,r,k,ls,lq,rs,rq) + f[(k+1)&1][len][l][newlsq][newrsq];
  				}

  				// Case 2: Change of state in l
  				ll ans2=INF;
  				if (lsq==FREESQ) {
  					for (int s=SLO;s<=SHI;s++) {
  						int qlo=(k==0)?0:1; // 0th bit not required to make -1 bit free
  						for (int q=qlo;q<=1;q++) {
  							if (isValidEntry(l,k,s,q)) {
  								int newlsq=encodesq(s,q);
  								ll cand=f[k&1][len][l][newlsq][rsq];
  								chkmin(ans2,cand);
  							}
  						}
  					}
  				}

  				// Case 3: Change of state in r
  				ll ans3=INF;
  				if (rsq==FREESQ) {
  					for (int s=SLO;s<=SHI;s++) {
  						int qlo=(k==0)?0:1;  // 0th bit not required to make -1 bit free
  						for (int q=qlo;q<=1;q++) {
  							if (isValidEntry(r,k,s,q)) {
  								int newrsq=encodesq(s,q);
  								ll cand=f[k&1][len][l][lsq][newrsq];
  								chkmin(ans3,cand);
  							}
  						}
  					}
  				}

  				ll ans4=INF;
  				// Case 4: There exists mid in (l,r), st mid is not free at bit k
  				for (int mid=l+1;mid<r;mid++) {
  					// mid is NOT free at k
  					// [l,r] is broken into [l,mid], [mid,r] 
  					for (int msq=0;msq<FREESQ;msq++) {
  						int ms=decodeS(msq),mq=decodeQ(msq);
  						if (isValidEntry(mid,k,ms,mq)) {
  							ll cand=f[k&1][mid-l+1][l][lsq][msq] + f[k&1][r-mid+1][mid][msq][rsq];
  							chkmin(ans4,cand);
  						}
  					}
  				}
  				ll ans=min(min(ans1,ans2),min(ans3,ans4));
  				f[k&1][len][l][lsq][rsq]=ans;
  			}
  		}
  	}
  }
  
  {
  	const int k=0,l=0,r=n+1;
  	const int len=r-l+1;
  	const int lsq=FREESQ,rsq=FREESQ;
  	ll final= f[k][len][l][lsq][rsq];
		printf("%lld\n",final);
  }
  
}
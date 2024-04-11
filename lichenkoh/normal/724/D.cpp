#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
const ll UNDEF = -1;
const ll INF=1e9;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }

#ifdef DEBUG
     #define debug(args...)            {dbg,args; cerr<<endl;}
#else
    #define debug(args...)              // Just strip off all debug tokens
#endif

struct debugger
{
    template<typename T> debugger& operator , (const T& v)
    {    
        cerr<<v<<" ";    
        return *this;    
    }
} dbg;
const ll mn=1e5+4;
const ll N = mn;  // limit for array size
ll n;  // array size
ll t[2 * N];

void build() {  // build the tree
  for (int i = n - 1; i > 0; --i) t[i] = min(t[i<<1], t[i<<1|1]);
}

void modify(int p, ll value) {  // set value at position p
  for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = min(t[p], t[p^1]);
}

int query(int l, int r) {  // sum on interval [l, r)
	chkmax(l,0);
  ll res = INF;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) chkmin(res, t[l++]);
    if (r&1) chkmin(res, t[--r]);
  }
  return res;
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll m; string a; cin>>m>>a;
	n=a.length();
	for (ll ch=0;ch<26;ch++) {
		char c='a'+ch;
		for (ll x=0;x<n;x++) t[x+n]=INF;
		t[0+n]=0;
		build();
		ll ans=INF;
		for (ll x=1;x<=n;x++) {
			char d=a[x-1];
			if (d<c) {
				ll get=query(x-m,x);
				//printf("LESS c:%c x:%lld get:%lld\n",c,x,get);
				if (x<n) modify(x,get);
				if (x+m-1>=n-1) chkmin(ans,get);
			}
			else if (d==c) {
				ll get=query(x-m,x)+1;
				//printf("EQ c:%c x:%lld get:%lld. %lld to %lld\n",c,x,get,x-m,x);
				if (x<n) modify(x,get);
				if (x+m-1>=n-1) chkmin(ans,get);
			}
		}
		//printf("%c ans:%lld\n",c,ans);
		if (ans<INF) {
			for (char d='a';d<c;d++) {
				for (ll x=0;x<n;x++) if (a[x]==d) printf("%c",d);
			}
			for (ll t=0;t<ans;t++) {
				printf("%c",c);
			}
			printf("\n");
			return 0;
		}
	}
}
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
#define fst first
#define snd second
const ll UNDEF = -1;
const ll INF=1e18;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
const int mn=3e5+2;
int a[mn];
const int ms=5002;
ll f[ms][ms];
int n,k;
ll getsum(int l, int r) {
	if (r>=n) return INF;
	return a[r]-a[l];
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	scanf("%d%d",&n,&k);
	for (int i=0;i<n;i++) scanf("%d",&a[i]);
	sort(a,a+n);
	int empty=(n/k);
	for (int seg=0;seg<=k;seg++) {
		for (int d=0;d<=seg;d++) {
			f[seg][d]=INF;
		}
	}
	f[0][0]=0;
	for (int seg=0;seg<k;seg++) {
		for (int d=0;d<=seg;d++) {
			int l=empty*seg+d;
			ll now=f[seg][d];
			if (now>=INF) continue;
			//printf("seg:%d d:%d now:%lld\n",seg,d,now);
			{
				int r=l+empty-1;
				ll add=getsum(l,r);
				if (add>=INF) continue;
				//printf("nseg:%d nd:%d l:%d r:%d add:%lld res:%lld\n",seg+1,d,l,r,add,now+add);
				chkmin(f[seg+1][d], now+add);
			}
			{
				int r=l+empty+1-1;
				ll add=getsum(l,r);
				if (add>=INF) continue;
				//printf("nseg:%d nd:%d add:%lld res:%lld\n",seg+1,d+1,add,now+add);
				chkmin(f[seg+1][d+1], now+add);
			}
		}
	}
	int full=0;
	int emp=0;
	for (int seg=0;seg<k;seg++) {
		if (1+((n-seg-1)/k)==(n/k)+1) full++;
		else emp++;
	}
	//printf("full:%d\n",full);
	ll final=f[k][full];
	printf("%lld\n",final);
}
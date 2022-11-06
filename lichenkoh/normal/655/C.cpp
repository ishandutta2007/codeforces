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
template<typename T> inline bool chkmax(T &a, T b) { return a < b ? a = b, true : false; }
template<typename T> inline bool chkmin(T &a, T b) { return a > b ? a = b, true : false; }
const ll INF=1000008;
const ll MAXN=100008;
bool a[MAXN];
vector<ll> v;
ll vsz;
/*
ll query(ll l, ll r) {
	ll ans=INF;
	ll key=(l+r)/2;
	ll imin=0,imax=vsz;
	while(imin<imax) {
		ll imid=(imin+imax)/2;
		if (v[imid]<key) {
			imin=imid+1;
		}
		else {
			imax=imid;
		}
	}
	if (0<=imin&&imin<vsz) {
		ll s=max(0LL,imin-3);
		ll e=min(vsz-1,imin+6);
		for (ll x=s;x<=e;x++) {
			ans=min(ans,max(abs(v[x]-l),abs(r-v[x])));
		}
	}
	else {
		ll s=max(0LL,vsz-6);
		ll e=vsz-1;
		for (ll x=s;x<=e;x++) {
			ans=min(ans,max(abs(v[x]-l),abs(r-v[x])));
		}
	}
	return ans;
} */



int main() {
	ios_base::sync_with_stdio(false);
	int n,k;
	cin>>n>>k;
	string s; cin>>s;
	for (ll i=0;i<n;i++) {
		a[i]=(s[i]=='0');
	}
	for (ll i=0;i<n;i++) {
		if(a[i]) v.PB(i);
	}
	vsz=v.size();
	ll l=0;
	while(!a[l]) {
		l++;
	}
	ll r=l;
	ll cnt=1;
	while(cnt<=k) {
		r++;
		cnt+=a[r];
	}
	ll ans=INF;
	ll mididx=0;
	while(r<n) {
		while(r<n&&!a[r]) {
			r++;
		}
		while(l<n&&!a[l]) {
			l++;
		}
		if(r>=n||l>=n) break;
		while(1) {
			if (mididx+1>=vsz) break;
			ll oldmid=v[mididx];
			ll oldcand=max(abs(oldmid-l),abs(r-oldmid));
			ll newmid=v[mididx+1];
			ll newcand=max(abs(newmid-l),abs(r-newmid));
			if (newcand>=oldcand) {
				ans=min(ans,oldcand);
				break;
			}
			else {
				mididx++;
				ans=min(ans,newcand);
			}
		}
		l++; r++;
	}
	cout<<ans<<endl;
}
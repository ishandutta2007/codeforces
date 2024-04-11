#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

int main(){FIN;
	ll n,k; cin>>n>>k;
	ll a[n];
	fore(i,0,n)cin>>a[i],a[i]--;
	ll res=0;
	ll u[n];
	fore(i,0,n)u[a[i]]=i;
	vector<ll> v;
	fore(i,0,k)res+=n-i,v.pb(u[n-i-1]);
	sort(ALL(v));
	ll cant=1;
	//for(auto i:v)cout<<i<<" ";
	fore(i,0,SZ(v)-1)cant*=v[i+1]-v[i],cant%=998244353;
	cout<<res<<" "<<cant;
	
	return 0;
}
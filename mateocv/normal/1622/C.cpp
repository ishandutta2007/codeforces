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

ll dv(ll a, ll b){
	if(a>=0)return a/b;
	if(a%b==0)return a/b;
	return a/b-1;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,k; cin>>n>>k;
		vector<ll> a(n);
		fore(i,0,n)cin>>a[i];
		sort(ALL(a));
		vector<ll> sump={0};
		fore(i,0,n)sump.pb(sump.back()+a[i]);
		ll res=1e18;
		res=min(res,max(0ll,sump[n]-sump[0]-k));
		fore(i,0,n){
			ll kk=k-(sump[i+1]-sump[1]);
			res=min(res,n-i-1+max(0ll,a[0]-dv(kk,n-i)));
		}
		cout<<res<<"\n";
	}
	
	return 0;
}
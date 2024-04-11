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

const int MAXN=200005;

ll a[MAXN],b[MAXN];

vector<ll> va,vb;

ll sumpa[MAXN],sumpb[MAXN];

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		fore(i,0,n)cin>>a[i];
		fore(i,0,n)cin>>b[i];
		va.clear(); vb.clear();
		fore(i,0,n){
			if(b[i]==1)va.pb(a[i]);
			else vb.pb(a[i]);
		}
		sort(ALL(va));
		reverse(ALL(va));
		sort(ALL(vb));
		reverse(ALL(vb));
		sumpa[0]=0;
		fore(i,0,SZ(va))sumpa[i+1]=sumpa[i]+va[i];
		sumpb[0]=0;
		fore(i,0,SZ(vb))sumpb[i+1]=sumpb[i]+vb[i];
		ll res=1e18;
		if(sumpa[SZ(va)]+sumpb[SZ(vb)]<m){
			cout<<"-1\n";
			continue;
		}
		fore(i,0,SZ(va)+1){
			ll f=m-sumpa[i];
			ll pos=lower_bound(sumpb,sumpb+SZ(vb)+1,f)-sumpb;
			if(pos<SZ(vb)+1)res=min(res,2*pos+i);
		}
		cout<<res<<"\n";
	}
	
	return 0;
}
#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

int main(){FIN;
	ll n,m; cin>>n>>m;
	vector<ll> a(n),b(m);
	fore(i,0,n)cin>>a[i];
	fore(i,0,m)cin>>b[i];
	sort(ALL(b));
	vector<ll> d(n,1e18);
	fore(i,0,n){
		auto pos=lower_bound(ALL(b),100ll*i)-b.begin();
		if(pos<m)d[i]=min(d[i],abs(100ll*i-b[pos]));
		if(pos-1>=0)d[i]=min(d[i],abs(100ll*i-b[pos-1]));
	}
	vector<ll> sump={0};
	for(auto i:a)sump.pb(sump.back()+i);
	ll res=0;
	ll l=0,r=-1;
	while(r<n){
		if(l>r||d[l]+d[r]>100ll*(r-l)){
			if(l<=r)res=max(res,sump[r+1]-sump[l]);
			r++;
		}else{
			l++;
		}
	}
	cout<<res<<"\n";
	
	return 0;
}
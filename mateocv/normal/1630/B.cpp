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

vector<ll> oc[MAXN];

ll n,k;

vector<ll> a;

pair<bool,pair<ll,ll>> can(ll m){
	//cout<<"can "<<m<<"\n";
	ll sum=0;
	fore(i,0,m)sum+=SZ(oc[i]);
	//cout<<sum<<"\n";
	ll ul=m-1;
	while(1){
		//cout<<"s "<<sum-k<<" "<<n-sum<<"\n";
		if(sum-k>=n-sum){
			//cout<<"1\n";
			return {1,{ul-m+1,ul}};
		}
		ul++;
		if(ul==n)break;
		sum+=SZ(oc[ul]);
		sum-=SZ(oc[ul-m]);
	}
	//cout<<"0\n";
	return {0,{-1,-1}};
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n>>k;
		a.clear();
		a.resize(n);
		fore(i,0,n)cin>>a[i],a[i]--;
		fore(i,0,n)oc[i].clear();
		fore(i,0,n)oc[a[i]].pb(i);
		//cout<<"s\n";
		//fore(i,0,n)cout<<SZ(oc[i])<<" ";
		//cout<<"\n";
		ll l=1,r=n;
		while(l<=r){
			ll m=(l+r)/2;
			auto c=can(m);
			if(c.fst)r=m-1;
			else l=m+1;
		}
		auto ran=can(l).snd;
		//assert(can(l).fst);
		cout<<ran.fst+1<<" "<<ran.snd+1<<"\n";
		vector<pair<ll,ll>> res;
		ll c[2]={0,0};
		ll ul=0;
		fore(i,0,n){
			if(ran.fst<=a[i]&&a[i]<=ran.snd)c[1]++;
			else c[0]++;
			if(c[1]>c[0]){
				if(SZ(res)==k-1){
					res.pb({ul,n-1});
					break;
				}
				res.pb({ul,i});
				ul=i+1;
				c[0]=0;
				c[1]=0;
			}
		}
		for(auto i:res)cout<<i.fst+1<<" "<<i.snd+1<<"\n";
	}
	
	return 0;
}
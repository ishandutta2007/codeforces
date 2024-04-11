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

ll solve(vector<ll> v){
	map<ll,ll> mp;
	ll s=0,res=0;
	for(auto i:v){
		s+=i;
		mp[s]++;
		res=max(res,mp[s]);
	}
	//cout<<"sol ";
	//for(auto i:v)cout<<i<<" ";
	//cout<<": "<<res<<"\n";
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<ll> a(n);
		fore(i,0,n)cin>>a[i];
		ll res=0;
		vector<ll> v;
		while(SZ(a)){
			v.pb(a.back());
			a.pop_back();
			if(v.back()==0){
				reverse(ALL(v));
				res+=solve(v);
				v.clear();
			}
		}
		reverse(ALL(v));
		ll s=0;
		for(auto i:v){
			s+=i;
			res+=(s==0);
		}
		cout<<res<<"\n";
	}
	
	return 0;
}
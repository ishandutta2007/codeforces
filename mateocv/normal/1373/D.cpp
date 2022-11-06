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
	ll res=0,va=0;
	for(auto i:v){
		va=max(i,i+va);
		res=max(res,va);
	}
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		ll a[n];
		fore(i,0,n)cin>>a[i];
		ll sum=0;
		fore(i,0,n){
			if(i%2==0)sum+=a[i];
		}
		vector<ll> v[2];
		fore(i,0,n){
			if(i%2==0&&i>0){
				v[0].pb(a[i-1]-a[i]);
			}else if(i%2==1){
				v[1].pb(a[i]-a[i-1]);
			}
		}
		/*
		fore(k,0,2){
			for(auto i:v[k])cout<<i<<" ";
			cout<<"\n";
		}
		*/
		cout<<sum+max(solve(v[0]),solve(v[1]))<<"\n";
	}
	
	return 0;
}
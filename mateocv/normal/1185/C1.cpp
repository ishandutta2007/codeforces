#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

int main(){FIN;
	ll n,m; cin>>n>>m;
	ll a[n];
	fore(i,0,n)cin>>a[i];
	vector<ll> v;
	fore(i,0,n){
		ll t=a[i];
		if(i==0){
			cout<<"0 "; continue;
		}
		v.pb(a[i-1]);
		sort(ALL(v));
		reverse(ALL(v));
		ll sum=t;
		fore(i,0,SZ(v))sum+=v[i];
		ll res=0;
		while(sum>m){
			sum-=v[res];
			res++;
		}
		cout<<res<<" ";
	}
	
	return 0;
}
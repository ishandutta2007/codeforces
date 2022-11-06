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
	ll t; cin>>t;
	while(t--){
		ll n,x; cin>>n>>x;
		vector<ll> a(n);
		fore(i,0,n)cin>>a[i];
		ll sum=0;
		for(auto i:a)sum+=i;
		if(sum==x)cout<<"NO\n";
		else{
			cout<<"YES\n";
			ll s=0;
			fore(i,0,n){
				s+=a[i];
				if(s==x){
					swap(a[i],a[i+1]);
					break;
				}
			}
			for(auto i:a)cout<<i<<" ";
			cout<<"\n";
		}
	}
	
	return 0;
}
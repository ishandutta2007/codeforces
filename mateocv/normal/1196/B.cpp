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
	ll q; cin>>q;
	while(q--){
		ll n,k; cin>>n>>k;
		ll a[n];
		fore(i,0,n)cin>>a[i];
		ll sum=0;
		ll tot=0;
		vector<ll> v;
		fore(i,0,n){
			sum+=a[i];
			if(a[i]&1){
				tot++;
				sum=0;
				v.pb(i);
				if(tot==k)break;
			}
		}
		if(tot!=k)cout<<"NO\n";
		else{
			fore(i,v.back()+1,n)sum+=a[i];
			if(sum&1)cout<<"NO\n";
			else{
				cout<<"YES\n";
				v.pop_back(); v.pb(n-1);
				fore(i,0,SZ(v))cout<<v[i]+1<<" ";
				cout<<"\n";
			}
		}
	}
	
	return 0;
}
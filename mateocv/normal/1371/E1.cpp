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
	ll n,p; cin>>n>>p;
	ll a[n];
	fore(i,0,n)cin>>a[i];
	sort(a,a+n);
	ll res[2020];
	mset(res,0);
	fore(i,1,2001){
		res[i]=1;
		ll pos=0;
		fore(j,0,n){
			while(pos<n&&a[pos]<=i+j){
				pos++;
			}
			res[i]=(res[i]*max(pos-j,0ll))%p;
		}
	}
	//fore(i,0,20)cout<<res[i]<<" "; cout<<"\n";
	vector<ll> ref;
	fore(i,0,2020){
		if(res[i])ref.pb(i);
	}
	cout<<SZ(ref)<<"\n";
	for(auto i:ref)cout<<i<<" ";
	
	return 0;
}
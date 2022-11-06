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
	ll n,k; cin>>n>>k;
	vector<ll> a(n);
	fore(i,0,n)cin>>a[i];
	vector<ll> op(n);
	ll vaop=0,vas=0,res=0;
	for(ll i=n-1;i>=k;i--){
		vas-=op[i]*(k-1);
		vaop-=op[i];
		vas+=vaop;
		a[i]-=vaop*k-vas;
		ll c=max(0ll,(a[i]+k-1)/k);
		op[i-k]+=c;
		vaop+=c;
		res+=c;
	}
	//cout<<res<<"\n";
	ll maxi=0;
	for(ll i=k-1;i>=0;i--){
		vas-=op[i]*(k-1);
		vaop-=op[i];
		vas+=vaop;
		a[i]-=vaop*k-vas;
		maxi=max(maxi,(a[i]+i)/(i+1));
		//cout<<a[i]<<" "<<maxi<<"\n";
	}
	//cout<<res<<" "<<maxi<<"\n";
	res+=maxi;
	//cout<<res<<" "<<maxi<<"\n";
	cout<<res<<"\n";
	
	return 0;
}
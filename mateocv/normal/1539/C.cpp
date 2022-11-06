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
	ll n,k,x; cin>>n>>k>>x;
	vector<ll> a(n);
	fore(i,0,n)cin>>a[i];
	sort(ALL(a));
	vector<ll> v;
	fore(i,0,n-1){
		if(a[i]!=a[i+1])v.pb((a[i+1]-a[i]+x-1)/x-1);
		else v.pb(0);
	}
	sort(ALL(v));
	reverse(ALL(v));
	//for(auto i:v)cout<<i<<" ";
	//cout<<"\n";
	ll res=n;
	while(SZ(v)&&v.back()<=k){
		auto b=v.back();
		v.pop_back();
		k-=b;
		res--;
	}
	cout<<res<<"\n";
	
	return 0;
}
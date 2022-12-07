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
		ll a,b,d; cin>>a>>b>>d;
		ll aa=a,bb=b,dd=d;
		ll c=0;
		while(a%2==0&&b%2==0&&d%2==0){
			c++;
			a/=2;
			b/=2;
			d/=2;
		}
		if(d%2==0){
			cout<<"-1\n";
			continue;
		}
		auto d2=((d+1)/2);
		ll x=((-(a|b))%d+d)%d;
		fore(i,0,30)x=x*d2%d;
		//cout<<x<<"\n";
		ll res=(((x<<30)+(a|b))<<c);
		assert((aa|res)%dd==0);
		assert((bb|res)%dd==0);
		cout<<res<<"\n";
	}
	
	return 0;
}
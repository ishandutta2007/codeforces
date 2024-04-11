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

ll p[200005];

ll can(ll x, ll y, ll cant1, ll cant2, ll cant3){
	if(x>y)swap(x,y),swap(cant1,cant2);
	ll sum=0;
	fore(i,0,cant3){
		sum+=(p[i]/100)*(x+y);
	}
	fore(i,cant3,cant3+cant2){
		sum+=(p[i]/100)*(y);
	}
	fore(i,cant3+cant2,cant3+cant2+cant1){
		sum+=(p[i]/100)*(x);
	}
	//cout<<sum<<"\n";
	return sum;
}

int main(){FIN;
	ll q; cin>>q;
	while(q--){
		ll n; cin>>n;
		fore(i,0,n)cin>>p[i];
		ll x,a,y,b; cin>>x>>a>>y>>b;
		ll k; cin>>k;
		sort(p,p+n);
		reverse(p,p+n);
		ll g=__gcd(a,b);
		ll l=0,r=n;
		//if(can(x,y,m/a-m/(a*b),m/b-m/(a*b),m/(a*b))<k)
		while(l <= r) {
			ll m = (l+r)/2;
			//vector<ll> v;
			//fore(i,0,m)v.pb(a[i]);
			//cout<<m<<" : ";
			if (m<=n&&can(x,y,m/a-m/(a*b/g),m/b-m/(a*b/g),m/(a*b/g))>=k) r=m-1;
			else l=m+1;
		}
		if(l==n+1) cout<<-1<<"\n";
		else cout<<l<<"\n";
	}
	return 0;
}
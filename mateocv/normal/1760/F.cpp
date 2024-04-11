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
		ll n,c,d; cin>>n>>c>>d;
		vector<ll> a(n);
		fore(i,0,n)cin>>a[i];
		sort(ALL(a));
		reverse(ALL(a));
		if(d*a[0]<c){
			cout<<"Impossible\n";
			continue;
		}
		ll sp=0;
		fore(i,0,min(n,d))sp+=a[i];
		if(sp>=c){
			cout<<"Infinity\n";
			continue;
		}
		ll l=0,r=d;
		while(l<=r){
			ll m=(l+r)/2;
			ll pos=0;
			ll ne=m+1;
			ll va=0;
			fore(i,0,d){
				if(i==ne){
					pos=0;
					ne+=m+1;
				}
				if(pos<n)va+=a[pos];
				pos++;
			}
			if(va>=c)l=m+1;
			else r=m-1;
		}
		cout<<r<<"\n";
	}
	
	return 0;
}
#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

ll sq=100,c=1000;

ll getm(vector<ll> v){
	ll res=0;
	ll ul=-1e18,va=0;
	for(auto i:v){
		if(i==ul)va++;
		else{
			ul=i;
			va=1;
		}
		res=max(res,va);
	}
	return res;
}

int main(){FIN;
	ll n; cin>>n;
	vector<ll> a(n);
	fore(i,0,n)cin>>a[i];
	ll res=n-1;
	fore(d,-sq,sq+1){
		vector<ll> b;
		fore(i,0,SZ(a))b.pb(a[i]-i*d);
		sort(ALL(b));
		res=min(res,n-getm(b));
	}
	fore(i,0,n){
		vector<ll> b;
		fore(j,-c,c+1){
			if(j&&i+j>=0&&i+j<n){
				ll dif=(a[i+j]-a[i])/j;
				if(dif*j==a[i+j]-a[i])b.pb(dif);
			}
		}
		sort(ALL(b));
		res=min(res,n-getm(b)-1);
	}
	cout<<res<<"\n";
	
	return 0;
}
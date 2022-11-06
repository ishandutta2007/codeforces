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

ll INF=1e9;

ll ask(ll x){
	cout<<"? "<<x<<endl;
	ll resp; cin>>resp;
	if(resp==0)resp=INF;
	return resp;
}

int main(){FIN;
	ll n; cin>>n;
	ll l=1,r=2022ll*n;
	while(l<=r){
		ll m=(l+r)/2;
		if(ask(m)==1)r=m-1;
		else l=m+1;
	}
	ll res=l;
	fore(k,2,n+1){
		res=min(res,(l/k)*ask(l/k));
	}
	cout<<"! "<<res<<endl;
	
	return 0;
}
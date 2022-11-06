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

ll maxd(ll n){
	ll res=-1;
	while(n>0){
		res=max(res,n%10);
		n/=10;
	}
	return res;
}

ll mind(ll n){
	ll res=10;
	while(n>0){
		res=min(res,n%10);
		n/=10;
	}
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll a,k; cin>>a>>k;
		k--;
		while(k--){
			if(a%10==0||mind(a)==0)break;
			a=a+maxd(a)*mind(a);
		}
		cout<<a<<"\n";
	}
	
	return 0;
}
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

ll n;
ll a[3030];

ll getnpos(ll pos, ll val){
	ll s=0;
	fore(i,pos,n){
		s+=a[i];
		if(s==val)return i+1;
		if(s>val)return -1;
	}
	return -1;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n;
		fore(i,0,n)cin>>a[i];
		ll s=0;
		ll res=n-1;
		fore(i,0,n){
			s+=a[i];
			ll tot=0,va=0;
			while(va!=n&&va!=-1){
				va=getnpos(va,s);
				tot++;
			}
			if(va==n){
				res=min(res,n-tot);
			}
		}
		cout<<res<<"\n";
	}
	
	return 0;
}
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

ll cant(ll n, ll k){
	ll res=0;
	while(n%k==0){
		res++;
		n/=k;
	}
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,x; cin>>n>>x;
		ll a[n];
		fore(i,0,n)cin>>a[i];
		ll c[n];
		fore(i,0,n){
			c[i]=cant(a[i],x);
		}
		ll res=0;
		fore(i,0,n)res+=a[i];
		while(1){
			ll br=0;
			fore(i,0,n){
				if(c[i])res+=a[i],c[i]--;
				else{
					br++; break;
				}
			}
			if(br)break;
		}
		cout<<res<<"\n";
	}
	
	return 0;
}
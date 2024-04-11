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

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<ll> a(n);
		fore(i,0,n)cin>>a[i];
		ll res=0;
		ll l=n,r=-1,c=0;
		fore(i,0,n){
			if(a[i]!=0){
				l=min(l,i);
				r=max(r,i);
				c++;
			}
		}
		if(c==0)res=0;
		else if(c==n||r-l+1==c)res=1;
		else res=2;
		cout<<res<<"\n";
	}
	
	return 0;
}
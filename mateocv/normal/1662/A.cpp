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
		ll n; cin>>n;
		vector<ll> a(10);
		fore(i,0,n){
			ll x,y; cin>>x>>y; 
			swap(x,y);
			x--;
			a[x]=max(a[x],y);
		}
		ll res=0,br=0;
		fore(i,0,10){
			if(a[i])res+=a[i];
			else br++;
		}
		if(br)cout<<"MOREPROBLEMS\n";
		else cout<<res<<"\n";
	}
	
	return 0;
}
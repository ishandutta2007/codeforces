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
		vector<ll> a(n);
		fore(i,0,n)cin>>a[i];
		pair<ll,ll> mini={a[0],a[1]};
		pair<ll,ll> van={1,1};
		pair<ll,ll> sum=mini;
		ll res=n*mini.fst+n*mini.snd;
		fore(i,2,n){
			if(i&1){
				van.snd++;
				mini.snd=min(mini.snd,a[i]);
				sum.snd+=a[i];
			}else{
				van.fst++;
				mini.fst=min(mini.fst,a[i]);
				sum.fst+=a[i];
			}
			res=min(res,sum.fst+(n-van.fst)*mini.fst+sum.snd+(n-van.snd)*mini.snd);
		}
		cout<<res<<"\n";
	}
	
	return 0;
}
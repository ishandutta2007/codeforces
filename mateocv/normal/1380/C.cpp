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
		ll n,x; cin>>n>>x;
		ll a[n];
		fore(i,0,n)cin>>a[i];
		vector<ll> v;
		fore(i,0,n)v.pb(a[i]);
		sort(ALL(v));
		ll res=0,qued=0,va=1;
		while(SZ(v)){
			if(va>n)break;
			if(va*v.back()>=x&&qued>=va-1){
				res++; qued-=va-1;
				v.pop_back();
			}else if(va*v.back()>=x){
				qued++;
				v.pop_back();
			}else{
				va++;
			}
		}
		cout<<res<<"\n";
	}
	
	return 0;
}
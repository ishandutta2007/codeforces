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
	vector<ll> fib={1,1};
	while(fib.back()<=100000000000ll)fib.pb(fib[SZ(fib)-2]+fib[SZ(fib)-1]);
	vector<ll> sp=fib;
	fore(i,1,SZ(fib))sp[i]+=sp[i-1];
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<ll> a(n);
		fore(i,0,n)cin>>a[i];
		ll s=0;
		for(auto i:a)s+=i;
		ll pos=-1;
		fore(i,0,SZ(sp)){
			if(sp[i]==s)pos=i;
		}
		if(pos==-1){
			cout<<"NO\n";
			continue;
		}
		ll ul=-1;
		vector<pair<ll,ll>> ap;
		fore(i,0,n)ap.pb({a[i],i});
		ll res=1;
		while(pos>=0){
			sort(ALL(ap));
			reverse(ALL(ap));
			ll br=0;
			fore(i,0,n){
				if(ap[i].fst>=fib[pos]&&ul!=ap[i].snd){
					ap[i].fst-=fib[pos];
					ul=ap[i].snd;
					br++;
					break;
				}
			}
			pos--;
			if(!br){
				res=0;
				break;
			}
		}
		if(!res)cout<<"NO\n";
		else cout<<"yes\n";
	}
	
	return 0;
}
#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

ll cr(vector<ll> v){
	ll res=0;
	sort(ALL(v));
	while(SZ(v)>=2){
		auto b=v.back();
		v.pop_back();
		if(b==v.back()){
			res++;
			v.pop_back();
		}
	}
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,l,r; cin>>n>>l>>r;
		vector<ll> a(l),b(r);
		fore(i,0,l)cin>>a[i];
		fore(i,0,r)cin>>b[i];
		sort(ALL(a));
		sort(ALL(b));
		vector<ll> aa,bb;
		while(SZ(a)||SZ(b)){
			if(!SZ(a)){
				bb.pb(b.back());
				b.pop_back();
			}else if(!SZ(b)){
				aa.pb(a.back());
				a.pop_back();
			}else if(a.back()==b.back()){
				a.pop_back();
				b.pop_back();
			}else if(a.back()>b.back()){
				aa.pb(a.back());
				a.pop_back();
			}else{
				bb.pb(b.back());
				b.pop_back();
			}
		}
		if(SZ(aa)>SZ(bb))swap(aa,bb);
		ll ca=min(cr(bb),(SZ(bb)-SZ(aa))/2);
		cout<<SZ(bb)-ca<<"\n";
	}
	
	return 0;
}
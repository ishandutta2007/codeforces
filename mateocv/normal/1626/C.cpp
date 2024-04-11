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
		vector<ll> a(n),b(n);
		fore(i,0,n)cin>>a[i];
		fore(i,0,n)cin>>b[i];
		vector<pair<ll,ll>> v;
		fore(i,0,n)v.pb({a[i]-b[i]+1,a[i]});
		sort(ALL(v));
		//for(auto i:v)cout<<i.fst<<" "<<i.snd<<"\n";
		ll res=0;
		vector<ll> vr;
		pair<ll,ll> ul={0,-1};
		for(auto i:v){
			if(i.fst<=ul.snd){
				ul.snd=max(ul.snd,i.snd);
			}else{
				vr.pb(ul.snd-ul.fst+1);
				ul=i;
			}
		}
		vr.pb(ul.snd-ul.fst+1);
		for(auto i:vr)res+=i*(i+1)/2;
		cout<<res<<"\n";
	}
	
	return 0;
}
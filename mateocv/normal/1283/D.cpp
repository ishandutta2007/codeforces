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
	ll n,m; cin>>n>>m;
	ll a[n];
	fore(i,0,n)cin>>a[i];
	sort(a,a+n);
	vector<pair<ll,pair<ll,ll>>> v;
	fore(i,0,n-1){
		v.pb({(a[i+1]-a[i]-1)/2,{a[i],1}});
		v.pb({(a[i+1]-a[i])/2,{a[i+1],-1}});
	}
	v.pb({1e6,{a[0],-1}}); v.pb({1e6,{a[n-1],1}});
	sort(ALL(v));
	reverse(ALL(v));
	//for(auto i:v)cout<<i.fst<<" "<<i.snd.fst<<" "<<i.snd.snd<<"\n";
	ll tot=0;
	ll res=0;
	vector<ll> pos;
	fore(i,1,1000000){
		while(v.back().fst==0)v.pop_back();
		if(tot==m)break;
		fore(j,0,SZ(v)){
			if(tot==m)break;
			res+=i;
			pos.pb(v[j].snd.fst+v[j].snd.snd*i);
			tot++;
			v[j].fst--;	
		}
	}
	cout<<res<<"\n";
	for(auto i:pos)cout<<i<<" ";
	
	return 0;
}
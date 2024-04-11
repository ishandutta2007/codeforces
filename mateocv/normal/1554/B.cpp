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

pair<ll,ll> max2(pair<ll,ll> a, pair<ll,ll> b){
	vector<ll> v={a.fst,a.snd,b.fst,b.snd};
	sort(ALL(v));
	while(v[SZ(v)-1]==v[SZ(v)-2])v.pop_back();
	return {v[SZ(v)-1],v[SZ(v)-2]};
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,k; cin>>n>>k;
		vector<ll> a(n);
		fore(i,0,n)cin>>a[i];
		vector<pair<ll,ll>> vp(2*n);
		fore(i,0,2*n)vp[i]={-1,-2};
		fore(i,0,n){
			vp[a[i]]=max2(vp[a[i]],{i+1,-1});
		}
		ll res=-1e18;
		fore(i,0,2*n){
			fore(j,0,20){
				if((1ll<<j)&i){
					vp[i]=max2(vp[i],vp[i^(1ll<<j)]);
				}
			}
			if(vp[i].fst>=0&&vp[i].snd>=0)res=max(res,vp[i].fst*vp[i].snd-k*i);
		}
		cout<<res<<"\n";
	}
	
	return 0;
}
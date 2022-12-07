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
		vector<ll> sump[2];
		fore(k,0,2){
			sump[k]={0};
			for(auto i:a){
				sump[k].pb(sump[k].back()+(i==k));
			}
		}
		ll c1=0,ci=0;
		for(auto i:a){
			if(i==1)c1++;
			else ci+=c1;
		}
		ll res=ci;
		fore(i,0,n){
			if(a[i]==0){
				res=max(res,ci-sump[1][i]+(sump[0].back()-sump[0][i+1]));
			}else{
				res=max(res,ci+sump[1][i]-(sump[0].back()-sump[0][i+1]));
			}
		}
		cout<<res<<"\n";
	}
	
	return 0;
}
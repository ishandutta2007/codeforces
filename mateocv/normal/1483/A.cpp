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

vector<vector<ll>> vv;

ll c[100005];

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		vv.clear();
		vv.resize(m);
		fore(i,0,m){
			ll k; cin>>k;
			vector<ll> v(k);
			fore(j,0,k)cin>>v[j],v[j]--;
			vv[i]=v;
		}
		vector<ll> res(m);
		fore(i,0,m)res[i]=vv[i][0];
		fore(i,0,n)c[i]=0;
		for(auto i:res)c[i]++;
		ll val=-1,cant=0;
		fore(i,0,n){
			if(c[i]>(m+1)/2){
				val=i;
				cant=c[i]-(m+1)/2;
			}
		}
		fore(i,0,m){
			if(cant>0&&res[i]==val&&SZ(vv[i])>1){
				res[i]=vv[i][1];
				cant--;
			}
		}
		if(cant)cout<<"NO\n";
		else{
			cout<<"YES\n";
			for(auto i:res)cout<<i+1<<" ";
			cout<<"\n";
		}
	}
	
	return 0;
}
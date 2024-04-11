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

const ll MOD=998244353;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,k; cin>>n>>k;
		vector<ll> a(n);
		fore(i,0,n)cin>>a[i];
		ll res=1;
		fore(i,n-k,n){
			if(a[i]>0)res=0;
			else if(a[i]==-1)a[i]=0;
		}
		//if(!res)cout<<res<<"\n";
		fore(i,0,n-k){
			if(a[i]==0){
				res=res*(k+1)%MOD;
			}
			if(a[i]==-1){
				res=res*(k+i+1)%MOD;
			}
		}
		fore(i,0,k){
			res=res*(i+1)%MOD;
		}
		cout<<res<<"\n";
	}
	
	return 0;
}
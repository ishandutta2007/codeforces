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
		ll n,m; cin>>n>>m;
		if(m<n||((n%2==0)&&(m%2==1)))cout<<"NO\n";
		else{
			cout<<"YES\n";
			vector<ll> res(n,1);
			m-=n;
			if(n&1)res.back()+=m;
			else{
				res[n-1]+=m/2;
				res[n-2]+=m/2;
			}
			for(auto i:res)cout<<i<<" ";
			cout<<"\n";
		}
	}
	
	return 0;
}
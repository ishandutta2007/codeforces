#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

int main(){FIN;
	ll n,q; cin>>n>>q;
	deque<ll>d;
	ll lle;
	fore(i,0,n)cin>>lle,d.pb(lle);
	ll maxi=-1;
	fore(i,0,n){
		maxi=max(maxi,d[i]);
	}
	vector<pair<ll,ll>> res;
	while(d[0]!=maxi){
		res.pb({d[0],d[1]});
		ll a=d[0]; d.pop_front();
		ll b=d[0]; d.pop_front();
		d.push_front(max(a,b));
		d.pb(min(a,b));
	}
	while(q--){
		ll m; cin>>m;
		if(m<=SZ(res)){
			cout<<res[m-1].fst<<" "<<res[m-1].snd<<"\n";
		}else{
			m--;
			m-=SZ(res);
			m%=n-1;
			cout<<d[0]<<" "<<d[1+m]<<"\n";
		}
	}
	
	
	return 0;
}
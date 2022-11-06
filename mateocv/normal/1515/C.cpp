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
		ll n,m,x; cin>>n>>m>>x;
		vector<ll> a(n);
		fore(i,0,n)cin>>a[i];		
		priority_queue<pair<ll,ll>> pq;
		vector<ll> res(n);
		fore(i,0,m)pq.push({0,i});
		fore(i,0,n){
			auto f=pq.top();
			pq.pop();
			res[i]=f.snd;
			pq.push({f.fst-a[i],f.snd});
		}
		cout<<"YES\n";
		for(auto i:res)cout<<i+1<<" ";
		cout<<"\n";
	}
	
	return 0;
}
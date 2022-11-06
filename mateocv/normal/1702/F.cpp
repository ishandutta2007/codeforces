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
		fore(i,0,n){
			while(a[i]%2==0)a[i]/=2;
		}
		map<ll,ll> mp;
		for(auto i:a)mp[i]++;
		priority_queue<ll> pq;
		for(auto i:b)pq.push(i);
		ll br=0;
		while(SZ(pq)){
			auto f=pq.top(); pq.pop();
			if(mp.count(f)){
				mp[f]--;
				if(mp[f]==0)mp.erase(f);
			}else{
				if(f==1)br++;
				else pq.push(f/2);
			}
		}
		if(br)cout<<"NO\n";
		else cout<<"YES\n";
	}
	
	return 0;
}
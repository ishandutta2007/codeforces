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
		sort(ALL(a));
		vector<ll> c(n+1);
		for(auto i:a)c[i]++;
		ll ul=0;
		priority_queue<ll> pq;
		vector<ll> res;
		ll va=0;
		fore(i,0,n+1){
			while(ul<n&&a[ul]<i){
				pq.push(a[ul]);
				ul++;
			}
			if(ul<i)break;
			if(i){
				assert(SZ(pq));
				auto t=pq.top();
				pq.pop();
				va+=i-1-t;
			}
			res.pb(va+c[i]);
		}
		while(SZ(res)<n+1)res.pb(-1);
		for(auto i:res)cout<<i<<" ";
		cout<<"\n";
	}
	
	return 0;
}
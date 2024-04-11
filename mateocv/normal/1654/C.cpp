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
		reverse(ALL(a));
		ll s=0;
		for(auto i:a)s+=i;
		ll ul=0;
		priority_queue<ll> pq;
		pq.push(s);
		ll tot=0;
		while(1){
			auto f=pq.top(); pq.pop();
			if(a[ul]==f){
				ul++;
				if(ul==n)break;
			}else if(a[ul]>f){
				break;
			}else{
				pq.push(f/2);
				pq.push((f+1)/2);
				tot++;
				if(tot==n)break;
			}
		}
		if(ul==n&&SZ(pq)==0)cout<<"YES\n";
		else cout<<"NO\n";
	}
	
	return 0;
}
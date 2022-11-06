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
		ll n,m,k; cin>>n>>m>>k;
		vector<ll> a(k);
		fore(i,0,k)cin>>a[i];
		priority_queue<ll> pq;
		ll res=1,va=k;
		for(auto i:a){
			if(va==i){
				va--;
				while(SZ(pq)&&pq.top()==va){
					va--;
					pq.pop();
				}
			}else{
				pq.push(i);
				if(SZ(pq)==n*m-3){
					res=0;
					break;
				}
			}
		}
		if(res)cout<<"YA\n";
		else cout<<"TIDAK\n";
	}
	
	return 0;
}
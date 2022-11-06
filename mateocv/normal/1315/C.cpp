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
		ll b[n];
		fore(i,0,n)cin>>b[i];
		set<ll> s;
		fore(i,0,2*n)s.insert(i+1);
		ll br=0;
		fore(i,0,n){
			if(!s.count(b[i])){
				cout<<-1<<"\n"; br++; break;
			}else{
				s.erase(b[i]);
			}
		}
		if(br)continue;
		ll res[2*n];
		fore(i,0,n){
			res[2*i]=b[i];
			auto it=s.lower_bound(b[i]);
			if(it==s.end()){
				cout<<-1<<"\n"; br++; break;
			}else{
				res[2*i+1]=*it;
				s.erase(it);
			}
		}
		if(br)continue;
		fore(i,0,2*n)cout<<res[i]<<" "; cout<<"\n";
	}
	
	return 0;
}
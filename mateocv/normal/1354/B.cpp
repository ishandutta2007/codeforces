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
		string s; cin>>s;
		vector<ll> u[3];
		fore(i,0,SZ(s)){
			u[s[i]-'1'].pb(i);
		}
		ll br=0;
		fore(i,0,3){
			if(SZ(u[i])==0){
				cout<<0<<"\n";
				br++; break;
			}
		}
		if(br)continue;
		ll res=SZ(s)+1;
		fore(i,0,SZ(s)-1){
			if(s[i]!=s[i+1]){
				ll f=3-(s[i]-'1')-(s[i+1]-'1');
				auto it=lower_bound(ALL(u[f]),i);
				if(it!=u[f].end()){
					res=min(res,*it-i+1);
				}
			}
		}
		assert(res<SZ(s)+1);
		cout<<res<<"\n";
	}
	return 0;
}
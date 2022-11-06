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
		vector<pair<ll,ll>> sump={{0,0}};
		fore(i,0,SZ(s)){
			auto b=sump.back();
			if(s[i]!='?'){
				if((i&1)==s[i]-'0')b.fst++;
				else b.snd++;
			}
			sump.pb(b);
		}
		ll res=0;
		fore(i,0,SZ(s)){
			ll l=i+1,r=SZ(s);
			while(l<=r){
				ll m=(l+r)/2;
				pair<ll,ll> c={sump[m].fst-sump[i].fst,sump[m].snd-sump[i].snd};
				if(c.fst==0||c.snd==0)l=m+1;
				else r=m-1;
			}
			res+=r-i;
		}
		cout<<res<<"\n";
	}
	
	return 0;
}
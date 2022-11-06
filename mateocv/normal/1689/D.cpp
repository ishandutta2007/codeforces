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

pair<ll,ll> oper(pair<ll,ll> a, pair<ll,ll> b){
	return {min(a.fst,b.fst),max(a.snd,b.snd)};
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		vector<string> s(n);
		fore(i,0,n)cin>>s[i];
		pair<ll,pair<ll,ll>> mini={1e9,{-1,-1}};
		pair<ll,ll> su={1e9,-1e9},re={1e9,-1e9};
		fore(i,0,n){
			fore(j,0,m){
				if(s[i][j]=='B'){
					su=oper(su,{i+j,i+j});
					re=oper(re,{i-j,i-j});
				}
			}
		}
		//cout<<su.fst<<" "<<su.snd<<"\n";
		//cout<<re.fst<<" "<<re.snd<<"\n";
		fore(i,0,n){
			fore(j,0,m){
				ll val=0;
				val=max(val,su.snd-(i+j));
				val=max(val,(i+j)-su.fst);
				val=max(val,re.snd-(i-j));
				val=max(val,(i-j)-re.fst);
				mini=min(mini,{val,{i,j}});
			}
		}
		cout<<mini.snd.fst+1<<" "<<mini.snd.snd+1<<"\n";
	}
	
	return 0;
}
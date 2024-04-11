#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,a,b,c; cin>>n>>a>>b>>c;
		string s; cin>>s;
		string RPS="RPS";
		vector<ll> v[3];
		fore(k,0,3){
			fore(i,0,SZ(s)){
				if(s[i]==RPS[k])v[k].pb(i);
			}
		}
		if(min(a,SZ(v[2]))+min(b,SZ(v[0]))+min(c,SZ(v[1]))>=(n+1)/2){
			cout<<"YES\n";
			string res=s;
			while(SZ(v[2])&&a){
				res[v[2].back()]='R';
				a--;
				v[2].pop_back();
			}
			while(SZ(v[0])&&b){
				res[v[0].back()]='P';
				b--;
				v[0].pop_back();
			}
			while(SZ(v[1])&&c){
				res[v[1].back()]='S';
				c--;
				v[1].pop_back();
			}
			fore(k,0,3){
				while(SZ(v[k])){
					if(a>0){
						res[v[k].back()]='R';
						a--;
					}else if(b>0){
						res[v[k].back()]='P';
						b--;
					}else if(c>0){
						res[v[k].back()]='S';
						c--;
					}
					v[k].pop_back();
				}
			}
			cout<<res<<"\n";
		}else{
			cout<<"NO\n";
		}
	}
	
	return 0;
}
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
		fore(i,0,SZ(s)){
			if(s[i]==')')s[i]='(';
			if(s[i]==']')s[i]='[';
		}
		string pr="([";
		vector<ll> sump[2][2];
		fore(ii,0,2){
			fore(jj,0,2){
				sump[ii][jj].pb(0);
			}
		}
		//cout<<"HOLA"<<endl;
		fore(i,0,SZ(s)){
			fore(ii,0,2){
				fore(jj,0,2){
					sump[ii][jj].pb(sump[ii][jj].back()+(s[i]==pr[ii]&&(i&1)==jj));
				}
			}
		}
		ll q; cin>>q;
		while(q--){
			ll l,r; cin>>l>>r; l--;
			ll c[2][2];
			fore(ii,0,2){
				fore(jj,0,2){
					c[ii][jj]=sump[ii][jj][r]-sump[ii][jj][l];
				}
			}
			cout<<max(c[0][0],c[0][1])-min(c[0][0],c[0][1])<<"\n";
		}
	}
	
	return 0;
}
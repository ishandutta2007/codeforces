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
		ll n,k; cin>>n>>k;
		string s; cin>>s;
		char ss[SZ(s)];
		fore(i,0,SZ(s)){
			ss[i]=s[i];
		}
		string t;
		fore(i,0,k-1){
			t+="()";
		}
		fore(i,0,n/2-k+1){
			t+='(';
		}
		fore(i,0,n/2-k+1){
			t+=')';
		}
		vector<pair<ll,ll>> res;
		fore(i,0,n/2){
			if(ss[i]!=t[i]&&ss[n-1-i]!=t[n-1-i]&&ss[i]==t[n-1-i]&&t[i]==ss[n-1-i]){
				res.pb({i,n-i-1}); reverse(ss+i,ss+n-i); 
				//fore(i,0,SZ(s))cout<<ss[i]; cout<<"\n";
			}
			if(ss[i]!=t[i]){
				fore(j,i+1,n-1-i){
					if(ss[j]==t[i]){
						res.pb({i,j}); reverse(ss+i,ss+j+1);
						//fore(i,0,SZ(s))cout<<ss[i]; cout<<"\n";
						break;
					}
				}
			}
			if(ss[n-1-i]!=t[n-1-i]){
				fore(j,i+1,n-1-i){
					if(ss[j]==t[n-1-i]){
						res.pb({j,n-1-i}); reverse(ss+j,ss+n-i); 
						//fore(i,0,SZ(s))cout<<ss[i]; cout<<"\n";
						break;
					}
				}
			}
		}
		//cout<<t<<" ";
		//fore(i,0,SZ(s))cout<<ss[i]; cout<<"\n";
		cout<<SZ(res)<<"\n";
		for(auto i:res)cout<<i.fst+1<<" "<<i.snd+1<<"\n";
	}
	
	return 0;
}
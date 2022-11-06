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

vector<ll> s,ss;

int main(){FIN;
	ll n,m; cin>>n>>m;
	if(n>=4&&m>=4){
		cout<<-1;
		return 0;
	}
	char c[min(n,m)][max(n,m)];
	if(n<=m){
		fore(i,0,n){
			fore(j,0,m){
				cin>>c[i][j];
			}
		}
	}else{
		fore(i,0,n){
			fore(j,0,m){
				cin>>c[j][i];
			}
		}
	}
	if(n>=m)swap(n,m);
	if(n==1){
		cout<<0;
		return 0;
	}
	if(n==2){
		fore(i,0,m){
			s.pb((c[0][i]-'0'+c[1][i]-'0')&1);
		}
		ll res=m;
		ll va=0;
		fore(i,0,m){
			if(s[i]%2!=i%2)va++;
		}
		res=min(res,va);
		va=0;
		fore(i,0,m){
			if(s[i]%2==i%2)va++;
		}
		res=min(res,va);
		cout<<res<<"\n";
		return 0;
	}
	if(n==3){
		fore(i,0,m){
			s.pb((c[0][i]-'0'+c[1][i]-'0')&1);
		}
		fore(i,0,m){
			ss.pb((c[1][i]-'0'+c[2][i]-'0')&1);
		}
		ll res=m;
		ll va=0;
		
		va=0;
		fore(i,0,m){
			if(s[i]%2!=i%2||ss[i]%2!=i%2)va++;
		}
		res=min(res,va);
		
		va=0;
		fore(i,0,m){
			if(s[i]%2!=i%2||ss[i]%2==i%2)va++;
		}
		res=min(res,va);
		
		va=0;
		fore(i,0,m){
			if(s[i]%2==i%2||ss[i]%2!=i%2)va++;
		}
		res=min(res,va);
		
		va=0;
		fore(i,0,m){
			if(s[i]%2==i%2||ss[i]%2==i%2)va++;
		}
		res=min(res,va);
		
		cout<<res<<"\n";
		return 0;
	}
	
	return 0;
}
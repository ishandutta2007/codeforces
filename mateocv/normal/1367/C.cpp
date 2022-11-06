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
		vector<ll> u;
		fore(i,0,SZ(s)){
			if(s[i]=='1')u.pb(i);
		}
		ll res=0;
		if(SZ(u)==0){
			res=(n+k)/(k+1);
		}else{
			res=u[0]/(k+1)+(n-1-u.back())/(k+1);
			fore(i,0,SZ(u)-1)res+=(u[i+1]-u[i]-1-k)/(k+1);
		}
		cout<<res<<"\n";
	}
	
	return 0;
}
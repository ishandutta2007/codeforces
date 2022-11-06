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
		string res;
		for(ll k=9;k>=0;k--){
			ll c=0;
			while(SZ(s)&&s.back()=='0'+k){
				s.pop_back();
				c++;
			}
			string ns;
			for(auto i:s){
				if(i=='0'+k){
					res.pb('0'+min(9ll,k+1));
				}else ns.pb(i);
			}
			s=ns;
			fore(_,0,c)res.pb('0'+k);
		}
		reverse(ALL(res));
		cout<<res<<"\n";
	}
	
	return 0;
}
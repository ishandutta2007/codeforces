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
		string s; cin>>s;
		ll u=0,z=0;
		while(SZ(s)&&s.back()=='1'){
			s.pop_back(); u++;
		}
		reverse(ALL(s));
		while(SZ(s)&&s.back()=='0'){
			s.pop_back(); z++;
		}
		fore(i,0,z)cout<<0;
		if(SZ(s)!=0)cout<<0;
		fore(i,0,u)cout<<1;
		cout<<"\n";
		
	}
	
	return 0;
}
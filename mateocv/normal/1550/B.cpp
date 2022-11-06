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
		ll n,a,b; cin>>n>>a>>b;
		string s; cin>>s;
		ll va=1;
		fore(i,1,SZ(s)){
			va+=(s[i]!=s[i-1]);
		}
		ll res=max(n*(a+b),n*a+b*(va/2+1));
		cout<<res<<"\n";
	}
	
	return 0;
}
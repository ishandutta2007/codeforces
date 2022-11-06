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
		string a,s; cin>>a>>s;
		vector<ll> ub(26);
		fore(i,0,SZ(a))ub[a[i]-'a']=i;
		ll res=0;
		fore(i,0,SZ(s)-1)res+=abs(ub[s[i]-'a']-ub[s[i+1]-'a']);
		cout<<res<<"\n";
	}
	
	return 0;
}
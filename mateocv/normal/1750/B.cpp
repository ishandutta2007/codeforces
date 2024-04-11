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
		ll c[2]={0,0};
		for(auto i:s)c[i-'0']++;
		ll res=c[0]*c[1];
		ll va=0;
		fore(i,0,n){
			if(i&&s[i]==s[i-1])va++;
			else va=1;
			res=max(res,va*va);
		}
		cout<<res<<"\n";
	}
	
	return 0;
}
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
		ll res=1;
		ll n=SZ(s);
		fore(i,0,SZ(s)){
			if((i-1<0||s[i-1]!=s[i])&&(i+1>=n||s[i+1]!=s[i]))res=0;
		}
		if(res)cout<<"YES\n";
		else cout<<"NO\n";
	}
	
	return 0;
}
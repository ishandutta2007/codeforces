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
		ll res=10;
		fore(i,0,n-1){
			if(s[i]=='a'&&s[i+1]=='a')res=min(res,2ll);
		}
		fore(i,0,n-2){
			if(s[i]=='a'&&s[i+2]=='a')res=min(res,3ll);
		}
		fore(i,0,n-3){
			if(s[i]=='a'&&s[i+3]=='a'&&s[i+1]!=s[i+2])res=min(res,4ll);
		}
		fore(i,0,n-6){
			if(s[i]=='a'&&s[i+3]=='a'&&s[i+6]=='a'){
				string t;
				t+=s[i+1];
				t+=s[i+2];
				t+=s[i+4];
				t+=s[i+5];
				sort(ALL(t));
				if(t=="bbcc")res=min(res,7ll);
			}
		}
		if(res==10)cout<<"-1\n";
		else cout<<res<<"\n";
	}
	
	return 0;
}
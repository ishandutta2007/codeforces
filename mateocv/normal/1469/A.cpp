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
		if(SZ(s)&1){
			cout<<"No\n";
			continue;
		}
		ll l=-1,r=-1;
		fore(i,0,SZ(s)){
			if(s[i]=='(')l=i;
			if(s[i]==')')r=i;
		}
		if(r!=0&&l!=SZ(s)-1)cout<<"Yes\n";
		else cout<<"No\n";
	}
	
	return 0;
}
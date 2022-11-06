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
		ll pos=-1;
		fore(i,0,SZ(s)-1){
			if(s[i]-'0'+s[i+1]-'0'>=10)pos=i;
		}
		if(pos==-1)pos=0;
		fore(i,0,pos)cout<<s[i];
		cout<<ll(s[pos]+s[pos+1]-'0'-'0');
		fore(i,pos+2,SZ(s))cout<<s[i];
		cout<<"\n";
	}
	
	return 0;
}
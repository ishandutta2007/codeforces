#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
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
		ll zl=SZ(s),zr=-1,c=0;
		fore(i,0,SZ(s)){
			if(s[i]=='0'){
				zl=min(zl,i);
				zr=max(zr,i);
				c++;
			}
		}
		if(zr==-1)cout<<"0\n";
		else if(zr-zl+1==c)cout<<"1\n";
		else cout<<"2\n";
	}
	
	return 0;
}
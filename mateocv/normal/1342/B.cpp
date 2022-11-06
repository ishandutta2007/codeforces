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
		ll tot=0;
		fore(i,0,SZ(s)){
			tot+=(s[i]==s[0]);
		}
		if(tot==SZ(s)){
			cout<<s<<s<<"\n";
		}else{
			fore(i,0,SZ(s))cout<<"01";
			cout<<"\n";
		}
	}
	
	return 0;
}
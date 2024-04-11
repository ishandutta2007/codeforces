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
		ll st=-1;
		fore(i,0,n){
			if(s[i]=='A'){
				st=i; break;
			}
		}
		if(st==-1){
			cout<<0<<"\n"; continue;
		}
		ll va=0,res=0;
		fore(i,st,n){
			if(s[i]=='P')va++;
			else{
				va=0;
			}
			res=max(res,va);
		}
		cout<<res<<"\n";
	}
	
	return 0;
}
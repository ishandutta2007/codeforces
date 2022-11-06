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
		ll a,b,p; cin>>a>>b>>p;
		string s; cin>>s;
		ll res=SZ(s)-1,tot=0;
		fore(i,0,SZ(s)-1){
			if(i==0){
				if(s[SZ(s)-2]=='A'){
					tot+=a;
				}else{
					tot+=b;
				}
				if(tot<=p){
					res=SZ(s)-2-i;
				}else break;
			}else{
				if(s[SZ(s)-2-i]==s[SZ(s)-1-i]){
					res=SZ(s)-2-i; continue;
				}
				if(s[SZ(s)-2-i]=='A'){
					tot+=a;
				}else{
					tot+=b;
				}
				if(tot<=p){
					res=SZ(s)-2-i;
				}else break;
			}
		}
		cout<<res+1<<"\n";
	}
	
	return 0;
}
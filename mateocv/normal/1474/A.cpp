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
		ll va=-1;
		fore(i,0,SZ(s)){
			if(s[i]=='0'){
				if(va!=1){
					cout<<"1";
					va=1;
				}else{
					cout<<"0";
					va=0;
				}
			}else{
				if(va!=2){
					cout<<"1";
					va=2;
				}else{
					cout<<"0";
					va=1;
				}
			}
		}
		cout<<"\n";
	}
	
	return 0;
}
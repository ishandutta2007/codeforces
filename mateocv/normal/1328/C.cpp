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
		string a,b;
		ll ya=0;
		fore(i,0,n){
			if(!ya){
				if(s[i]=='2'){
					a+='1'; b+='1';
				}else if(s[i]=='0'){
					a+='0'; b+='0';
				}else if(s[i]=='1'){
					a+='1'; b+='0'; ya++;
				}
			}else{
				a+='0'; b+=s[i];
			}
		}
		cout<<a<<"\n"<<b<<"\n";
	}
	
	return 0;
}
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
		ll cant[10];
		mset(cant,0);
		fore(i,0,SZ(s)){
			cant[s[i]-'0']++;
		}
		ll res=SZ(s);
		fore(i,0,10)res=min(res,SZ(s)-cant[i]);
		fore(i,0,10){
			fore(j,0,10){
				ll a=0,b=0;
				fore(ii,0,SZ(s)){
					if(a==b){
						a+=(s[ii]=='0'+i);
					}else{
						b+=(s[ii]=='0'+j);
					}
				}
				res=min(res,SZ(s)-2*b);
			}
		}
		cout<<res<<"\n";
	}
	
	return 0;
}
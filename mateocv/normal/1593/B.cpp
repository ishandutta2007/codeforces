#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		string s; cin>>s;
		vector<string> vr={"25","50","75","00"};
		ll res=1e18;
		fore(i,0,SZ(s)){
			fore(j,i+1,SZ(s)){
				fore(k,0,SZ(vr)){
					string t;
					t+=s[i];
					t+=s[j];
					if(t==vr[k]){
						res=min(res,SZ(s)-i-2);
					}
				}
			}
		}
		cout<<res<<"\n";
	}
	
	return 0;
}
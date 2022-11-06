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
		string s,abc; cin>>s>>abc;
		vector<ll> c(26);
		for(auto i:s)c[i-'a']++;
		string res;
		if(abc=="abc"){
			fore(i,0,26){
				ll pos=i;
				if(c[0])if(pos==1||pos==2)pos^=1^2;
				fore(j,0,c[pos])res+='a'+pos;
			}
		}else{
			fore(i,0,26){
				fore(j,0,c[i])res+='a'+i;
			}
		}
		cout<<res<<"\n";
	}
	
	return 0;
}
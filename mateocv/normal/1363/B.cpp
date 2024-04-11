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
		ll res=SZ(s);
		ll c[2]={0,0};
		fore(i,0,SZ(s)){
			c[s[i]-'0']++;
		}
		fore(i,0,SZ(s)){
			if(s[i]=='0')c[1]++;
			else c[1]--;
			res=min(res,c[1]);
		}
		fore(i,0,SZ(s)){
			if(s[i]=='1')c[0]++;
			else c[0]--;
			res=min(res,c[0]);
		}
		cout<<res<<"\n";
	}
	
	return 0;
}
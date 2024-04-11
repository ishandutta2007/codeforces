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
		string res;
		ll pos=SZ(s)-1;
		while(pos>=0){
			if(s[pos]=='0'){
				res.pb('a'+(10*(s[pos-2]-'0')+s[pos-1]-'0'-1));
				pos-=3;
			}else{
				res.pb('a'+s[pos]-'1');
				pos--;
			}
		}
		reverse(ALL(res));
		cout<<res<<"\n";
	}
	
	return 0;
}
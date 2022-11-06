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
		vector<string> s(8);
		fore(i,0,8)cin>>s[i];
		ll br=0;
		fore(i,0,8){
			ll c=0;
			fore(j,0,8){
				c+=(s[i][j]=='R');
			}
			if(c==8)br=1;
		}
		if(br)cout<<"R\n";
		else cout<<"B\n";
	}
	
	return 0;
}
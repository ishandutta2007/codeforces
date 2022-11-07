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
		string s,ss; cin>>s>>ss;
		ll br=0;
		fore(i,0,SZ(s)){
			fore(j,i,SZ(s)){
				string sn;
				fore(ii,i,j+1)sn+=s[ii];
				for(ll ii=j-1;ii>=0;ii--)sn+=s[ii];
				while(SZ(sn)>SZ(ss))sn.pop_back();
				if(sn==ss)br++;
			}
		}
		if(br)cout<<"YES\n";
		else cout<<"NO\n";
	}
	
	return 0;
}
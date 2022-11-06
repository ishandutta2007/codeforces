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

set<ll> g[30];
ll vis[30];

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		mset(vis,0);
		fore(i,0,30)g[i].clear();
		string s; cin>>s;
		if(SZ(s)==1){
			cout<<"YES\n";
			fore(i,0,26)cout<<(char)('a'+i);
			cout<<"\n";
			continue;
		}
		//cout<<"ACAAAAAAAAAAAAAAAAAAA"<<endl;
		fore(i,0,SZ(s)-1){
			g[s[i]-'a'].insert(s[i+1]-'a');
			g[s[i+1]-'a'].insert(s[i]-'a');
		}
		ll br=0,c=0,st=-1;
		fore(i,0,26){
			if(SZ(g[i])>=3){
				cout<<"NO\n"; br++; break;
			}else if(SZ(g[i])==1){
				c++; st=i;
			}
		}
		if(br)continue;
		if(c!=2){
			cout<<"NO\n"; continue;
		}
		string res;
		while(1){
			res+=st+'a';
			vis[st]=1;
			if(SZ(g[st])==1){
				if(br)break;
				else br++;
			}
			ll sig=0;
			for(auto j:g[st]){
				sig+=j;
			}
			if(SZ(g[st])>=2){
				sig-=res[SZ(res)-2]-'a';
			}
			st=sig;
		}
		fore(i,0,26){
			if(!vis[i])res+='a'+i;
		}
		
		cout<<"YES\n"<<res<<"\n";
	}
	
	return 0;
}
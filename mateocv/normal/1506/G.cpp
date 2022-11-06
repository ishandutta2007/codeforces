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

string s;

ll suf[200005];

vector<ll> oc[30];

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>s;
		fore(i,0,26)oc[i].clear();
		fore(i,0,SZ(s))oc[s[i]-'a'].pb(i);
		fore(i,0,26)reverse(ALL(oc[i]));
		ll mk=0;
		fore(i,0,SZ(s)){
			ll pot=(1ll<<(s[i]-'a'));
			suf[i]=pot;
			mk|=pot;
		}
		for(int i=SZ(s)-2;i>=0;i--){
			suf[i]=(suf[i]|suf[i+1]);
		}
		string res;
		ll va=0;
		while(mk){
			//cout<<(bitset<26>)mk<<" "<<va<<" "<<res<<"\n";
			for(int i=25;i>=0;i--){
				if((1ll<<i)&mk){
					//cout<<i<<" "<<char('a'+i)<<":\n";
					while(SZ(oc[i])&&oc[i].back()<va)oc[i].pop_back();
					assert(SZ(oc[i]));
					ll b=oc[i].back();
					ll q=suf[b];
					//cout<<b<<" "<<(bitset<26>)q<<"\n";
					if((q&mk)==mk){
						mk^=(1ll<<i);
						res.pb('a'+i);
						va=b+1;
						break;
					}
				}
			}
		}
		cout<<res<<"\n";
	}
	
	return 0;
}
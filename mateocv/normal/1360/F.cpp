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

ll nmatch(string &s, string &t){
	assert(SZ(s)==SZ(t));
	ll res=0;
	fore(i,0,SZ(s)){
		res+=(s[i]!=t[i]);
	}
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		string s[n];
		fore(i,0,n)cin>>s[i];
		vector<string> t;
		fore(i,0,m){
			fore(j,0,26){
				string r=s[0];
				r[i]='a'+j;
				t.pb(r);
			}
		}
		ll br=0;
		for(auto i:t){
			ll tot=0;
			fore(j,0,n){
				tot+=(nmatch(i,s[j])<=1);
			}
			if(tot==n){
				cout<<i<<"\n";
				br++; break;
			}
		}
		if(br)continue;
		cout<<"-1\n";
	}
	
	return 0;
}
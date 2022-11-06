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
	ll q; cin>>q;
	while(q--){
		string s,t; cin>>s>>t;
		ll br=0;
		fore(i,0,SZ(s)){
			fore(j,0,SZ(t)){
				if(s[i]==t[j]){
					cout<<"YES\n"; br++; break;
				}
			}
			if(br)break;
		}
		if(br)continue;
		cout<<"NO\n";
	}
	
	return 0;
}
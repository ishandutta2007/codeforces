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
		ll n,k; cin>>n>>k;
		string s; cin>>s;
		set<char> st;
		fore(i,0,n){
			while(s[i]!='a'&&(k||st.count(s[i]))){
				if(!st.count(s[i])){
					st.insert(s[i]); k--;
				}
				s[i]--;
			}
		}
		cout<<s<<"\n";
	}
	
	return 0;
}
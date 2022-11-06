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

string cuatro(ll n){
	string s="0000";
	ll p=3;
	while(n>0){
		s[p]+=n%10;
		p--; n/=10;
	}
	return s;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		ll s[n];
		fore(i,0,n)cin>>s[i];
		set<ll> st;
		fore(i,0,10)st.insert(i);
		fore(i,0,n){
			if(st.count(s[i]%10))st.erase(s[i]%10);
		}
		ll res=0;
		fore(i,0,n){
			fore(j,0,i){
				if(s[i]==s[j]){
					s[i]-=(s[i]%10);
					s[i]+=*st.begin();
					res++;
					st.erase(s[i]%10);
				}
			}
		}
		cout<<res<<"\n";
		fore(i,0,n)cout<<cuatro(s[i])<<"\n";
	}
	
	return 0;
}
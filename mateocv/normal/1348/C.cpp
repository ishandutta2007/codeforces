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
 
string solve1(string s, ll k){
	ll tot=0;
	for(auto i:s)tot+=(i==s[0]);
	string res;
	if(tot==SZ(s)){
		fore(i,0,(tot+k-1)/k)res.pb(s[0]);
		return res;
	}
	return s;
}
 
string solve0(string s, ll k){
	ll tot=0;
	for(auto i:s)tot+=(i==s[0]);
	string res;
	if(tot<k){
		res+=s[k-1];
		return res;
	}
	if(tot==SZ(s)){
		fore(i,0,(tot+k-1)/k)res.pb(s[0]);
		return res;
	}
	fore(i,k,SZ(s))res.pb(s[i]);
	string t;
	t+=s[k-1];
	return t+solve1(res,k);	
}
 
 
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,k; cin>>n>>k;
		string s; cin>>s;
		sort(ALL(s));
		cout<<solve0(s,k)<<"\n";
	}
	
	return 0;
}
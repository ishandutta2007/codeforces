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
		if(k&1){
			fore(i,0,n)s[i]=(s[i]^'0'^'1');
		}
		vector<ll> res(n);
		fore(i,0,n-1){
			if(s[i]=='0'&&k){
				s[i]='1';
				res[i]++;
				k--;
			}
		}
		res[n-1]=k;
		if(k&1)s[n-1]=(s[n-1]^'0'^'1');
		cout<<s<<"\n";
		for(auto i:res)cout<<i<<" ";
		cout<<"\n";
	}
	
	return 0;
}
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
		ll n; cin>>n;
		string s; cin>>s;
		ll c=0;
		for(auto i:s)c+=(i=='1');
		if(c&1){
			cout<<"-1\n";
			continue;
		}
		vector<ll> v;
		fore(i,0,n){
			if(s[2*i]!=s[2*i+1])v.pb(i);
		}
		//cout<<"v\n";
		//for(auto i:v)cout<<i<<" ";
		//cout<<"\n";
		vector<ll> res;
		fore(i,0,SZ(v)){
			ll val='0'+(i&1);
			res.pb((s[2*v[i]]==val?2*v[i]:2*v[i]+1));
		}
		cout<<SZ(res)<<" ";
		for(auto i:res)cout<<i+1<<" ";
		cout<<"\n";
		fore(i,0,n)cout<<2*i+1<<" ";
		cout<<"\n";
	}
	
	return 0;
}
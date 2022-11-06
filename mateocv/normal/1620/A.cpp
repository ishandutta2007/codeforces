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
		string s; cin>>s;
		ll n=SZ(s);
		ll cant=0;
		for(auto i:s)cant+=(i=='N');
		if(cant==1)cout<<"NO\n";
		else cout<<"YES\n";
		/*
		vector<ll> res(n);
		res[0]=1;
		fore(i,1,n){
			if(s[i-1]=='E')res[i]=res[i-1];
			else res[i]=res[i-1]+1;
		}
		if(res.back()=='E'){
			fore(i,0,n){
				if(res[i]==res.back())res[i]=res[0];
			}
		}
		for(auto i:res)cout<<i<<" ";
		cout<<"\n";
		*/
	}
	
	return 0;
}
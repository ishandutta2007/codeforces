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
		ll n,m; cin>>n>>m;
		string a,b; cin>>a>>b;
		ll res=0;
		if(n==m){
			res=(a==b);
		}else{
			ll c[2]={0,0};
			fore(i,0,n-m+1)c[a[i]-'0']++;
			res=1;
			if(c[b[0]-'0']==0)res=0;
			if(a.substr(n-m+1,m-1)!=b.substr(1,m-1))res=0;
		}
		if(res)cout<<"YES\n";
		else cout<<"NO\n";
	}
	
	return 0;
}
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
		vector<ll> a(n),b(n);
		fore(i,0,n)cin>>a[i];
		fore(i,0,n)cin>>b[i];
		ll c[2]={0,0};
		fore(i,0,n){
			if(a[i]!=b[i])c[a[i]]++;
		}
		ll res=0;
		if(c[0]&&c[1])res=abs(c[0]-c[1])+1;
		else res=c[0]+c[1];
		cout<<res<<"\n";
	}
	
	return 0;
}
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

ll solv(vector<ll> v){
	fore(i,0,SZ(v)-1){
		if(abs(v[i]-v[i+1])>1)return 1;
	}
	return 0;
}

ll eq(vector<ll> v){
	fore(i,0,SZ(v)){
		if(v[i]!=v[0])return 0;
	}
	return 1;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,u,v; cin>>n>>u>>v;
		vector<ll> a(n);
		fore(i,0,n)cin>>a[i];
		if(solv(a)){
			cout<<"0\n";
		}else if(eq(a)){
			cout<<v+min(u,v)<<"\n";
		}else{
			cout<<min(u,v)<<"\n";
		}
	}
	
	return 0;
}
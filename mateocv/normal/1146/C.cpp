#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

ll ask(ll n,ll b){
	vector<ll> v[2];
	fore(i,1,n+1){
		if(i&(1<<b)){
			v[0].pb(i);
		}else{
			v[1].pb(i);
		}
	}
	if(SZ(v[0])&&SZ(v[1])){
		cout<<SZ(v[0])<<" "<<SZ(v[1])<<" ";
		fore(i,0,SZ(v[0]))cout<<v[0][i]<<" ";
		fore(i,0,SZ(v[1]))cout<<v[1][i]<<" ";
		cout<<endl;
		ll resp; cin>>resp; 
		if(resp==-1)assert(0);
		return resp;
	}else{
		return 0;
	}
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		ll res=0;
		fore(i,0,9){
			res=max(res,ask(n,i));
		}
		cout<<"-1 "<<res<<endl;
	}
	
	return 0;
}
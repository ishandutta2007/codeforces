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

ll ceros(ll n){
	ll res=0;
	while(n%2==0){
		res++; n/=2;
	}
	return res;
}

int main(){FIN;
	ll n; cin>>n;
	ll a[n];
	fore(i,0,n)cin>>a[i];
	vector<ll> v[62];
	fore(i,0,n){
		ll c=ceros(a[i]);
		v[c].pb(a[i]);
	}
	ll maxi=0,maxid=-1;
	fore(i,0,62){
		if(SZ(v[i])>maxi){
			maxi=SZ(v[i]);
			maxid=i;
		}
	}
	/*fore(i,0,3){
		for(auto j:v[i])cout<<j<<" ";
		cout<<"\n";
	}*/
	//cout<<ceros(2)<<"\n";
	cout<<n-maxi<<"\n";
	fore(i,0,62){
		if(i!=maxid){
			fore(j,0,SZ(v[i]))cout<<v[i][j]<<" ";
		}
	}
	
	return 0;
}
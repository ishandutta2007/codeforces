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

ll tom3(ll n){
	return n*(n-1)*(n-2)/6;
}

ll tom2(ll n){
	return n*(n-1)/2;
}

int main(){FIN;
	ll n; cin>>n;
	vector<pair<ll,ll>> v(n);
	fore(i,0,n)cin>>v[i].fst>>v[i].snd;
	fore(i,0,n){
		v[i].fst/=2;
		v[i].snd/=2;
	}
	ll c[2][2];
	mset(c,0);
	for(auto i:v){
		c[i.fst&1][i.snd&1]++;
	}
	ll res=0;
	fore(i,0,2){
		fore(j,0,2){
			res+=tom3(c[i][j]);
			res+=tom2(c[i][j])*(n-c[i][j]);
		}
	}
	cout<<res<<"\n";
	
	return 0;
}
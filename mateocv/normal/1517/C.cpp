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

vector<ll> fil(vector<ll> v, ll x){
	vector<ll> res;
	for(auto i:v){
		if(i>=x)res.pb(i);
	}
	return res;
}

ll res[505][505];

int main(){FIN;
	ll n; cin>>n;
	vector<ll> a(n);
	fore(i,0,n)cin>>a[i];
	vector<vector<ll>> resr;
	fore(i,0,n)resr.pb(fil(a,n-i));
	fore(i,0,SZ(resr)){
		fore(j,0,SZ(resr[i])){
			res[n-1-i+j][j]=resr[i][j];
		}
	}
	fore(i,0,n){
		fore(j,0,i+1){
			cout<<res[i][j]<<" ";
		}
		cout<<"\n";
	}
	
	return 0;
}
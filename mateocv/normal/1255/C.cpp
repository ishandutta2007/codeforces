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

map<pair<ll,ll>,vector<ll>> mp;
ll a[100005][3];

ll next(ll x, ll y, ll z){
    //cout<<"Entro con "<<x<<" "<<y<<" "<<z<<endl;
	vector<ll> v=mp[{min(y,z),max(y,z)}];
	ll s[2]={0,0};
	fore(k,0,2){
		fore(j,0,3)s[k]+=a[v[k]][j];
		if(s[k]-y-z!=x)return s[k]-y-z; 
	}
}

int main(){FIN;
	ll n; cin>>n;
	fore(i,0,n-2)cin>>a[i][0]>>a[i][1]>>a[i][2];
	ll c[n+1];
	mset(c,0);
	fore(i,0,n-2){
		fore(k,0,3){
			c[a[i][k]]++;
			mp[{min(a[i][k],a[i][(k+1)%3]),max(a[i][k],a[i][(k+1)%3])}].pb(i);
		}
	}
	vector<ll> u,d;
	fore(i,1,n+1){
		if(c[i]==1)u.pb(i);
		if(c[i]==2)d.pb(i);
	}
	vector<ll>res;
	ll x=-1,y=u[0],z;
	res.pb(u[0]);
	if(mp.count({min(u[0],d[0]),max(u[0],d[0])})){
		res.pb(d[0]);
		z=d[0];
	}else{
		res.pb(d[1]);
		z=d[1];
	}
	while(SZ(res)<n){
		res.pb(next(x,y,z));
		x=y;
		y=z;
		z=res.back();
	}
	for(auto i:res)cout<<i<<" ";
	return 0;
}
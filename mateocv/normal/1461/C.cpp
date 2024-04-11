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

const int MAXN=100005;

ll a[MAXN],b[MAXN],c[MAXN];

vector<pair<ll,double>> v;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		fore(i,0,n)cin>>a[i];
		v.clear();
		fore(i,0,m){
			ll x; cin>>x; //x--;
			double y; cin>>y;
			v.pb({x,y});
		}
		v.pb({0,1.}); m++;
		fore(i,0,n)b[i]=a[i];
		sort(b,b+n);
		fore(i,0,n)c[i]=0;
		c[n]=1;
		for(int i=n-1;i>=0;i--){
			c[i]=(c[i+1]&&a[i]==b[i]);
		}
		double res=1.;
		fore(i,0,m){
			if(c[v[i].fst]){
				res*=1.-v[i].snd;
			}
		}
		cout<<fixed<<setprecision(10)<<1.-res<<"\n";
	}
	
	return 0;
}
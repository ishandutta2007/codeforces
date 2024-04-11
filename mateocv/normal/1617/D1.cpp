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

ll ask(ll a, ll b, ll c){
	cout<<"? "<<a+1<<" "<<b+1<<" "<<c+1<<endl;
	ll resp; cin>>resp;
	if(resp==-1)exit(0);
	return resp;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<ll> a(n);
		fore(i,0,n)a[i]=ask(i,(i+1)%n,(i+2)%n);
		ll x=-1,y=-1;
		fore(i,0,n){
			if(a[i]!=a[(i+1)%n]){
				x=(i+1)%n,y=(i+2)%n;
			}
		}
		vector<ll> c(n);
		ll xx=-1,yy=-1;
		fore(i,0,n){
			if(i!=x&&i!=y){
				c[i]=ask(x,y,i);
				if(c[i])xx=i;
				if(!c[i])yy=i;
			}
		}
		c[x]=ask(xx,yy,x);
		c[y]=ask(xx,yy,y);
		vector<ll> res;
		fore(i,0,n){
			if(!c[i])res.pb(i);
		}
		cout<<"! "<<SZ(res)<<" ";
		for(auto i:res)cout<<i+1<<" ";
		cout<<endl;
	}
	
	return 0;
}
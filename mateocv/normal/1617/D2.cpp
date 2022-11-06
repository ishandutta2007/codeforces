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
		vector<ll> g(n/3);
		fore(i,0,n/3)g[i]=ask(3*i,3*i+1,3*i+2);
		ll gx=-1,gy=-1;
		fore(i,0,n/3){
			if(g[i])gx=i;
			if(!g[i])gy=i;
		}
		assert(gx!=-1&&gy!=-1);
		vector<ll> v={3*gx,3*gx+1,3*gx+2,3*gy,3*gy+1,3*gy+2};
		ll l=ask(v[1],v[2],v[3]);
		ll r=ask(v[2],v[3],v[4]);
		vector<ll> c(n);
		ll x=-1,y=-1;
		if(l==0)x=v[0],y=v[3];
		else if(r==0)x=v[1],y=v[4];
		else x=v[2],y=v[5];
		assert(x!=-1&&y!=-1);
		c[x]=1;
		c[y]=0;
		for(auto i:v){
			if(i!=x&&i!=y){
				c[i]=ask(x,y,i);
			}
		}
		fore(i,0,n/3){
			if(i!=gx&&i!=gy){
				if(g[i]){
					ll a=ask(y,3*i,3*i+1);
					if(a){
						c[3*i]=1;
						c[3*i+1]=1;
						c[3*i+2]=ask(x,y,3*i+2);
					}else{
						c[3*i]=ask(x,y,3*i);
						c[3*i+1]=1-c[3*i];
						c[3*i+2]=1;
					}
				}else{
					ll a=ask(x,3*i,3*i+1);
					if(a){
						c[3*i]=ask(x,y,3*i);
						c[3*i+1]=1-c[3*i];
						c[3*i+2]=0;
					}else{
						c[3*i]=0;
						c[3*i+1]=0;
						c[3*i+2]=ask(x,y,3*i+2);
					}
				}
			}
		}
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
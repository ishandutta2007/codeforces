#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

ll res=0;
vector<pair<ll,ll>> v;
ll n;
ll p[300005];
ll u[300005];

void chang(ll a, ll b){
	u[p[a]]=b;
	u[p[b]]=a;
	swap(p[a],p[b]);
	res++;
	v.pb({a,b});
}

int main(){FIN;
	cin>>n;
	fore(i,1,n+1)cin>>p[i];
	fore(i,1,n+1){
		u[p[i]]=i;
	}
	fore(i,0,n/2){
		if(i==n/2-1){
			if(p[1]!=1){
				chang(1,n);
			}
			break;
		}
		if(u[n/2-i]>n/2){
			chang(u[n/2-i],1);
		}
		chang(u[n/2-i],n);
		chang(n,n/2-i);
		if(u[n/2+1+i]<=n/2){
			chang(u[n/2+1+i],n);
		}
		chang(u[n/2+1+i],1);
		chang(1,n/2+1+i);
		/*if(u[n/2+1+i]<=n/2){
			chang(u[n/2+1+i],n);
		}
		if(u[n/2-i]>n/2){
			chang(u[n/2-i],1);
		}
		if(u[n/2-i]<=n/2&&u[n/2+1+i]>n/2){
			chang(u[n/2-i],n);
			chang(u[n/2+1+i],1);
			chang(n,n/2-i);
			chang(1,n/2+i+1);
		}*/
	}
	cout<<res<<"\n";
	fore(i,0,res)cout<<v[i].fst<<" "<<v[i].snd<<"\n";
	
	return 0;
}
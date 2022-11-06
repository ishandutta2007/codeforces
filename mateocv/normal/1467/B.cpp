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

const int MAXN=300005;

ll a[MAXN],c[MAXN];

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		fore(i,0,n)cin>>a[i],a[i]*=2;
		fore(i,0,n)c[i]=0;
		ll sum=0;
		fore(i,1,n-1){
			c[i]=(a[i]>max(a[i-1],a[i+1])||a[i]<min(a[i-1],a[i+1]));
			sum+=c[i];
		}
		ll res=sum;
		fore(i,0,n){
			vector<ll> v;
			fore(j,-1,2){
				if(i-1>=0)v.pb(a[i-1]+j);
				if(i+1<n)v.pb(a[i+1]+j);
			}
			fore(k,0,SZ(v)){
				ll va=sum;
				ll old=a[i];
				a[i]=v[k];
				fore(j,i-1,i+2){
					if(j>=1&&j<n-1){
						va-=c[j];
						va+=(a[j]>max(a[j-1],a[j+1])||a[j]<min(a[j-1],a[j+1]));
					}
				}
				res=min(res,va);
				a[i]=old;
			}
		}
		cout<<res<<"\n";
		
	}
	
	return 0;
}
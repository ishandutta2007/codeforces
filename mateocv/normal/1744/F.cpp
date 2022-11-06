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

ll calc(ll x, ll y, ll k){
	if(k==0)return 1;
	if(x+y<=k)return (x+1)*(y+1);
	//if(x>=k&&y>=k)return (k+1)*(k+2)/2;
	if(x>y)swap(x,y);
	if(y>k)return calc(x,k,k);
	assert(k-y<x);
	ll res=(k-y+1)*(y+1);
	res+=y*(y+1)/2-(k-x)*(k-x+1)/2;
	//cout<<"calc "<<x<<" "<<y<<" "<<k<<" "<<res<<"\n";
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<ll> a(n);
		fore(i,0,n)cin>>a[i];
		vector<ll> ub(n);
		fore(i,0,n)ub[a[i]]=i;
		ll res=1;
		ll l=ub[0],r=ub[0];
		fore(i,1,n){
			//cout<<i<<":\n";
			l=min(l,ub[i-1]);
			r=max(r,ub[i-1]);
			if(l<=ub[i]&&ub[i]<=r)continue;
			if(r-l+1<=2*i){
				ll x,y,k;
				if(ub[i]<l){
					x=l-ub[i]-1;
					y=n-r-1;
				}else{
					x=l;
					y=ub[i]-r-1;
				}
				k=2*i-(r-l+1);
				//cout<<l<<" "<<r<<" "<<x<<" "<<y<<" "<<k<<"\n";
				res+=calc(x,y,k);
				//cout<<res<<"\n";
			}
		}
		cout<<res<<"\n";
	}
	
	return 0;
}
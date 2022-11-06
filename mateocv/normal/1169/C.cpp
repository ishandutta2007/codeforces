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

ll n,m;
ll a[300009];

bool can(ll x){
	ll va=0;
	fore(i,0,n){
		if(va>a[i]+x)return 0;
		if(a[i]+x<m){
			va=max(a[i],va);
		}else{
			if((a[i]+x)%m<va)va=max(a[i],va);
		}
	}
	return 1;
}

int main(){FIN;
	cin>>n>>m;
	fore(i,0,n)cin>>a[i];
	ll l=0,r=m-1;
	while(l<=r){
		ll mid=(l+r)/2;
		if(can(mid))r=mid-1;
		else l=mid+1;
	}
	cout<<l;
	return 0;
}
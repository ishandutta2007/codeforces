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

int main(){FIN;
	ll q; cin>>q;
	while(q--){
		ll n; cin>>n;
		ll rest[4]={-100000,100000,100000,-100000};
		fore(i,0,n){
			ll x,y; cin>>x>>y;
			ll a[4];
			fore(j,0,4)cin>>a[j];
			if(!a[0]){
				rest[0]=max(rest[0],x);
			}
			if(!a[1]){
				rest[1]=min(rest[1],y);
			}
			if(!a[2]){
				rest[2]=min(rest[2],x);
			}
			if(!a[3]){
				rest[3]=max(rest[3],y);
			}
		}
		if(rest[0]<=rest[2]&&rest[3]<=rest[1]){
			cout<<"1 "<<rest[0]<<" "<<rest[1]<<"\n";
		}else{
			cout<<"0\n";
		}
	}
	
	return 0;
}
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
	ll t; cin>>t;
	while(t--){
		ll b,p,f; cin>>b>>p>>f;
		ll h,c; cin>>h>>c;
		ll t1=min(b/2,p);
		ll t2=min(b/2,f);
		//cout<<t1<<" "<<t2<<"\n";
		cout<<max(t1*h+min((b-2*t1)/2,f)*c,t2*c+min((b-2*t2)/2,p)*h)<<"\n";
	}
	
	return 0;
}
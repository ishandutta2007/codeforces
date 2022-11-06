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
	ll n; cin>>n;
	ll a[n];
	ll sumt=0;
	fore(i,0,n)cin>>a[i],sumt+=a[i];
	vector<ll> v;
	v.pb(0);
	ll sum=a[0];
	fore(i,1,n){
		if(a[0]>=2*a[i])v.pb(i),sum+=a[i];
		
	}
	if(2*sum>sumt){
		cout<<SZ(v)<<"\n";
		fore(i,0,SZ(v))cout<<v[i]+1<<" ";
	}else{
		cout<<0;
	}

	return 0;
}
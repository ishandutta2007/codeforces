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

int main(){FIN;
	ll n; cin>>n;
	ll a[n];
	fore(i,0,n)cin>>a[i];
	ll b[2*n];
	fore(i,0,2*n)b[i]=a[(2*i)%n];
	//fore(i,0,2*n)cout<<b[i]<<" "; cout<<"\n";
	ll sum=0;
	fore(i,0,n)sum+=a[i];
	ll mini=0,res=1e18;
	fore(i,0,n/2)mini+=b[i];
	//cout<<mini<<" "<<res<<"\n";
	fore(i,0,2*n){
		if(n/2+i<2*n)mini+=b[n/2+i]-b[i];
		res=min(mini,res);
		//cout<<mini<<" "<<res<<"\n";
	}
	cout<<sum-res<<"\n";
	return 0;
}
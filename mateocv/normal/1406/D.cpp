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
	ll d[n-1];
	fore(i,0,n-1)d[i]=a[i+1]-a[i];
	ll dd[2]={0,0};
	fore(i,0,n-1){
		dd[d[i]>=0]+=d[i];
	}
	cout<<((a[0]+dd[1]+1)>>1)<<"\n";
	ll q; cin>>q;
	while(q--){
		ll l,r,x; cin>>l>>r>>x; l--; r--;
		if(l==0){
			a[0]+=x;
		}else{
			dd[d[l-1]>=0]-=d[l-1];
			d[l-1]+=x;
			dd[d[l-1]>=0]+=d[l-1];
		}
		if(r!=n-1){
			dd[d[r]>=0]-=d[r];
			d[r]-=x;
			dd[d[r]>=0]+=d[r];
		}
		cout<<((a[0]+dd[1]+1)>>1)<<"\n";
	}
	
	return 0;
}
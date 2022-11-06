#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

int main(){FIN;
	ll n,m; cin>>n>>m;
	ll a[n],b[m];
	fore(i,0,n)cin>>a[i];
	fore(i,0,m)cin>>b[i];
//	cout<<*(lower_bound(a,a+n,b[0])-1);
	ll res=0;
/*	fore(i,0,m){
		if(a[0]>b[i]){
			res=max(res,abs(b[i]-*lower_bound(a,a+n,b[i])));
		}else if(a[n-1]<b[i]){
			res=max(res,abs(b[i]-*(lower_bound(a,a+n,b[i])-1)));
		}else{
			res=max(res,max(abs(b[i]-*lower_bound(a,a+n,b[i])),abs(b[i]-*(lower_bound(a,a+n,b[i])-1))));
		}
		
	}*/
	fore(i,0,n){
		if(a[i]<b[0]){
			res=max(res,abs(a[i]-*lower_bound(b,b+m,a[i])));
		}else if(a[i]>b[m-1]){
			res=max(res,abs(a[i]-*(lower_bound(b,b+m,a[i])-1)));
		}else{
			res=max(res,min(abs(a[i]-*lower_bound(b,b+m,a[i])),abs(a[i]-*(lower_bound(b,b+m,a[i])-1))));
		}
	}
	cout<<res;
	
	return 0;
}
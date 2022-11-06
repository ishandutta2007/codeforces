#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
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
	ll a[n+1];
	a[n]=1ll*1e10;
	fore(i,0,n)cin>>a[i];
	fore(i,0,n)a[i]=abs(a[i]);
	sort(a,a+n);
	ll l=0,r=0;
	ll res=0;
	while(l<n){
		if(2*a[l]>=a[r])r++;
		else{
			res+=r-l-1; l++;
			//cout<<l<<" "<<r<<"\n";
		}
	}
	cout<<res;
	return 0;
}
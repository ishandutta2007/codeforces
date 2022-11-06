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
	ll a[n];
	fore(i,0,n)cin>>a[i];
	ll res=0;
	for(int i=n-1;i>=0;i--){
		if(a[i]!=a[0]){
			res=i;break;
		}
	}
	fore(i,0,n){
		if(a[i]!=a[n-1]){
			res=max(res,n-1-i); break;
		}
	}
	cout<<res;
	
	return 0;
}
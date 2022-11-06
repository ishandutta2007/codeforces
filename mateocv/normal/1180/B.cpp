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
	fore(i,0,n)cin>>a[i];
	fore(i,0,n){
		if(a[i]>=0)a[i]=-a[i]-1;
	}
	ll mini=2,minid=-1;
	fore(i,0,n){
		if(a[i]<mini){
			mini=a[i];
			minid=i;
		}
	}
	if(n%2){
		a[minid]=-a[minid]-1;
	}
	fore(i,0,n)cout<<a[i]<<" ";
	
	return 0;
}
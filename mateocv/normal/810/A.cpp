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
	ll n,k; cin>>n>>k;
	ll a[n],sum=0;
	fore(i,0,n){
		cin>>a[i];
		sum+=a[i];	
	}
	fore(i,0,100000000){
		if((sum+i*k)*2>=(2*k-1)*(n+i)){
			cout<<i; break;
		}
	}
	
	return 0;
}
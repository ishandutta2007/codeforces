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
	ll n,k; cin>>n>>k;
	ll a[n];
	fore(i,0,n)cin>>a[i];
	ll b; cin>>b;
	if(k==1){
		fore(i,0,n){
			if(a[i]==0)a[i]=b;
		}
		ll tot=0;
		fore(i,1,n){
			if(a[i]>a[i-1])tot++;
		}
		if(tot==n-1){
			cout<<"No";
		}else{
			cout<<"Yes";	
		}
	}else{
		cout<<"Yes";
	}
	
	return 0;
}
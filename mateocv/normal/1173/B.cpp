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
	ll m=(n+2)/2;
	cout<<m<<"\n";
	fore(i,1,n+1){
		if(i<=m){
			cout<<1<<" "<<i<<"\n";
		}else{
			cout<<i-m+1<<" "<<m<<"\n";
		}
	}
	
	return 0;
}
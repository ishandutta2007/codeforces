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
	ll t; cin>>t;
	while(t--){
		ll n,k; cin>>n>>k;
		if((n-k+1+2*k)%2==1&&n-k+1>=1){
			cout<<"YES"<<"\n";
			fore(i,0,k-1)cout<<"1 ";
			cout<<n-k+1<<"\n";
			continue;
		}else if((n)%2==0&&n-2*k+2>=2){
			cout<<"YES"<<"\n";
			fore(i,0,k-1)cout<<"2 ";
			cout<<n-2*k+2<<"\n";
			continue;
		}else{
			cout<<"NO\n";
		}
	}
	
	return 0;
}
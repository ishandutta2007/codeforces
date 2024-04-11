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
		ll n; cin>>n;
		if(n<=4&&n!=3){
			cout<<"-1\n";
		}else{
			ll r=n%3;
			if(r==0){
				cout<<n/3<<" 0 0\n";
			}else if(r==1){
				cout<<(n-7)/3<<" 0 1\n";
			}else if(r==2){
				cout<<(n-5)/3<<" 1 0\n";
			}
		}
	}
	
	return 0;
}
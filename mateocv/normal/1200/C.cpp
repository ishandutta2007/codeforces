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
	ll n,m,q; cin>>n>>m>>q;
	ll g=__gcd(n,m);
	while(q--){
		ll a,b,c,d; cin>>a>>b>>c>>d;
		b--; d--;
		if(a==1&&c==1){
			if(b/(n/g)==d/(n/g)){
				cout<<"YES";
			}else{
				cout<<"NO";
			}
		}else if(a==2&&c==2){
			if(b/(m/g)==d/(m/g)){
				cout<<"YES";
			}else{
				cout<<"NO";
			}
		}else{
			if(a==2&&c==1){
				swap(b,d);
			}
			if(b/(n/g)==d/(m/g)){
				cout<<"YES";
			}else{
				cout<<"NO";
			}
		}
		cout<<"\n";
	}
	
	return 0;
}
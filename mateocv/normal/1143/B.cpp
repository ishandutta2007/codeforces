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
	vector<ll> v;
	while(n>0){
		v.pb(n%10);
		n/=10;
	}
	//reverse(ALL(v));
	ll res=0,par=1;
	fore(i,0,SZ(v)){
		fore(j,0,SZ(v)){
			if(i==0){
				par*=v[j];
			}else{
				if(j<i){par*=9;
				}else if(j==i){
					if(v[j]>1||j!=SZ(v)-1)par*=v[j]-1;
				}else if(j>i){
					par*=v[j];
				}
			}
		}
		res=max(res,par);
	//	cout<<par<<"\n";
		par=1;
	}
	cout<<res;
	return 0;
}
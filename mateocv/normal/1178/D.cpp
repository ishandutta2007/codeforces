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

ll esp(ll n){
	if(n==1)return 0;
	for(ll i=2;i*i<=n;i++){
		if(n%i==0)return 0;
	}
	return 1;
}

int main(){FIN;
	ll n; cin>>n;
	//fore(n,3,1001){
		vector<pair<ll,ll>> res;
		fore(i,1,n)res.pb({i,i+1});
		res.pb({n,1});
		fore(i,1,n-1){
			if(esp(SZ(res)))break;
			if((i%4==2||i%4==1)){
				res.pb({i,i+2});
			}
		}
		//if(!esp(SZ(res)))cout<<n<<"\n";
		cout<<SZ(res)<<"\n";
		fore(j,0,SZ(res))cout<<res[j].fst<<" "<<res[j].snd<<"\n";
	//}
	//cout<<"ready";
	return 0;
}
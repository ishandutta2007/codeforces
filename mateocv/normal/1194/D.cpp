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
	ll t; cin>>t;
	while(t--){
		ll n,k; cin>>n>>k;
		if(k%3!=0){
			if(n%3==0)cout<<"Bob\n";
			else cout<<"Alice\n";
		}else{
			if((n%(k+1))%3==0&&n%(k+1)!=k)cout<<"Bob\n";
			else cout<<"Alice\n";
		}
	}
	
	return 0;
}
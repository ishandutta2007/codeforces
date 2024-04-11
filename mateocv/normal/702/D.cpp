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
	ll d,k,a,b,t; cin>>d>>k>>a>>b>>t;
//	ll blo=min(a*k+t,b*k);
	if(d<=k){
		cout<<a*d;
	}else{
		cout<<min(a*k+b*(d-k),min(((d-1)/k)*t+a*d,((d-1)/k-1)*t+a*d+(b-a)*(d%k)+(!(d%k))*k*(b-a)));
//		cout<<" "<<a*k+b*(d-k)<<" "<<((d-1)/k)*t+a*d;
	}
	
	return 0;
}
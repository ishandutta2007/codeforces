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

ll MOD=998244353;

ll d=499122177,dd=748683265;

ll sump[2]={499122177,748683265};

int main(){FIN;
	ll n; cin>>n;
	if(n==1){
		cout<<d<<"\n";
		return 0;
	}
	fore(i,3,n+1){
		ll nx=(dd*sump[0]+d*sump[1])%MOD;
		sump[0]=sump[1];
		sump[1]=nx;
	}
	cout<<sump[1]<<"\n";
	
	return 0;
}
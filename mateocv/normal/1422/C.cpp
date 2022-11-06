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

ll MOD=1000000007;

ll pot[100005],pots[100005];

int main(){FIN;
	string s; cin>>s;
	pot[0]=1;
	pots[0]=1;
	fore(i,1,100005){
		pot[i]=pot[i-1]*10%MOD;
		pots[i]=(pots[i-1]+pot[i])%MOD;
	}
	ll res=0,va=0;
	fore(i,0,SZ(s)-1){
		va=va*10%MOD;
		va=(va+s[i]-'0')%MOD;
		res=(res+va*pots[SZ(s)-2-i])%MOD;
	}
	va=0;
	fore(i,0,SZ(s)-1){
		va=(va+(pot[i]*(s[SZ(s)-i-1]-'0')))%MOD;
		res=(res+va*(SZ(s)-1-i))%MOD;
	}
	cout<<res<<"\n";
	return 0;
}
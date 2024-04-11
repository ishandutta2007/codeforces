#include <bits/stdc++.h>
#ifdef DEMETRIO
#define deb(...) fprintf(stderr,__VA_ARGS__)
#define deb1(x) cerr << #x << " = " << x << endl
#else
#define deb(...) 0
#define deb1(x) 0
#endif
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)x.size())
#define mset(a,v) memset(a,v,sizeof(a))
#define mcopy(a,b) memcpy(a,b,sizeof(a))
using namespace std;
typedef long long ll;

#define MOD 1000000007

ll pm(ll a, ll e){
	ll r=1;
	while(e){
		if(e&1)r=r*a%MOD;
		e>>=1;
		a=a*a%MOD;
	}
	return r;
}


ll s[5005][5005];

int main(){
	s[0][0]=1;
	fore(i,1,5005)fore(j,1,i+1)s[i][j]=(j*s[i-1][j]+s[i-1][j-1])%MOD;
	int n,k;
	scanf("%d%d",&n,&k);
	ll r=0,m=n;
	fore(x,1,min(n,k)+1){
		r+=s[k][x]*m%MOD*pm(2,n-x)%MOD;r%=MOD;
		m*=n-x;m%=MOD;
	}
	printf("%lld\n",r);
	return 0;
}
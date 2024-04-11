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
#define SZ(x) ((int)(x).size())
#define mset(a,v) memset(a,v,sizeof(a))
#define mcpy(a,b) memcpy(a,b,sizeof(a))
using namespace std;
typedef long long ll;

ll dp[20][20][2];
string d;

ll f(int i, int m, int b){
	ll& r=dp[i][m][b];
	if(r>=0)return r;
	if(m>3)return r=0;
	if(i==SZ(d))return r=b;
	r=0;
	fore(j,1,10){
		if(!b&&j>(d[i]-'0'))break;
		r+=f(i+1,m+1,(b||(j<(d[i]-'0'))));
	}
	r+=f(i+1,m,b||d[i]!='0');
	return r;
}


ll doit(ll x){
	if(x==1)return 0;
	d=to_string(x);
	mset(dp,-1);
	return f(0,0,0)-1;
}

int main(){
	int tn;
	scanf("%d",&tn);
	while(tn--){
		ll a,b;
		scanf("%lld%lld",&a,&b);
		printf("%lld\n",doit(b+1)-doit(a));
	}
	return 0;
}
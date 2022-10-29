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

ll dp[1<<19];
char d[1<<19];int n;

bool val(int m){
	fore(i,0,n)if(m&(1<<i)&&(i==0||d[i-1]!=d[i]))return false;
	return true;
}

ll f(int m){
	ll& r=dp[m];
	if(r>=0)return r;
	r=val(m);
	fore(i,0,n)if(m&(1<<i)){
		if(m==((1<<n)-1)&&d[i]=='0')continue;
		if(i>0&&d[i]==d[i-1]&&m&(1<<(i-1)))continue;
		r+=f(m^(1<<i));
	}
	return r;
}

int main(){
	mset(dp,-1);
	scanf("%s",d);n=strlen(d);
	sort(d,d+n);
	printf("%lld\n",f((1<<n)-1));
	return 0;
}
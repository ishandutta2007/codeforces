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

#define MOD 998244353

int n,m,k;
ll f[2048],f2[2048];

int main(){
	scanf("%d%d%d",&n,&m,&k);
	f[0]=m;
	fore(_,1,n){
		mset(f2,0);
		fore(i,0,k+1){
			f2[i+1]+=(m-1)*f[i]%MOD;
			if(f2[i+1]>=MOD)f2[i+1]-=MOD;
			f2[i]+=f[i];
			if(f2[i]>=MOD)f2[i]-=MOD;
		}
		mcpy(f,f2);
	}
	printf("%lld\n",f[k]);
	return 0;
}
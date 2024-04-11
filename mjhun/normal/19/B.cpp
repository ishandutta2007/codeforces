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
#define mcopy(a,b) memcpy(a,b,sizeof(a))
using namespace std;
typedef long long ll;

ll f[2048];int n;

int main(){
	scanf("%d",&n);
	fill(f+1,f+n+1,1LL<<60);
	fore(_,0,n){
		int t,c;
		scanf("%d%d",&t,&c);
		for(int i=n;i;--i)f[i]=min(f[i],f[max(i-t-1,0)]+c);
	}
	printf("%lld\n",f[n]);
	return 0;
}
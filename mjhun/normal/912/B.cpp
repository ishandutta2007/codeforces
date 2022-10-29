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
using namespace std;
typedef long long ll;

ll n,k;

int main(){
	scanf("%lld%lld",&n,&k);
	if(k==1)printf("%lld\n",n);
	else {
		int z=64-__builtin_clzll(n);
		printf("%lld\n",(1LL<<z)-1);
	}
	return 0;
}
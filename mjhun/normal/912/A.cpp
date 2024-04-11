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

ll a,b,x,y,z;

int main(){
	scanf("%lld%lld%lld%lld%lld",&a,&b,&x,&y,&z);
	printf("%lld\n",max(2*x+y-a,0LL)+max(3*z+y-b,0LL));
	return 0;
}
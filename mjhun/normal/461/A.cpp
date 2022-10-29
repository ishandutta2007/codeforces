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

int n;
ll a[300005];

int main(){
	scanf("%d",&n);
	fore(i,0,n)scanf("%lld",a+i);
	sort(a,a+n);
	ll r=0;
	fore(i,0,n)r+=min(i+2,n)*a[i];
	printf("%lld\n",r);
	return 0;
}
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

ll n;
ll a[1000];

int main(){
	scanf("%lld",&n);
	for(int i=0;i<n;i++) scanf("%lld",&a[i]);
	ll d = a[1]-a[0];
	int i=0;
	while(i<n-1 && a[i+1]-a[i]==d) i++;
	if(i==n-1) printf("%lld\n",a[n-1]+d);
	else printf("%lld\n",a[n-1]);

	return 0;
}
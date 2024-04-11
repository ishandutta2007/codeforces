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

ll a[16],b[16];int n=14;

int main(){
	fore(i,0,n)scanf("%lld",a+i);
	ll r=0;
	fore(i,0,n){
		mcpy(b,a);
		ll k=b[i];b[i]=0;
		fore(j,0,n)b[(i+j+1)%n]+=k/n+(j<k%n);
		ll s=0;
		fore(j,0,n)if(b[j]%2==0)s+=b[j];
		r=max(r,s);
	}
	printf("%lld\n",r);
	return 0;
}
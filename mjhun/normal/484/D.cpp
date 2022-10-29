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

ll a[1<<20],r,a0,a1;int n;

int main(){
	scanf("%d",&n);
	fore(i,0,n)scanf("%lld",a+i);
	a0=-a[0];a1=a[0];
	fore(i,0,n){
		r=max(r,max(a0+a[i],a1-a[i]));
		if(i<n-1){
			a0=max(a0,r-a[i+1]);
			a1=max(a1,r+a[i+1]);
		}
	}
	printf("%lld\n",r);

	return 0;
}
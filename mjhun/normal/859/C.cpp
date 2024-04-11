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

int n,a[64],f[64],s;

int main(){
	scanf("%d",&n);
	fore(i,0,n)scanf("%d",a+i),s+=a[i];
	for(int i=n-1;i>=0;--i)f[i]=abs(a[i]-f[i+1]);
	int r0=(f[0]+s)/2;int r1=s-r0;
	printf("%d %d\n",r1,r0);
	return 0;
}
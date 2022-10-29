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

void perdi(){puts("-1");exit(0);}

int n;
int a[200005],b[200005];
int r[200005];

int main(){
	scanf("%d",&n);
	fore(i,0,n)scanf("%d%d",a+i,b+i),b[i]+=a[i];
	r[0]=b[0];
	fore(i,1,n){
		r[i]=min(b[i],r[i-1]+1);
		if(r[i]<a[i])perdi();
	}
	for(int i=n-2;i>=0;--i){
		r[i]=min(r[i],r[i+1]+1);
		if(r[i]<a[i])perdi();
	}
	ll rr=0;
	fore(i,0,n)rr+=r[i]-a[i];
	printf("%lld\n",rr);
	fore(i,0,n){
		if(i)putchar(' ');
		printf("%d",r[i]);
	}
	puts("");
	return 0;
}
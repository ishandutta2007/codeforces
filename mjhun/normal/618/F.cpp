#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
using namespace std;
typedef long long ll;

ll a[1<<20],b[1<<20];
ll sa[1<<20],sb[1<<20];
int w[1<<20],z[1<<20];
int n;
bool s;

int main(){
	scanf("%d",&n);
	fore(i,0,n)scanf("%lld",a+i),sa[i+1]=sa[i]+a[i];
	fore(i,0,n)scanf("%lld",b+i),sb[i+1]=sb[i]+b[i];
	if(sa[n]>sb[n])swap(a,b),swap(sa,sb),s=true;
	memset(z,-1,sizeof(w));z[0]=0;
	int j=0;
	int as=-1,ae,bs,be;
	fore(i,1,n+1){
		while(j<n&&sb[j+1]<=sa[i])j++;
		w[i]=j;
		if(z[sa[i]-sb[j]]>=0){
			as=z[sa[i]-sb[j]];
			ae=i;
			bs=w[as];
			be=j;
			break;
		}
		z[sa[i]-sb[j]]=i;
	}
	assert(as>=0);
	if(s)swap(as,bs),swap(ae,be);
	printf("%d\n",ae-as);
	fore(i,as,ae){
		if(i)putchar(' ');
		printf("%d",i+1);
	}
	puts("");
	printf("%d\n",be-bs);
	fore(i,bs,be){
		if(i)putchar(' ');
		printf("%d",i+1);
	}
	puts("");
	return 0;
}
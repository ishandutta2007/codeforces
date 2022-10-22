#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef unsigned long long ll;
const int MAXM=1<<21|5;
char s[MAXM];
int n,ppc[MAXM];
ll a[MAXM],b[MAXM],c[MAXM],pw[25];
inline void FWT(ll *a,int ty){
	for(int mid=1; mid<1<<n; mid<<=1)
		for(int i=0; i<1<<n; i+=mid*2)
			for(int j=0; j<mid; j++)
				a[i+j+mid]+=a[i+j]*ty;
}
int main(){
	scanf("%d",&n);
	pw[0]=1;
	for(int i=1; i<=n; i++)
		pw[i]=pw[i-1]*4;
	scanf("%s",s);
	for(int i=0; i<1<<n; i++){
		ppc[i]=ppc[i>>1]+(i&1);
		a[i]=pw[ppc[i]]*(s[i]^48);
	}
	scanf("%s",s);
	for(int i=0; i<1<<n; i++)
		b[i]=pw[ppc[i]]*(s[i]^48);
	FWT(a,1);
	FWT(b,1);
	for(int i=0; i<1<<n; i++)
		c[i]=a[i]*b[i];
	FWT(c,-1);
	for(int i=0; i<1<<n; i++)
		s[i]=(c[i]>>ppc[i]*2&3)+'0';
	puts(s);
	return 0;
}
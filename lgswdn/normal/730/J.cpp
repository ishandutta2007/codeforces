#include<bits/stdc++.h>
#define rep(i,a,b) for(register int i=a;i<=b;i++)
#define per(i,a,b) for(register int i=a;i>=b;i--)
using namespace std;
const int N=109;

int n,suma,K,sumb,f[10086][N],ans=0;
struct node {int a,b;}c[N];
bool cmp(const node&a,const node&b) {
	return a.b>b.b;
} 

int main() {
	scanf("%d",&n);
	rep(i,1,n) scanf("%d",&c[i].a), suma+=c[i].a;
	rep(i,1,n) scanf("%d",&c[i].b);
	sort(c+1,c+n+1,cmp);
	while(sumb<suma) sumb+=c[++K].b;
	printf("%d ",K);
	memset(f,128,sizeof(f)); f[0][0]=0;
	rep(i,1,n) per(j,sumb,c[i].b) rep(k,1,K)
		f[j][k]=max(f[j][k],f[j-c[i].b][k-1]+c[i].a);
	rep(j,suma,sumb) ans=max(ans,f[j][K]);
	printf("%d",suma-ans);
	return 0;
}
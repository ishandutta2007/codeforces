#include<cstdio>
#include<algorithm>
using namespace std;

int a[1000001];
int p[200001],q[200001];
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	int k=200000;
	for(int i=1,l=1,r=n;i<=k;i++){
		p[i]=a[l];
		q[i]=a[l+1];
		if(a[l]>a[l+1]){
			a[r+1]=a[l+1];
			a[l+1]=a[l];
		}
		else a[r+1]=a[l];
		l++,r++;
	}
	for(int i=1;i<=m;i++){
		long long z;
		scanf("%lld",&z);
		if(z<=k)printf("%d %d\n",p[z],q[z]);
		else printf("%d %d\n",a[k+1],a[k+2+((z-k-1)%(n-1)+(n-1))%(n-1)]);
	}
}
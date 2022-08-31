#include <cstdio>
#include <algorithm>
using namespace std;
int i,n,k,a[100100],p[100100],rk[100100],fg;
long long sum,b;
bool cmp(int x,int y) { return a[x]>a[y];}
int main() {
	scanf("%d%d%I64d",&n,&k,&b);for (i=0;i<n;i++) scanf("%d",&a[i]);
	for (i=0;i<n-1;i++) p[i]=i;sort(p,p+n-1,cmp);
	for (i=0;i<n-1;i++) rk[p[i]]=i;
	sum=0;for (i=0;i<k-1;i++) sum+=a[p[i]];
	for (i=0;i<n-1;i++) {
		if (rk[i]<=k-1 && sum+a[p[k-1]]>b) {
			printf("%d\n",i+1);fg=1;break;
		} else if (rk[i]>=k && sum+a[i]>b) {
			printf("%d\n",i+1);fg=1;break;
		}
	}
	if (!fg) printf("%d\n",n);
}
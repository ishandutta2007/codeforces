#include <cstdio>
using namespace std;
int n,i,j,t,a[1001],fg;
int main() {
	scanf("%d",&n);
	for (i=1;i<=n;i++) scanf("%d",&a[i]);a[0]=a[n+1]=1001;
	for (t=1;t<=1001;t++) {
		if (a[1]<=t||a[n]<=t) fg=1; else 
		for (j=0;j<n;j++) if (a[j+1]<=t && a[j+2]<=t) {
			fg=1;break;
		}
		if (fg) {
			printf("%d\n",t);break;
		}
	}
}
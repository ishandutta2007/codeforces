#include <cstdio>
using namespace std;
int n,i,a[200],min,max;
int main() {
	scanf("%d",&n);
	for (i=0;i<n;i++) scanf("%d",&a[i]);
	min=n-1;max=0;
	for (i=n-2;i>=0;i--) if (a[min]>a[i]) min=i;
	for (i=0;i<n;i++) if (a[max]<a[i]) max=i;
	if (min>=max) printf("%d\n",n-1+max-min); else printf("%d\n",n-2+max-min);
}
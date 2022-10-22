#include <bits/stdc++.h>
using namespace std;
#define N 105
int n,cnt1,cnt2,a[N],b[N];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	for(int i=1;i<=n;++i) scanf("%d",&b[i]);
	for(int i=1;i<=n;++i) cnt1+=a[i]<b[i],cnt2+=a[i]>b[i];
	if(!cnt2) {puts("-1");return 0;}
	printf("%.0lf\n",ceil(1.0*(cnt1+1)/cnt2));return 0;
}
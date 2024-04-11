#include <iostream>
#include <algorithm>
using namespace std;
int a[200005],ans[200005];
pair<int,int> b[200005];
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	scanf("%d",&a[i]);
	for (int i=0;i<n;i++)
	scanf("%d",&b[i].first),b[i].second=i;
	sort(a,a+n);
	sort(b,b+n);
	reverse(b,b+n);
	for (int i=0;i<n;i++)
	ans[b[i].second]=a[i];
	for (int i=0;i<n;i++)
	printf("%d ",ans[i]);
}
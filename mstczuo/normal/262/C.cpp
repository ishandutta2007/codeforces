# include <iostream>
# include <cstdio>
# include <algorithm>
# include <functional>
using namespace std;

int n, d = ~0U>>1, a[100010];
int f[100010];
int main()
{
	scanf("%d",&n); int t;
	for(int i=0;i<n;i++)
		scanf("%d",&t),d=min(d,t);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	sort(a+1, a+n+1,greater<int>());
	for(int i=1;i<=n;i++)a[i]+=a[i-1];

	for(int i=0;i<=d+1;i++)f[i]=a[i];
	f[d+1]=min(f[d+1],f[d]);
	for(int i=d+2;i<=n;i++){
		f[i]=f[i-1]+(a[i]-a[i-1]);
		f[i]=min(f[i-d-1]+(a[i-1]-a[i-d-1]),f[i]),
		f[i]=min(f[i-d-2]+(a[i-2]-a[i-d-2]),f[i]);
	}

	cout<<f[n]<<endl;
	return 0;
}
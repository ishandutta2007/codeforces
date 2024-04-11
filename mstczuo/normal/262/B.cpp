# include <iostream>
# include <cstdio>
# include <algorithm>
using namespace std;

int a[100010], n, m, k=-1, t;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)scanf("%d",&a[i]);
	sort(a, a+n);
	for(int i=0;i<n&&m;i++)
		if(a[i]<=0)a[i]=-a[i],m--;

	if(m%2){
		sort(a,a+n);a[0]=-a[0];
	}

	long long ans = 0;
	for(int i=0; i<n; i++)
		ans+=a[i];
	cout<<ans<<endl;
}
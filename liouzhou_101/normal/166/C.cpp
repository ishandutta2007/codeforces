#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
	int n,x;
	int v[2000];
	cin>>n>>x;
	for (int i=1;i<=n;++i)
		cin>>v[i];
	int ans=0;
	int flag=0;
	for (int i=1;i<=n;++i)
		if (v[i]==x) flag=1;
	if (!flag)
	{
		++ans;
		v[++n]=x;
	}
	sort(v+1,v+n+1);
	while (v[(n+1)/2]!=x)
	{
		int tmp=(v[(n+1)/2]>x)?1:100000;
		++ans;
		v[++n]=tmp;
		sort(v+1,v+n+1);
	}
	cout<<ans<<endl;
	return 0;
}
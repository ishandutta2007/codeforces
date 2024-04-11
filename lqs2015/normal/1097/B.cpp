#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
int n,a[111],cur;
int main()
{
	cin>>n;
	for (int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for (int i=0;i<(1<<n);i++)
	{
		cur=0;
		for (int j=0;j<n;j++)
		{
			if (i&(1<<j)) cur+=a[j];
			else cur-=a[j];
		}
		cur=(cur%360+360)%360;
		if (!cur)
		{
			printf("YES\n");
			return Accepted;
		}
	}
	printf("NO\n");
	return Accepted;
}
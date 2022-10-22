#include <bits/stdc++.h>
using namespace std;
int n;
int t[300000];
int r=0;
int l;
int a[300000];
int b[300000];
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&t[i+1]);
	for(int i=1;i<=n;i++)
	{
		
		if(t[i]==0)
		{
			a[r]=i;
			b[i]=r;
			r++;
		}
		else
		{
			if(a[b[t[i]]]==t[i])
			{
				l=b[t[i]];
				b[i]=l;
				a[l]=i;
			}
			else
			{
				b[i]=r;
				a[r]=i;
				r++;
			}
		}
	}
	printf("%d",r);
	return 0;
}
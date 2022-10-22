#include <iostream>
#include <cstdio>
using namespace std;
int a[1000000];
int n;
int r;
int t=0;
int b[1000000];
bool v[1000000];
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		a[i]--;
		v[i]=false;
	}
	r=0;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&b[i]);
		r+=b[i];
	}
	if(r%2==0) t++;
	int q=0;
	for(int i=0;i<n;i++)
	{
		if(!v[i])
		{
			r=a[i];
			while(!v[r])
			{
				v[r]=true;
				r=a[r];
			}
			q++;
		}
	}
	t=t+q;
	if(q==1) t--;
	printf("%d",t);
	return 0;
}
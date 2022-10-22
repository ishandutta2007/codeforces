#include <iostream>
#include <cstdio>
using namespace std;
int n,l;
int a[1000];
int c[1000];
int b[1000];
int k=0;
bool pos;
int main()
{
	scanf("%d %d",&n,&l);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	for(int i=0;i<n;i++) scanf("%d",&b[i]);
	for(int i=0;i<l;i++)
	{
		k=0;
		pos=false;
		for(int j=0;j<n;j++)
		{
			if(a[j]>=i) 
			{
				c[k]=a[j]-i;
				k++;
			}
		}
		for(int j=0;j<n;j++)
		{
			if(a[j]<i) 
			{
				c[k]=l+(a[j]-i);
				k++;
			}
		}
		/*for(int g=0;g<n;g++) cout<<c[g]<<" ";
		cout<<endl;*/
		for(int j=0;j<n;j++)
		{
			pos=true;
			for(int g=0;g<n;g++)
			{
				
				if(!(b[(j+g)%n]==c[g]))
				{
					
					g=n;
					pos=false;
				}
			}
			if(pos)
			{
				printf("YES");
				return 0;
			}
		}
	}
	printf ("NO");
	return 0;
}
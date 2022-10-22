#include <bits/stdc++.h>
using namespace std;
int n;
int a[200];
int b[200];
int c[200];
int d[200];
int f,g,h;
int main()
{
	scanf("%d",&n);
	a[1]=1;
	b[0]=1;
	f=2;
	g=1;
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<f;j++) c[j]=a[j];
		h=f;
		for(int j=0;j<f;j++) d[j+1]=(a[j]+b[j+1])%2;
		d[0]=b[0];
		f++;
		for(int j=0;j<f;j++) a[j]=d[j];
		for(int j=0;j<h;j++) b[j]=c[j];
		g=h;
	}
	printf("%d\n",f-1);
	for(int i=0;i<f;i++) printf("%d ",a[i]);
	printf("\n%d\n",g-1);
	for(int i=0;i<g;i++) printf("%d ",b[i]);
	return 0;
}
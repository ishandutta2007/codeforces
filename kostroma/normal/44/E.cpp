#include <stdio.h>
#include <memory.h>
#include <string.h>
#include <string>
#include <vector>
#include <set>
#include <math.h>
#include <algorithm>
using namespace std;
char mas[1000];
int main()
{
	int n,k,i,s=0,c,a,b,l,r,j,t;
	scanf("%d%d%d\n", &k,&a, &b);
	gets(mas);
	l=strlen(mas);
	if(l<k*a || l>b*k)
	{
		printf("No solution");
		return 0;
	}
	t=l/k+1;
	if(l%k==0)
		t--;
	r=t*k-l;
	for(i=0;i<r;r--)
	{
		for(j=0;j<l/k;j++)
			printf("%c",mas[j+s]);
		printf("\n");
		s=s+l/k;
	}
	t=l/k+1;
	if(l%k==0)
		t--;
	for(i=s;i<l;i++)
		{
		for(j=0;j<t;j++)
			printf("%c",mas[j+i]);
		printf("\n");
		i=i+t-1;
		}
	return 0;
}
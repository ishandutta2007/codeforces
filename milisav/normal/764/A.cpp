#include <iostream>
#include <cstdio>
using namespace std;
int r=0;
int n,m,z;
int main()
{
	scanf("%d %d %d",&n,&m,&z);
	for(int j=1;j<=z;j++) if(j%n==0 && j%m==0) r++;
	printf("%d",r);
	return 0;
}
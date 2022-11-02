#include <cmath>
#include <queue>
#include <cstdio>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
inline int read() 
{ 
    int x=0,f=1;char ch=getchar(); 
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();} 
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();} 
    return x*f; 
}
int n,k; // orz fccccccccccccccccccccccccccccccccccccccccc
int main()
{
	n=read(),k=read();
	if(n==k||k==0)
	{
		printf("0 0");
		return 0;
	}
	printf("1 ");
	if(k*3==n)
	{
		printf("%d\n",k*2);
		return 0;
	}
	if(k<=n/3)
	{
		printf("%d\n",k*2);
		return 0;
	}
	else 
	printf("%d\n",(n-k));
}
#include <cmath>
#include <queue>
#include <cstdio>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 100000
#define ll long long
using namespace std;
inline int read() 
{ 
    int x=0,f=1;char ch=getchar(); 
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();} 
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();} 
    return x*f; 
}
int n,k;
int pd[100]; 
int main()
{
	n=read(),k=read();
	for(int i=1;i<=n;i++)
	{
		int tmp=0;
		for(int j=1;j<=k;j++)
		tmp+=(read()<<(j-1));
		pd[tmp]=1;
	}
	int lim=(1<<k);
	for(int i=0;i<lim;i++)
	for(int j=0;j<lim;j++)
	if((pd[i]+pd[j]==2)&&(!(i&j)))
	{
		puts("YES");
		return 0;
	}
	puts("NO");
	return 0;
}
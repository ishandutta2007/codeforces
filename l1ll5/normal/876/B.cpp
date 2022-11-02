#include <cmath>
#include <queue>
#include <cstdio>
#include <vector>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 100010
#define ll long long
using namespace std;
inline int read() 
{ 
    int x=0,f=1;char ch=getchar(); 
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();} 
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();} 
    return x*f; 
}
vector<int> v[N];
int n,k,m;
int main()
{
	n=read(),k=read(),m=read();
	for(int i=1;i<=n;i++)
	{
		int x=read();
		v[x%m].push_back(x);
	}
	for(int i=0;i<m;i++)
	{
		if(v[i].size()>=k)
		{
			puts("Yes");
			for(int j=0;j<k;j++)
			printf("%d ",v[i][j]);
			return 0;
		}
	}
	puts("No");
}
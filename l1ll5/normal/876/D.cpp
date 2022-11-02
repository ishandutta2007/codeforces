#include <cmath>
#include <queue>
#include <cstdio>
#include <vector>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 300010
#define ll long long
using namespace std;
inline int read() 
{ 
    int x=0,f=1;char ch=getchar(); 
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();} 
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();} 
    return x*f; 
}
int n;
bool v[N];

int now,cnt;//wzh ans
int main()
{
	n=read();
	cout<<"1 ";now=n+1,cnt=1;
	for(int i=1;i<=n;i++)
	{
		int x=read();
		v[x]=1;cnt++;
		while(v[now-1])now--,cnt--;
		printf("%d ",cnt);
	}
}
/*
orzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz
*/
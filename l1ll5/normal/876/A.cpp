#include <cmath>
#include <queue>
#include <cstdio>
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
int n,a,b,c,ans; 
int main()
{
	n=read(),a=read(),b=read(),c=read();
	int mn=min(a,b);
	mn=min(mn,c);
	if(mn==a||mn==b)
	{
		ans=mn*(n-1);
		cout<<ans<<endl;
	}
	else
	{
		if(n==1)
		{
			cout<<0<<endl;
			return 0;
		}
		if(n==2)
		{
			cout<<min(a,b)<<endl;
			return 0;
		}
		else
		{
			ans=min(a,b);
			n--;
			ans+=mn*(n-1);
			cout<<ans<<endl;
			return 0;
		}
	}
}
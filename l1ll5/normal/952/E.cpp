#include<cmath>
#include<ctime>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<iomanip>
#include<vector>
#include<string>
#include<bitset>
#include<queue>
#include<map>
#include<set>
using namespace std;

inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch<='9'&&ch>='0'){x=10*x+ch-'0';ch=getchar();}
	return x*f;
}
void print(int x)
{if(x<0)putchar('-'),x=-x;if(x>=10)print(x/10);putchar(x%10+'0');}

int main()
{
	int n=read();
	char opt[20];
	int mx=0,mn=0;
	for(int i=1;i<=n;++i)
	{
		scanf("%s",opt),scanf("%s",opt);
		switch(opt[0])
		{
			case 's':mx++;break;
			default :mn++;break;
		}
	}
	if(mx<mn) swap(mx,mn);
	int ans;
	mn ? ans=2 : ans=1;
	while((ans*ans/2)<mn || ((ans*ans+1)/2)<mx)
	{
		ans++;
	}
	cout<<ans<<endl;
	return 0;
}
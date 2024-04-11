#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int read()
{
	char ch=getchar();int f=0;
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') {f=f*10+(ch^48);ch=getchar();}
	return f;
}
int main()
{
	long long l,r,x,y,k;
	cin>>l>>r>>x>>y>>k;
	for(int i=x;i<=y;i++)
	{
		if(i*k>=l&&i*k<=r)
		{
			printf("YES");
			return 0;
		}
	}
	puts("NO");
	return 0;
}
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
int read()
{
	char ch=getchar();int f=0,x=1;
	while(ch<'0'||ch>'9'){if(ch=='-') x=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){f=(f<<1)+(f<<3)+ch-'0';ch=getchar();}
	return f*x;
}
int p[55],cou[55];
int main()
{
	int T=read();
	p[0]=1;
	for(int i=1;i<=30;i++)
	{
		p[i]=p[i-1]*2;
	}
	for(int i=0;i<=30;i++) p[i]--;
	//cout<<p[30];
	while(T--)
	{
		int d=read(),m=read(),lim;
		if(d==1)
		{
			cout<<1%m<<endl;
			continue;
		}
		for(int i=1;i<=30;i++)
		{
			if(p[i]>=d)
			{
				lim=i;
				cou[i]=d-p[i-1];
				//cout<<cou[i]<<endl;
				break;
			}
			else cou[i]=p[i]-p[i-1];
		}
		ll ans=1%m;
		for(int i=1;i<=lim;i++)
		{
			ans=ans*(cou[i]+1)%m;
		}
		cout<<(ans-1+m)%m<<endl;
	}
}
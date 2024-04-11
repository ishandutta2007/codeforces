#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
char ch[10];
int main()
{
	int n,i,l=0,r=1000000000,ax1,ay1,ax2,ay2;cin>>n;
	for (i=1;i<=n && i<=25;i++)
	{
		int mid=(l+r)>>1;
		cout<<mid<<' '<<0<<endl;
		cin>>ch;if (ch[0]=='b') l=mid;
		else r=mid;
	}
	ax1=l,ax2=r;l=0;r=1000000000;
	for (;i<=n;i++)
	{
		int mid=(l+r)>>1;
		cout<<mid<<' '<<1000000000<<endl;
		cin>>ch;if (ch[0]=='b') l=mid;
		else r=mid;
	}
	cout<<ax1+1<<' '<<0<<' '<<r-1<<' '<<1000000000<<endl;
}
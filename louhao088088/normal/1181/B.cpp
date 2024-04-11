#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	char ch=getchar();bool f=0;int x=0;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=1;
	for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	if(f==1)x=-x;return x; 
}
char x;
int n,t,f,a[100005],b[100005],c[100005],b1[100005],c1[100005],d[100005],d1[100005],w;
int main()
{
//	freopen("split.in","r",stdin);
	//freopen("split.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)
	{
		scanf("%c",&x);a[i]=x-'0';
	}
	//f=a[1];
	t=n/2+1;w=n/2;
	while(a[t+1]==0)t++;
	while(a[w+1]==0)w--;
	for(int i=1;i<=t;i++)
		b[t-i+1]=a[i];
	for(int i=t+1;i<=n;i++)
		c[n-i+1]=a[i];
	for(int i=1;i<=w;i++)
		b1[w-i+1]=a[i];
	for(int i=w+1;i<=n;i++)
		c1[n-i+1]=a[i];
	int len1=t,len2=n-t,len3=0;
	for(int i=1;i<=max(len1,len2);i++)
	{
		//cout<<c[i]<<" "<<b[i]<<endl;
		d[i]=d[i]+c[i]+b[i];
		if(d[i]>=10)d[i]-=10,d[i+1]=1,len3=max(len3,i+1);
		len3=max(i,len3);
	}
	int len4=w,len5=n-w,len6=0;
	for(int i=1;i<=max(len4,len5);i++)
	{
		d1[i]=d1[i]+c1[i]+b1[i];
		if(d1[i]>=10)d1[i]-=10,d1[i+1]=1,len6=max(len6,i+1);
		len6=max(i,len6);
	}//cout<<"A";
	//cout<<len3<<" "<<len6<<" "<<t<<" "<<w<<endl;
	if(len3<len6)
	{//cout<<"A";
		for(int i=len3;i>=1;i--)
		{
			cout<<d[i];
		}exit(0);
	}
	else if(len3>len6)
	{
		for(int i=len6;i>=1;i--)
		{
			cout<<d1[i];
		}exit(0);
	}
	else 
	{//
		for(int i=len6;i>=1;i--)
		{//cout<<"A";
			if(d[i]<d1[i])
			{
				for(int j=i;j>=1;j--)
				{
					cout<<d[j];
				}exit(0);
			}
			else if(d[i]>d1[i])
			{
				for(int j=i;j>=1;j--)
				{
					cout<<d1[j];
				}exit(0);
			}
			cout<<d1[i];
		}
	}
	return 0;
}
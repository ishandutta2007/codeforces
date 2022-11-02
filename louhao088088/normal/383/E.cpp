#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read()
{
	char ch=getchar();bool f=0;int x=0;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=1;
	for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	if(f==1)x=-x;return x;
}
int getnum(int x){int num=0;while(x){if(x&1)num++;x>>=1;}return num;}
int n,x,f[(1<<24)+1],m,s,ans,T,t;
char a[5];
signed main()
{
	n=read();s=pow(2,24)-1;
	for(int i=1;i<=n;i++)
	{
		scanf("%s",a);int t=0;
		for(int i=0;i<=2;i++)t=t|(1<<(a[i]-'a'));
		for(int i=t;i>0;i=(i-1)&t)
			if(getnum(i)%2==1)f[i]++;
			else f[i]--;
	}
	for(int i=0;i<=23;i++)
	{
		for(int j=0;j<=s;j++)
		{
			if(j&(1<<i))f[j]+=f[j^(1<<i)];
		}
	}
	for(int i=0;i<=s;i++)ans=ans^(f[i]*f[i]);
	cout<<ans;
}
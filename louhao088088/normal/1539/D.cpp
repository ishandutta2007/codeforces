#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=2e5+5;
inline int read()
{
	char ch=getchar();bool f=0;int x=0;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=1;
	for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	if(f==1)x=-x;return x;
}
struct node
{
	int x,y;
}a[maxn];
int n,m,ans,sum=0;
bool cmp(node a,node b)
{
	return a.y<b.y;
}
signed main()
{
	n=read();
	for(int i=1;i<=n;i++)a[i].x=read(),a[i].y=read(),sum+=a[i].x;
	sort(a+1,a+n+1,cmp);if(sum<a[1].y)cout<<sum*2,exit(0);
	int t=a[1].y;ans=a[1].y*2;
	for(int i=1;i<=n;i++)
	{
		if(t<a[i].y)
		{
			if(sum<a[i].y)ans=ans+(sum-t)*2,cout<<ans,exit(0);
			else ans=ans+(a[i].y-t)*2;t=a[i].y;
		}
		ans+=min(sum-t,a[i].x);t=t+a[i].x;
		if(t>=sum)cout<<ans,exit(0);
		//cout<<ans<<endl;	
	}if(t<=sum)ans=ans+(sum-t)*2;cout<<ans<<endl;
	return 0;
}
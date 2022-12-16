#include<bits/stdc++.h>
#define ll long long
using namespace std;
int read()
{
	char ch=getchar();int x=0,f=1;
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
ll a[200005],t,b[200005];
ll p[200005];
int n;
int lowbit(int x)
{
	return x&(-x);
}
void add(int x,int y)
{
	for(int i=x;i<=n;i+=lowbit(i))
	p[i]+=y;
}
int query(int x)
{
	//if(x==n+1) return n;
	int ret=0;
	for(int i=x;i;i-=lowbit(i))
	ret+=p[i];
	return ret;
}
int find(ll x)
{
	int l=1,r=n,ans=n+1;
	while(l<=r)
	{
		int mid=l+r>>1;
		if(b[mid]==x) return mid;
		else if(b[mid]>x) r=mid-1;
		else ans=mid,l=mid+1;
	}
	return ans;
}
int main()
{
	n=read();cin>>t;
	for(int i=1;i<=n;i++)
	{
		a[i]=read();b[i]=b[i-1]+a[i];
	}
	b[n]=0;
	sort(b+1,b+n+1);
	ll now=0,ans=0;
	add(find(0),1);
	for(int i=1;i<=n;i++)
	{
		now+=a[i];
		if(find(now-t)==n+1)
		{
			ans+=i;
			add(find(now),1);
			continue;
		}
		//cout<<find(now-t)<<" "<<i-query(find(now-t))<<endl;
		ans+=i-query(find(now-t));
		if(i!=n)
		add(find(now),1);
		//cout<<"ok";
	}
	cout<<ans;
}
#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	char ch=getchar();bool f=0;int x=0;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=1;
	for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	if(f==1)x=-x;return x;
}
int lowbit(int x) {return x&(-x);}
struct node
{
	int x,y,z,id;
}a[500005];
bool cmp(node a,node b)
{
	return a.x>b.x;
}
bool cmp1(node a,node b)
{
	return a.y<b.y;
}
int n,id,c[500005],tot=0,ans=0;
void add(int x,int num)
{
	while(x)c[x]=max(c[x],num),x-=lowbit(x);
}
int query(int x)
{
	int ll=-1;
	while(x<=tot)ll=max(ll,c[x]),x+=lowbit(x);
	return ll;
}
int main()
{
	n=read();
	for(int i=1;i<=n;i++)a[i].x=read();
	for(int i=1;i<=n;i++)a[i].y=read();
	for(int i=1;i<=n;i++)a[i].z=read();
	sort(a+1,a+n+1,cmp1);
	for(int i=1;i<=n;i++)
		if(a[i].y==a[i-1].y)a[i].id=tot;
		else a[i].id=++tot,c[tot]=-1;
	sort(a+1,a+n+1,cmp);a[n+1].x=-1;
	for(int i=1;i<=n;i++)
	{
		if(a[i].x!=a[i+1].x)
		{
			
			for(int j=id;j<=i;j++)
				if(query(a[j].id+1)>a[j].z)ans++;//,cout<<j<<endl;
			for(int j=id;j<=i;j++)
				add(a[j].id,a[j].z);//cout<<i<<endl;;
			id=i+1;
		}
	}
	cout<<ans;
	return 0;
}
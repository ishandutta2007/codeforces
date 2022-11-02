#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	char ch=getchar();int x=0;bool f=0;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=1;
	for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	if(f==1)x=-x;return x;
}
#define int long long
#define double long double
const int maxn=1e5+5,mod=1e9+7;
int n,m,k,a[maxn],c[maxn],tot,cnt,p[maxn],st[maxn],h[maxn],w[maxn];
struct node
{
	int x,y,id,opt;
}b[maxn],d[maxn];
vector<int>e[maxn];
bool cmp(node a,node b)
{
	return a.y>b.y;
}
inline void print(int x)
{
    static int a[55];int top=0;
    if(x<0) putchar('-'),x=-x;
    do{a[top++]=x%10,x/=10;}while(x);
    while(top) putchar(a[--top]+48);
}
double l,r,eps=1e-12;
bool check(double x)
{
	for(int i=1;i<=n;i++)
		p[i]=a[i];
	int sum=0,num=0,g=0,res=1,u;
	for(int i=1;i<=tot;i++)
	{
		double t=1.0*b[i].y/p[b[i].x];t=t+1;//cout<<t<<endl;
		if(fabs(x-t)<eps)
		{
			num++,st[++g]=i;
		}
		else if(t-x>eps)sum++,p[b[i].x]=p[b[i].x]+b[i].y,w[sum]=i;
	}int sum2=sum;
	for(int i=1;i<=cnt;i++)
	{
		if(fabs(d[i].y-x)<eps)
		{
			num++;u=i;
		}
		else if(d[i].y-x>eps)
		{
			sum++;w[sum]=d[i].id;
		}
		else break;
	}
	if(sum>k)return true;
	else if(num+sum<k)return false;
	printf("%lld\n",k);
	//if(m==49849)cout<<sum<<" "<<num<<" "<<g<<" "<<sum2<<endl;
	for(int i=1;i<=sum2;i++)
	{
		if(b[w[i]].opt==1)
		print(b[w[i]].id),putchar(' ');
	}int o=sum;
	for(int i=1;i<=g;i++)
	{
		sum++;
		if(b[st[i]].opt==1)print(b[st[i]].id),putchar(' ');
		if(sum>=k)break;
	}sum=o;
	for(int i=1;i<=sum2;i++)
	{
		if(b[w[i]].opt!=1)
		print(b[w[i]].id),putchar(' ');
	}
	for(int i=1;i<=g;i++)
	{
		sum++;
		if(b[st[i]].opt!=1)print(b[st[i]].id),putchar(' ');
		if(sum>=k)break;
	}
	for(int i=sum2+1;i<=o;i++)
		print(w[i]),putchar(' ');
	for(int i=sum+1;i<=k;i++)
		print(d[u+sum+1-i].id),putchar(' ');
	exit(0);
}
signed main()
{
	//freopen("B.in","r",stdin);
	n=read();m=read();k=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=m;i++)
	{
		int op=read(),x=read(),y=read();
		if(op==1)
		{
			if(c[x]<y)c[x]=y,h[x]=i;
		}
		else if(op==2)
		{
			b[++tot].x=x,b[tot].y=y,b[tot].id=i;
		}
		else if(op==3)
		{
			if(y>1)d[++cnt].y=y,d[cnt].id=i;
		}
	}
	for(int i=1;i<=n;i++)
		if(a[i]<c[i])b[++tot].x=i,b[tot].y=c[i]-a[i],b[tot].id=h[i],b[tot].opt=1;
	sort(b+1,b+tot+1,cmp);
	sort(d+1,d+cnt+1,cmp);
	if(tot+cnt<=k)
	{
		for(int i=1;i<=tot;i++)
		{
			a[b[i].x]+=b[i].y;
		}int ans=1;
		cout<<tot+cnt<<endl;
		for(int i=1;i<=tot;i++)
			if(b[i].opt==1)
				print(b[i].id),putchar(' ');
		for(int i=1;i<=tot;i++)
			if(b[i].opt!=1)
				print(b[i].id),putchar(' ');
		for(int i=1;i<=cnt;i++)
			print(d[i].id),putchar(' ');
		exit(0);
	}
	l=1,r=1000000;
	while(abs(l-r)>eps)
	{
		double mid=(l+r)/2;
		if(check(mid))l=mid;
		else r=mid;
	}
	return 0;
}
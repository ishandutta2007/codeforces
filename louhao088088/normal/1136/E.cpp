#include<bits/stdc++.h>
using namespace std;
#define ls (rt<<1ll)
#define rs (rt<<1ll|1ll)
#define mid (l+r>>1ll)
#define int long long
inline int read()
{
	char ch=getchar();int x=0;bool f=0;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=1;
	for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	if(f==1)x=-x;return x;
}
void print(int x)
{
    if(x<0) putchar('-'),x=-x;
    if(x>9) print(x/10);
    putchar(x%10+'0');
}
const int maxn=2e5+5,inf=-1e18;
int tag[maxn*4],a[maxn],l,r,x,y,sum[maxn*4],n,m,opt,ss[maxn],k[maxn];
char s[5];
void build(int rt,int l,int r)
{
	tag[rt]=inf;
	if(l==r){sum[rt]=a[l];return;}
	build(ls,l,mid),build(rs,mid+1,r);
	sum[rt]=sum[ls]+sum[rs];
}
void push(int rt,int l,int r)
{
	if(tag[rt]!=inf)
	{
		tag[ls]=tag[rt];tag[rs]=tag[rt];
		sum[ls]=tag[rt]*(mid-l+1);sum[rs]=tag[rt]*(r-mid);tag[rt]=inf;
	}
}
void add(int rt,int l,int r,int L,int R,int num)
{
	
	if(l>R||r<L)return;//cout<<sum[rt]<<endl;
	if(l>=L&&r<=R)
	{
		sum[rt]=num*(r-l+1);tag[rt]=num;return;
	}
	push(rt,l,r);add(ls,l,mid,L,R,num),add(rs,mid+1,r,L,R,num);
	sum[rt]=sum[ls]+sum[rs];
}
int query(int rt,int l,int r,int L,int R)
{
	if(l>R||r<L)return 0;
	if(l>=L&&r<=R)return sum[rt];
	push(rt,l,r);return query(ls,l,mid,L,R)+query(rs,mid+1,r,L,R);
}
signed main()
{
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<n;i++)k[i]=read(),k[i]+=k[i-1],a[i+1]=a[i+1]-k[i],ss[i]=ss[i-1]+k[i];//,cout<<k[i]<<" "<<ss[i]<<endl;
	//for(int i=1;i<=n;i++)cout<<a[i]<<" ";
	build(1,1,n);m=read();
	for(int i=1;i<=m;i++)
	{
		scanf("%s",s);
		if(s[0]=='+')
		{
			x=read(),y=read();l=x,r=n;int u=query(1,1,n,x,x)+y;
			while(l<=r)
			{
				int res=query(1,1,n,mid,mid);
				if(res==u)break;
				else if(res>u)r=mid-1;//cout<<"A";
				else l=mid+1;
			}//cout<<res<<endl;
			add(1,1,n,x,mid,u);
		}
		else l=read(),r=read(),print(query(1,1,n,l,r)+ss[r-1]-ss[max(0ll,l-2)]),puts("");
	}
	return 0;
}
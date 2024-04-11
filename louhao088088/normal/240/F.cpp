#include<bits/stdc++.h>
using namespace std;
//static char buf[1000000],*p1=buf,*p2=buf;
//#define getchar() p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++
#define re register
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define ls (rt<<1)
#define rs (rt<<1|1)
#define mid (l+r>>1)
const int maxn=2e5+5,M=34005;
inline int read()
{
	char ch=getchar();bool f=0;int x=0;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=1;
	for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	if(f==1)x=-x;return x;
}
inline void print(int x)
{
    static int a[55];int top=0;
    if(x<0) putchar('-'),x=-x;
    do{a[top++]=x%10,x/=10;}while(x);
    while(top) putchar(a[--top]+48);
}
int n,m,a[maxn],sum[27][maxn*4],tag[27][maxn*4],g,c[55],l,r;
void push(int rt,int l,int r,int x)
{
	if(tag[x][rt]!=-1)
	{
		tag[x][ls]=tag[x][rs]=tag[x][rt],
		sum[x][ls]=tag[x][ls]*(mid-l+1),sum[x][rs]=tag[x][rs]*(r-mid);
	}
	tag[x][rt]=-1;
}
void change(int x,int rt,int l,int r,int L,int R,int num)
{
	if(l>R||r<L)return;
	if(l>=L&&r<=R){tag[x][rt]=num;sum[x][rt]=num*(r-l+1);return;}
	push(rt,l,r,x);change(x,ls,l,mid,L,R,num),change(x,rs,mid+1,r,L,R,num);
	sum[x][rt]=sum[x][ls]+sum[x][rs];
}
int query(int x,int rt,int l,int r,int L,int R)
{
	if(l>R||r<L)return 0;
	if(l>=L&&r<=R)return sum[x][rt];
	push(rt,l,r,x);return query(x,ls,l,mid,L,R)+query(x,rs,mid+1,r,L,R);
}
char b[maxn];
signed main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	n=read(),m=read();
	scanf("%s",b+1);
	for(int i=1;i<=n;i++)
		change(b[i]-'a',1,1,n,i,i,1);
	for(int i=1;i<=m;i++)
	{
		l=read(),r=read();g=-1;int F=0;
		for(int j=0;j<26;j++)
		{
			c[j]=query(j,1,1,n,l,r);
			if(c[j]%2==1&&g==-1)g=j;
			else if(c[j]%2==1){F=1;break;}
		}
		if(F)continue;
		int lx=l,rx=r;
		//cout<<g<<" "<<c[1]<<endl;
		for(int j=0;j<26;j++)
		{
			if(c[j])
			{
				change(j,1,1,n,l,r,0);
				change(j,1,1,n,lx,lx+c[j]/2-1,1);lx+=c[j]/2;
				change(j,1,1,n,rx-c[j]/2+1,rx,1);rx-=c[j]/2;
			}
		}
		if(g!=-1)
		{
			change(g,1,1,n,lx,rx,1);
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<26;j++)
			if(query(j,1,1,n,i,i)){putchar('a'+j);break;}
	}
 	return 0;
}
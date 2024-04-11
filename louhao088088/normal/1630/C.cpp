#include<bits/stdc++.h>
using namespace std;
//static char buf[1000000],*p1=buf,*p2=buf;
//#define getchar() p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++
#define re register
#define ls (rt<<1)
#define rs (rt<<1|1)
#define mid (l+r>>1) 
const int maxn=8e5+5;
inline int read()
{
	char ch=getchar();bool f=0;int x=0;
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
int n,m,f[maxn],Max[maxn],a[maxn],pos[maxn],Mx[maxn];
void add(int rt,int l,int r,int x,int num)
{
	if(l>x||r<x)return ;
	if(l==r){Mx[rt]=num;return;}
	add(ls,l,mid,x,num),add(rs,mid+1,r,x,num); 
	Mx[rt]=max(Mx[ls],Mx[rs]);
}
int query(int rt,int l,int r,int L,int R)
{
	if(l>R||r<L)return -1e9;
	if(l>=L&&r<=R)return Mx[rt];
	return max(query(ls,l,mid,L,R),query(rs,mid+1,r,L,R)); 
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	memset(Max,-0x3f,sizeof Max);
	n=read();
	for(int i=1;i<=n;i++)a[i]=read(); 
	f[0]=0;
	for(int i=1;i<=n;i++)
	{
		f[i]=f[i-1];
		if(pos[a[i]])
		{
			f[i]=max(f[i],Max[a[i]]+i-1);
			f[i]=max(f[i],query(1,0,n,pos[a[i]],i-1)+i-1);
		}
		else pos[a[i]]=i;
		Max[a[i]]=max(Max[a[i]],f[i]-i);
		add(1,0,n,i,f[i]-i);
	}
	cout<<f[n]<<endl;
 	return 0;
}
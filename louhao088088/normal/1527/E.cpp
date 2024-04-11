#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
#define ls rt<<1
#define rs rt<<1|1
inline int read()
{
	char ch=getchar();bool f=0;int x=0;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=1;
	for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	if(f==1)x=-x;return x;
}
const int maxn=35005;
int n,m,k,f[maxn][305],a[maxn],c[maxn],g[maxn],M[200005],tag[200005];
void pushup(int rt){M[rt]=min(M[ls],M[rs]);}
void push(int rt,int l,int r)
{
	if(tag[rt])tag[ls]+=tag[rt],tag[rs]+=tag[rt],M[ls]+=tag[rt],M[rs]+=tag[rt];tag[rt]=0;
} 
void clear(){memset(M,0x3f,sizeof M);memset(tag,0,sizeof tag);}
void add(int rt,int l,int r,int L,int R,int num)
{
	//cout<<rt<<" "<<l<<" "<<r<<" "<<L<<" "<<R<<" "<<num<<endl;
	if(l>R||r<L)return;
	if(l>=L&&r<=R){tag[rt]+=num,M[rt]+=num;return;}
	push(rt,l,r);int mid=l+r>>1;
	add(ls,l,mid,L,R,num),add(rs,mid+1,r,L,R,num);
	pushup(rt);
}
void change(int rt,int l,int r,int L,int R,int num)
{
	if(l>R||r<L)return;
	if(l>=L&&r<=R){M[rt]=num;return;}
	push(rt,l,r);int mid=l+r>>1;
	change(ls,l,mid,L,R,num),change(rs,mid+1,r,L,R,num);
	pushup(rt);//cout<<rt<<" "<<M[rt]<<" "<<endl;
}
int query(int rt,int l,int r,int L,int R)
{
	//cout<<rt<<" "<<l<<" "<<r<<" "<<L<<" "<<R<<endl;
	if(l>R||r<L)return 0x3f3f3f3f;
	if(l>=L&&r<=R)return M[rt];
	push(rt,l,r);int mid=l+r>>1;
	return min(query(ls,l,mid,L,R),query(rs,mid+1,r,L,R));
}
signed main()
{
	n=read(),m=read();
	for(int i=1;i<=n;i++)a[i]=read(),g[i]=c[a[i]],c[a[i]]=i;
	for(int i=1;i<=n;i++)
	{
		f[i][1]=f[i-1][1];
		if(g[i]!=0)f[i][1]=f[i][1]+i-g[i];//cout<<f[i][1]<<" "<<g[i]<<endl;
	} //cout<<endl;
	for(int k=2;k<=m;k++)
	{
		clear();
		for(int i=1;i<=n;i++)
		{
			change(1,1,n,i,i,f[i][k-1]);
			if(g[i]>1)add(1,1,n,1,g[i]-1,i-g[i]);
			f[i][k]=query(1,1,n,1,i);//cout<<f[i][k]<<" "<<i<<" "<<k<<" "<<i-g[i]<<" "<<g[i]<<endl;
		}//cout<<endl;
	}cout<<f[n][m];
	return 0;
}
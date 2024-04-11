#include<bits/stdc++.h>
using namespace std;
//static char buf[1000000],*p1=buf,*p2=buf;
//#define getchar() p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++
#define re register
#define ls (rt<<1)
#define rs (rt<<1|1)
#define mid (l+r>>1)
#define int long long
const int maxn=1e5+5;
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
int n,m,opt[maxn],L[maxn],R[maxn],b[maxn*10],tot,tag[maxn*30],sum[maxn*30],tag2[maxn*30],res;
void push(int rt,int l,int r)
{
	if(tag[rt]!=-1)
	{
		tag[ls]=tag[rs]=tag[rt];tag2[ls]=tag2[rs]=tag2[rt]=0;
		sum[ls]=(mid-l+1)*tag[rt];sum[rs]=(r-mid)*tag[rt];tag[rt]=-1;
		//if(ls==152||rs==152)cout<<"A",cout<<tag[rt]<<" "<<l<<" "<<r<<endl;tag[rt]=-1;
	}
	else if(tag2[rt])
	{
		tag2[ls]^=1,tag2[rs]^=1;//cout<<sum[ls]<<" "<<;
		if(tag[ls]!=-1)tag[ls]^=1,tag2[ls]=0;
		if(tag[rs]!=-1)tag[rs]^=1,tag2[rs]=0;
		sum[ls]=(mid-l+1)-sum[ls];sum[rs]=(r-mid)-sum[rs];tag2[rt]=0;
		//if(ls==152||rs==152)cout<<"A";
	//	cout<<l<<" "<<r<<" "<<mid<<" "<<sum[ls]<<endl;
	}
}
void add(int rt,int l,int r,int L,int R,int num)
{
	if(l>R||r<L)return ;
	if(l>=L&&r<=R){tag2[rt]=0;tag[rt]=num;sum[rt]=(r-l+1)*num;return;}
	push(rt,l,r);
	add(ls,l,mid,L,R,num),add(rs,mid+1,r,L,R,num);
	sum[rt]=sum[ls]+sum[rs];
//	cout<<rt<<" "<<l<<" "<<r<<" "<<b[l]<<" "<<sum[ls]<<" "<<L<<" "<<R<<endl;
}
void change(int rt,int l,int r,int L,int R)
{
	if(l>R||r<L)return ;
	if(l>=L&&r<=R){if(tag[rt]!=-1)tag[rt]^=1,tag2[rt]=0;else tag2[rt]^=1;sum[rt]=(r-l+1)-sum[rt];return;}
	push(rt,l,r);
	change(ls,l,mid,L,R),change(rs,mid+1,r,L,R);
	sum[rt]=sum[ls]+sum[rs];
}
void query(int rt,int l,int r)
{
	//cout<<l<<' '<<r<<" "<<sum[rt]<<endl;
	if(l==r&&sum[rt]){res=l;return;}
	if(l==r)return ;
	push(rt,l,r);
	if(sum[ls]<mid-l+1)
		query(ls,l,mid);
	else res=mid,query(rs,mid+1,r);	
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read();
	memset(tag,-1,sizeof tag);
	for(int i=1;i<=n;i++)
	{
		opt[i]=read(),L[i]=read(),R[i]=read();
		if(L[i]!=1)b[++tot]=L[i]-1;if(R[i]!=1)b[++tot]=R[i]-1;
		b[++tot]=L[i];b[++tot]=L[i]+1;
		b[++tot]=R[i];b[++tot]=R[i]+1;
	}b[++tot]=1;
	//for(int i=1;i<=100;i++)b[i]=i;tot=100;
	sort(b+1,b+tot+1);
	int un=unique(b+1,b+tot+1)-b;
	//for(int i=1;i<=un;i++)cout<<b[i]<<" "<<endl;
	for(int i=1;i<=n;i++)
	{
		res=0;int l=lower_bound(b+1,b+un+1,L[i])-b,r=lower_bound(b+1,b+un+1,R[i])-b;
	//	cout<<b[l]<<" "<<b[r]<<endl;
		if(opt[i]==1)add(1,1,un,l,r,1);
		else if(opt[i]==2)add(1,1,un,l,r,0);
		else change(1,1,un,l,r);query(1,1,un);//cout<<res<<endl;
		printf("%lld\n",b[res+1]);
	}
 	return 0;
}
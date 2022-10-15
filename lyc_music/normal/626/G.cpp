//QwQcOrZ yyds!!!
#include<bits/stdc++.h>
#define N 200005
using namespace std;

inline int read(){
    int x = 0; char ch = getchar(); bool positive = 1;
    for (; !isdigit(ch); ch = getchar())	if (ch == '-')	positive = 0;
    for (; isdigit(ch); ch = getchar())	x = x * 10 + ch - '0';
    return positive ? x : -x;
}
inline void write(int a){
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writesp(int a){
    if(a>=10)write(a/10);
    putchar('0'+a%10);
    printf(" ");
}
inline void writeln(int a){
    if(a<0){
    	a=-a; putchar('-');
    }
    write(a); puts("");
}
int n,t,q,a[N],p[N],l[N],mx[N<<2],mn[N<<2];

double add[N],sub[N],ans;

void work(int x)
{
	add[x]=a[x]>=l[x]?0:p[x]*(a[x]+1)*1.0/(l[x]+a[x]+1)-p[x]*a[x]*1.0/(a[x]+l[x]);
	if(a[x]) sub[x]=a[x]>l[x]?0:1.0*p[x]*a[x]/(l[x]+a[x])-1.0*p[x]*(a[x]-1)/(l[x]+a[x]-1);
	else sub[x]=10000000000000000.0;
}
void pushup(int x)
{
	mx[x]=(add[mx[x<<1]]>add[mx[x<<1|1]]?mx[x<<1]:mx[x<<1|1]);
	mn[x]=(sub[mn[x<<1]]<sub[mn[x<<1|1]]?mn[x<<1]:mn[x<<1|1]);
}
void build(int l,int r,int rt)
{
	if(l==r){mx[rt]=mn[rt]=l;return;}
	int mid=(l+r)>>1;
	build(l,mid,rt<<1);build(mid+1,r,rt<<1|1);
	pushup(rt);
}
void update(int l,int r,int rt,int p)
{
	if (l==r) return;
	if (p<=l+(r-l)/2) update(l,l+(r-l)/2,rt<<1,p); else update(l+(r-l)/2+1,r,rt<<1|1,p);
	pushup(rt);
}

signed main()
{
	n=read(),t=read(),q=read();
	for (int i=1;i<=n;i++) p[i]=read();
	for (int i=1;i<=n;i++) l[i]=read();
	for (int i=1;i<=n;i++) work(i);	
	build(1,n,1);
	for(int x,i=1;i<=t;i++) 
	{
		ans+=add[x=mx[1]];
		a[x]++,work(x);
		update(1,n,1,x);
	}
	for(int x,y,i=1;i<=q;i++)
	{
		x=read(),y=read();
		ans-=p[y]*min(1.0*a[y]/(l[y]+a[y]),0.5);
		if(x==1) l[y]++;else l[y]--;
		ans+=p[y]*min(1.0*a[y]/(l[y]+a[y]),0.5);
		work(y);update(1,n,1,y);
		for(;;)
		{
			x=mx[1];y=mn[1];
			if(add[x]-sub[y]>0)
			{
				ans+=add[x]-sub[y];
				a[x]++;
				a[y]--;
				work(x);work(y);
				update(1,n,1,x);
				update(1,n,1,y);
			}
			else break;
		}
		printf("%.10lf\n",ans);
	}
}
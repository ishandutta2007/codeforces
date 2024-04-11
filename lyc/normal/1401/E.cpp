#include<bits/stdc++.h>
#define int long long 
#define N 1000005
#define nmsl mm+=0
using namespace std;
int n,m,x,y,z,l[N],r[N],u[N],d[N],cnt,ans,tree[N<<2],mm;
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
inline void writeln(int a){
    if(a<0){
    	a=-a; putchar('-');
    }
    write(a); puts("");
}

struct sxy
{
	int p,v;
}h[N];
bool Cmp(sxy aa,sxy bb)
{
	return aa.v<bb.v;
}
bool Cmp1(sxy aa,sxy bb)
{
	return aa.v>bb.v;
}
    int lowbit(int k)
    {
        return k & -k;
    }
    void ad(int x,int k)
    {
        while(x<=N)
        {
            tree[x]+=k;
            x+=lowbit(x);
        }
    }
    int getsm(int x)
    {
        int ans=0;
        while(x!=0)
        {
            ans+=tree[x];
            x-=lowbit(x);
        }
        return ans;
    }
signed main()
{
	n=read(),m=read();nmsl;nmsl;nmsl;nmsl;
	for (int i=1;i<1000000;i++)
	{
		l[i]=d[i]=0;
		r[i]=u[i]=1000000;
	}nmsl;nmsl;nmsl;nmsl;
	for (int i=1;i<=n;i++)
	{
		x=read(),y=read(),z=read();
		if (z==1000000) r[x]=min(r[x],y);
		if (y==0) l[x]=max(l[x],z);
	}nmsl;nmsl;nmsl;nmsl;
	for (int i=1;i<=m;i++)
	{
		x=read(),y=read(),z=read();
		if (z==1000000) u[x]=min(u[x],y);
		if (y==0) d[x]=max(d[x],z);
	}nmsl;nmsl;nmsl;nmsl;
	for(int i=1;i<1000000;++i)
    {
        if(l[i]>=r[i])
        {
            ++ans;l[i]=1000000;
            r[i]=1000000;
        }
        if(d[i]>=u[i])
        {
            ++ans;d[i]=1000000;
            u[i]=1000000;
        }
        
    }nmsl;nmsl;nmsl;nmsl;nmsl;nmsl;
	for (int i=1;i<1000000;i++)
	{
		h[i].p=i;
		h[i].v=l[i];
		ad(i,1);
    }nmsl;nmsl;nmsl;nmsl;nmsl;
	sort(h+1,h+1000000,Cmp);
	cnt=0;
	for (int i=1;i<1000000;i++)
	{
		while (++cnt<1000000&h[cnt].v<i)
		{
			ad(h[cnt].p,-1);
		}
		cnt--;
		ans+=getsm(d[i])+getsm(1000000)-getsm(u[i]-1);
	}memset(tree,0,sizeof(tree));
	for (int i=1;i<1000000;i++)
	{
		h[i].p=i;
		h[i].v=r[i];
		ad(i,1);
	}
	nmsl;nmsl;nmsl;nmsl;nmsl;
	sort(h+1,h+1000000,Cmp1);
    cnt=0;
    nmsl;nmsl;nmsl;nmsl;nmsl;nmsl;
    for(int i=999999;i;--i)
    {
        while(++cnt<1000000&&h[cnt].v>i)
        {
            ad(h[cnt].p,-1);
        }
        --cnt;
        ans+=getsm(d[i]);
        ans+=getsm(1000000)-getsm(u[i]-1);
    }
    cout<<ans+1<<endl;
    nmsl;
}
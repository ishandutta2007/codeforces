//QwQcOrZ yyds!!!
#include<bits/stdc++.h>
#define mid (l+(r-l)/2)
#define N 500005

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

int n,q,sum[N][27],lazy[N],now[27],l,r,k;

char ch;

void push_down(int rt,int l,int r)
{
	if (lazy[rt]==0) return;
	for (int i=1;i<=26;i++)
	  sum[rt<<1][i]=0;
	sum[rt<<1][lazy[rt]]=mid-l+1;
	for (int i=1;i<=26;i++)
	  sum[rt<<1|1][i]=0;
	sum[rt<<1|1][lazy[rt]]=r-mid;
	lazy[rt<<1]=lazy[rt<<1|1]=lazy[rt];
	lazy[rt]=0;
}

void push_up(int rt)
{
    for (int i=1;i<=26;i++) sum[rt][i]=sum[rt<<1|1][i]+sum[rt<<1][i];
}

void update(int rt,int l,int r,int l1,int r1,int val)
{
	//cout<<rt<<" "<<l<<" "<<r<<" "<<l1<<" "<<r1<<endl;
	if (l>r) return;
	if (l>=l1&&r<=r1)
	{
		for (int i=1;i<=26;i++)
		  sum[rt][i]=0;
		sum[rt][val]=r-l+1;
		lazy[rt]=val;
		return;
	}
	push_down(rt,l,r);
	if (l1<=mid) update(rt<<1,l,mid,l1,r1,val);
	if (r1>mid) update(rt<<1|1,mid+1,r,l1,r1,val);
	push_up(rt);
}

void query(int rt,int l,int r,int l1,int r1)
{
	if (l>r) return;
	if (l>=l1&&r<=r1)
	{
		for (int i=1;i<=26;i++)
		  now[i]+=sum[rt][i];
		return;
	}
	push_down(rt,l,r);
	if (l1<=mid) query(rt<<1,l,mid,l1,r1);
	if (r1>mid) query(rt<<1|1,mid+1,r,l1,r1);
	push_up(rt);
}

void query1(int rt,int l,int r,int tp)
{
	if (l>r) return;
    if (l==r&&l==tp)
	{
	    for (int i=1;i<=26;i++)
	       if (sum[rt][i]) cout<<(char)('a'+i-1);
	    return;
	}
	push_down(rt,l,r);
	if (tp<=mid) query1(rt<<1,l,mid,tp);
	if (tp>mid) query1(rt<<1|1,mid+1,r,tp);
	push_up(rt);
}

signed main()
{
    n=read(),q=read();
    for (int i=1;i<=n;i++) cin>>ch,update(1,1,n,i,i,ch-'a'+1);
    for (int i=1;i<=q;i++)
    {
	    l=read(),r=read(),k=read();
	    for (int i=1;i<=26;i++) now[i]=0;
	    query(1,1,n,l,r);
	    if (k)
		    for (int i=1;i<=26;i++)
	    	{
	    		if (now[i]) update(1,1,n,l,l+now[i]-1,i);
	    		l+=now[i];
	    	}
	    else
	        for (int i=26;i>=1;i--)
	    	{
			    if (now[i]) update(1,1,n,l,l+now[i]-1,i);
	    		l+=now[i];
	    	}
	}
	for (int i=1;i<=n;i++)
	  query1(1,1,n,i);
}
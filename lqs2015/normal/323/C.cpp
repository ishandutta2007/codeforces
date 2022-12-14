#include<bits/stdc++.h>
using namespace std;
const int maxn=1000;
char buffer[maxn],*S,*T;
inline char Get_Char()
{
    if(S==T)
    {
        T=(S=buffer)+fread(buffer,1,maxn,stdin);
        if(S==T) return EOF;
    }
    return *S++;
}
int read()
{
    char c;
    int re=0,f=0;
    for(c=Get_Char();c<'0'||c>'9';c=Get_Char())
    {
    	if (c=='-') f=1;
	}
    while(c>='0'&&c<='9')
           re=re*10+(c&15),c=Get_Char();
    if (f) return -re;
    return re;
}
int n,p[1111111],q[1111111],pos[1111111],m,lans,a,b,c,d,l1,r1,l2,r2;
struct hjt
{
	int tree[22222222],ls[22222222],rs[22222222],rt[1111111],sz;
	void update(int x,int l,int r,int pre,int &nw)
	{
		nw=++sz;tree[nw]=tree[pre]+1;
		ls[nw]=ls[pre];rs[nw]=rs[pre];
		if (l==r) return;
		int mid=(l+r)>>1;
		if (x>mid) update(x,mid+1,r,rs[pre],rs[nw]);
		else update(x,l,mid,ls[pre],ls[nw]);
	}
	int query(int beg,int en,int l,int r,int pre,int nw)
	{
		if (l>en || r<beg) return 0;
		if (l>=beg && r<=en) return tree[nw]-tree[pre];
		int mid=(l+r)>>1;
		return query(beg,en,l,mid,ls[pre],ls[nw])+query(beg,en,mid+1,r,rs[pre],rs[nw]);
	}
}ht;
int main()
{
	n=read();
	for (int i=1;i<=n;i++) p[i]=read();
	for (int i=1;i<=n;i++) q[i]=read();
	for (int i=1;i<=n;i++) pos[q[i]]=i;
	for (int i=1;i<=n;i++)
	{
		ht.update(pos[p[i]],1,n,ht.rt[i-1],ht.rt[i]);
	}
	m=read();
	for (int i=1;i<=m;i++)
	{
		a=read();b=read();c=read();d=read();
		a=(a-1+lans)%n+1;b=(b-1+lans)%n+1;c=(c-1+lans)%n+1;d=(d-1+lans)%n+1;
		l1=min(a,b);r1=max(a,b);l2=min(c,d);r2=max(c,d);
		lans=ht.query(l2,r2,1,n,ht.rt[l1-1],ht.rt[r1]);
		printf("%d\n",lans);
		lans++;
	}
	return 0;
}
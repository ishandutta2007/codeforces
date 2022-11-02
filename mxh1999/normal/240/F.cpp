#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void read(int &digit)
{
	digit=0;
	char c;
	for (c=getchar();(c<'0' || c>'9') && c!='-';c=getchar());
	bool type=false;
	if (c=='-')
		type=true,c=getchar();
	for (;c>='0' && c<='9';digit=digit*10+c-'0',c=getchar());
	if (type==true)
		digit=-digit;
}

#define maxn 100010
struct Seg
{
	int num[26];
	int tag;
}	seg[maxn<<2];
int n,m;
char s[maxn];
int mjy[26];
void addtag(int t,int l,int r,int val)
{
	memset(seg[t].num,0,sizeof(seg[t].num));
	seg[t].num[val]=r-l+1;
	seg[t].tag=val;
}
void update(int t)
{
	for (int i=0;i<26;i++)	seg[t].num[i]=seg[t<<1].num[i]+seg[t<<1|1].num[i];
}
void pushdown(int t,int l,int r)
{
	if (seg[t].tag!=-1)
	{
		int mid=(l+r)>>1;
		addtag(t<<1,l,mid,seg[t].tag);
		addtag(t<<1|1,mid+1,r,seg[t].tag);
		seg[t].tag=-1;
	}
}
void build(int t,int l,int r)
{
	seg[t].tag=-1;
	if (l==r)
	{
		seg[t].num[s[l]-'a']=1;
		return;
	}
	int mid=(l+r)>>1;
	build(t<<1,l,mid);
	build(t<<1|1,mid+1,r);
	update(t);
}
void query(int t,int l,int r,int ql,int qr)
{
	if (l==ql && r==qr)
	{
		for (int i=0;i<26;i++)	mjy[i]+=seg[t].num[i];
		return;
	}
	pushdown(t,l,r);
	int mid=(l+r)>>1;
	if (qr<=mid)	query(t<<1,l,mid,ql,qr);else
	if (ql>mid)	query(t<<1|1,mid+1,r,ql,qr);else
	query(t<<1,l,mid,ql,mid),query(t<<1|1,mid+1,r,mid+1,qr);
}
void change(int t,int l,int r,int ql,int qr,int val)
{
	if (l==ql && r==qr)
	{
		addtag(t,l,r,val);
		return;
	}
	pushdown(t,l,r);
	int mid=(l+r)>>1;
	if (qr<=mid)	change(t<<1,l,mid,ql,qr,val);else
	if (ql>mid)	change(t<<1|1,mid+1,r,ql,qr,val);else
	change(t<<1,l,mid,ql,mid,val),change(t<<1|1,mid+1,r,mid+1,qr,val);
	update(t);
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	read(n);read(m);
	for (int i=1;i<=n;i++)
	{
		char ch=getchar();
		while (!(ch<='z' && ch>='a'))	ch=getchar();
		s[i]=ch;
	}
	build(1,1,n);
	for (int i=1;i<=m;i++)
	{
		int l,r;
		read(l),read(r);
		memset(mjy,0,sizeof(mjy));
		query(1,1,n,l,r);
		int cnt=0,pos=0;
		for (int i=0;i<26;i++)
		if (mjy[i]&1)	cnt++,pos=i;
		if (cnt<1 || (cnt==1 && ((r-l+1)&1)))
		{
			for (int i=0;i<26;i++)
			if (mjy[i]>1)
			{
				change(1,1,n,l,l+mjy[i]/2-1,i);
				change(1,1,n,r-mjy[i]/2+1,r,i);
				l+=mjy[i]/2;
				r-=mjy[i]/2;
			}
			if ((r-l+1)&1)	change(1,1,n,l,l,pos);
		}
	}
	for (int i=1;i<=n;i++)
	{
		memset(mjy,0,sizeof(mjy));
		query(1,1,n,i,i);
		for (int i=0;i<26;i++)
		if (mjy[i])	putchar((char)(i+'a'));
	}
	putchar('\n');
	return 0;
}
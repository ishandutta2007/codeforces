//~~
#include<bits/stdc++.h>
#define poly vector<int>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define mt make_tuple
#define pa pair < int,int >
#define fi first
#define se second
#define inf 1e18
#define mod 998244353
#define int ll
#define N 200005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int tag[N<<5];
int dep[N<<5];
int h0[N<<5];
int h1[N<<5];
int ch[N<<5][2];
int sum[N<<5];
int tot;
int n,q;
int rt;
int B=(1<<20)-1;
void Xor(int x,int y)
{
	tag[x]^=y;
	int p=h0[x]&y,pp=h1[x]&y;
	if (dep[x]>=0&&((y>>dep[x])&1)) swap(ch[x][0],ch[x][1]);
	h0[x]=pp|(h0[x]&(B^y));
	h1[x]=p|(h1[x]&(B^y));
}
void pushdown(int k)
{
	if (!tag[k]) return;
	Xor(ch[k][0],tag[k]);
	Xor(ch[k][1],tag[k]);
	tag[k]=0;
}
void pushup(int k)
{
	sum[k]=sum[ch[k][0]]+sum[ch[k][1]];
	h0[k]=h0[ch[k][0]]|h0[ch[k][1]]|((ch[k][0])?(1<<dep[k]):0);
	h1[k]=h1[ch[k][0]]|h1[ch[k][1]]|((ch[k][1])?(1<<dep[k]):0);
}
void ins(int &now,int val,int nowdp)
{
	if (!now)
	{
		now=++tot;dep[now]=nowdp;
		if (nowdp<0) sum[now]=1;
	}
	if (nowdp<0) return;
	pushdown(now);
	int x=(val>>nowdp)&1;
	ins(ch[now][x],val,nowdp-1);
	pushup(now);
}
int split(int &now,int l,int r,int L,int R)
{
	if (!now) return 0;
	if (L<=l&&r<=R) 
	{
		int p=now;
		now=0;
		return p;
	}
	int res=++tot;
	dep[res]=dep[now];
	int mid=l+(r-l)/2;
	pushdown(now);
	if (L<=mid)
	ch[res][0]=split(ch[now][0],l,mid,L,R);
	if (R>mid)
	ch[res][1]=split(ch[now][1],mid+1,r,L,R);
	pushup(res);
	pushup(now);
	return res;
}
void merge(int &x,int &y)
{
	if (!x||!y) return x=x|y,y=0,void();
	if (dep[x]<0)
	{
		y=0;
		return;
	}
	pushdown(x);
	pushdown(y);
	merge(ch[x][0],ch[y][0]);
	merge(ch[x][1],ch[y][1]);
	pushup(x);
	// cout<<x<<" "<<y<<" "<<sum[x]<<endl;
	y=0;
}
void Or(int now,int x)
{
	if (!now) return;
	// cout<<now<<" "<<x<<" "<<dep[now]<<" "<<h0[now]<<" "<<h1[now]<<" "<<sum[now]<<endl;
	if (dep[now]<0) return;
	pushdown(now);
	if (!(h0[now]&h1[now]&x))
	{
		Xor(now,x&h0[now]);
		return;
	}
	if ((x>>dep[now])&1)
	{
		Xor(ch[now][0],(1<<dep[now]));
		merge(ch[now][1],ch[now][0]);
	}
	Or(ch[now][0],x);
	Or(ch[now][1],x);
	pushup(now);
	// cout<<now<<" "<<x<<" "<<dep[now]<<" "<<h0[now]<<" "<<h1[now]<<" "<<sum[now]<<endl;
}
void BellaKira()
{
	n=read(),q=read();
	for (int i=1;i<=n;i++) ins(rt,read(),19);
	// return;
	for (int i=1;i<=q;i++)
	{
		int opt=read();
		if (opt==1)
		{
			int l=read(),r=read(),x=read();
			// cout<<"?"<<sum[rt]<<endl;
			int now=split(rt,0,B,l,r);
			Xor(now,B);
			Or(now,x^B);
			Xor(now,B);
			merge(rt,now);
			// cout<<"?"<<sum[rt]<<endl;
		} else
		if (opt==2)
		{
			int l=read(),r=read(),x=read();
			int now=split(rt,0,B,l,r);
			Or(now,x);
			merge(rt,now);
		} else
		if (opt==3)
		{
			int l=read(),r=read(),x=read();
			int now=split(rt,0,B,l,r);
			Xor(now,x);
			merge(rt,now);
		} else
		if (opt==4)
		{
			int l=read(),r=read();
			int now=split(rt,0,B,l,r);
			writeln(sum[now]);
			merge(rt,now);
		}
		// return;
	}
}
signed main()
{
	int T=1;
	while (T--)
	{
		BellaKira();
	}
}
/*

*/
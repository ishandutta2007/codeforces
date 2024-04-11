#include <set>
#include <map>
#include <ctime>
#include <cmath>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
#define sz size
#define fi first
#define se second
#define mp make_pair
#define pb push_back
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
#define maxn 300010
struct Line
{
	int k,b;
	int l,r;
	ll val(int x)
	{
		return 1LL*k*x+b;
	}
}	a[maxn];
int ha[maxn];
struct Ques
{
	int pos,num;
	int id;
}	ques[maxn];
int num[maxn];
int n,m,q;
int cnt;

int _a[20][maxn],_b[20][maxn];
int root[20];
ll mjy[maxn];
bool in(int l,int r,int ql,int qr)
{
	if (l>ql) swap(l,ql),swap(r,qr);
	return (ql<=r);
}
struct Seg
{
	int son[2];
	int tag;
}	seg[5000010];
int tot;
int insert(int pre,int l,int r,int pos)
{
	int now=++tot;
	seg[now]=seg[pre];
	if (seg[now].tag==0)
	{
		seg[now].tag=pos;
		return now;
	}
	if (l==r)
	{
		if (a[seg[now].tag].val(num[l])<a[pos].val(num[l]))	seg[now].tag=pos;
		return now;
	}
	int mid=(l+r)>>1;
	ll v1=a[pos].val(num[l]),_v1=a[seg[now].tag].val(num[l]);
	ll v2=a[pos].val(num[mid]),_v2=a[seg[now].tag].val(num[mid]);
	ll v3=a[pos].val(num[r]),_v3=a[seg[now].tag].val(num[r]);
	if (_v1>=v1 && _v3>=v3)	return now;
	if (_v1<v1 && _v3<v3)	{seg[now].tag=pos;return now;}
	if (_v2<v2)	swap(seg[now].tag,pos),swap(_v1,v1),swap(_v2,v2),swap(_v3,v3);
	if (_v1<v1) seg[now].son[0]=insert(seg[pre].son[0],l,mid,pos);
	if (_v3<v3) seg[now].son[1]=insert(seg[pre].son[1],mid+1,r,pos);
	return now;
}
int mxh;
void query(int t,int l,int r,int pos)
{
	if (seg[t].tag!=0)
	{
		if (mxh==0)	mxh=seg[t].tag;else
		if (a[mxh].val(num[pos])<a[seg[t].tag].val(num[pos])) mxh=seg[t].tag;
	}
	if (l==r)	return;
	int mid=(l+r)>>1;
	if (pos<=mid)	query(seg[t].son[0],l,mid,pos);else
	query(seg[t].son[1],mid+1,r,pos);
}
void solve(int l,int r,int dep)
{
	if (_b[dep][0]==0)	return;
	for (int i=1;i<=_a[dep][0];i++)
	if (a[_a[dep][i]].l<=l && a[_a[dep][i]].r>=r)
		root[dep]=insert(root[dep],1,cnt,_a[dep][i]);
	if (l==r)
	{
		for (int i=1;i<=_b[dep][0];i++)
		{
			mxh=0;
			query(root[dep],1,cnt,ques[_b[dep][i]].num);
			mjy[ques[_b[dep][i]].id]=mxh;
		}
		return;
	}
	int mid=(l+r)>>1;
	int _tot=tot;
	root[dep+1]=root[dep];
	_a[dep+1][0]=_b[dep+1][0]=0;
	for (int i=1;i<=_a[dep][0];i++)
	if (!(a[_a[dep][i]].l<=l && a[_a[dep][i]].r>=r) && in(l,mid,a[_a[dep][i]].l,a[_a[dep][i]].r))
		_a[dep+1][++_a[dep+1][0]]=_a[dep][i];
	for (int i=1;i<=_b[dep][0];i++)
	if (ques[_b[dep][i]].pos<=mid)	_b[dep+1][++_b[dep+1][0]]=_b[dep][i];
	solve(l,mid,dep+1);
	tot=_tot;
	root[dep+1]=root[dep];
	_a[dep+1][0]=_b[dep+1][0]=0;
	for (int i=1;i<=_a[dep][0];i++)
	if (!(a[_a[dep][i]].l<=l && a[_a[dep][i]].r>=r) && in(mid+1,r,a[_a[dep][i]].l,a[_a[dep][i]].r))
		_a[dep+1][++_a[dep+1][0]]=_a[dep][i];
	for (int i=1;i<=_b[dep][0];i++)
	if (ques[_b[dep][i]].pos>mid)	_b[dep+1][++_b[dep+1][0]]=_b[dep][i];
	solve(mid+1,r,dep+1);
	tot=_tot;
}
int main()
{
	read(m);
	for (int i=1;i<=m;i++)
	{
		int op,x,y;
		read(op);
		if (op==1)
		{
			read(x),read(y);
			n++;
			a[n].k=x,a[n].b=y;
			a[n].l=i,a[n].r=m;
			ha[i]=n;
		}	else
		if (op==2)
		{
			read(x);
			a[ha[x]].r=i;
		}	else
		if (op==3)
		{
			q++;
			ques[q].id=q;
			ques[q].pos=i;
			read(ques[q].num);
			num[++cnt]=ques[q].num;
		}
	}
	sort(num+1,num+cnt+1);
	cnt=unique(num+1,num+cnt+1)-num-1;
	for (int i=1;i<=q;i++)	ques[i].num=lower_bound(num+1,num+cnt+1,ques[i].num)-num;
	_a[0][0]=n;_b[0][0]=q;
	for (int i=1;i<=n;i++)	_a[0][i]=i;
	for (int i=1;i<=q;i++)	_b[0][i]=i;
	solve(1,m,0);
	for (int i=1;i<=q;i++)
	{
		if (mjy[i]==0)	printf("EMPTY SET\n");else
		printf("%I64d\n",a[mjy[i]].val(num[ques[i].num]));
	}
	return 0;
}
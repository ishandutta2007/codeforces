#include<bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;
typedef long long ll;
void read(ll &digit)
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

#define maxn 1010
struct Point
{
	ll x,y;
	ll val;
}	a[maxn*maxn];
ll b[maxn][maxn];
bool vis[maxn][maxn];
const int dx[4]={1,0,-1,0};
const int dy[4]={0,1,0,-1};
ll tot;
ll n,m;
ll k;
ll xmm[maxn*maxn];
ll mjy[maxn][maxn];
ll f[maxn*maxn],size[maxn*maxn];
bool mxh[maxn][maxn];
queue<pair<int,int> >	Q;

bool cmp(Point a,Point b)
{
	return a.val>b.val;
}
ll fa(ll t)
{
	if (f[t]==t)	return t;
	return f[t]=fa(f[t]);
}
void Union(ll x1,ll y1,ll x2,ll y2)
{
	if (x1<1 || y1<1 || x1>n || y2>m)	return;
	ll num1=(x1-1)*m+y1,num2=(x2-1)*m+y2;
	num1=fa(num1),num2=fa(num2);
	if (num1==num2)	return;
	f[num1]=num2,size[num2]+=size[num1];
}
void outit(ll fat,ll sz,ll num,ll _x,ll _y)
{
	Q.push(mp(_x,_y));
	mxh[_x][_y]=true;
	while (sz)
	{
		int x=Q.front().fi,y=Q.front().se;
		Q.pop();
		mjy[x][y]=num;
		sz--;
		for (int _=0;_<4;_++)
		{
			int __x=x+dx[_],__y=y+dy[_];
			if (__x<1 || __x>n || __y<1 || __y>m)	continue;
			if (mxh[__x][__y])	continue;
			int num1=(__x-1)*m+__y;
			if (num1<=0)	continue;
			num1=fa(num1);
			if (num1==fat)
			{
				mxh[__x][__y]=true;
				//cerr<<":"<<__x<<" "<<__y<<endl;
				Q.push(mp(__x,__y));
			}
		}
	}
	for (ll i=1;i<=n;i++)
	{
		for (ll j=1;j<=m;j++)	printf("%I64d ",mjy[i][j]);
		printf("\n");
	}
}
int main()
{
	read(n),read(m),read(k);
	for (ll i=1;i<=n;i++)
		for (ll j=1;j<=m;j++)
		{
			read(b[i][j]);
			tot++;
			a[tot].x=i,a[tot].y=j,a[tot].val=b[i][j];
		}
	sort(a+1,a+tot+1,cmp);
	for (ll i=1;i<=tot;i++)
	{
		ll x=a[i].x,y=a[i].y;
		vis[x][y]=true;
		ll num=(x-1)*m+y;
		f[num]=num,size[num]=1;
		if (vis[x-1][y])	Union(x-1,y,x,y);
		if (vis[x+1][y])	Union(x+1,y,x,y);
		if (vis[x][y-1])	Union(x,y-1,x,y);
		if (vis[x][y+1])	Union(x,y+1,x,y);
		num=fa(num);
		if (k%a[i].val==0)
		{
			ll q=k/a[i].val;
			if (q<=size[num])
			{
				printf("YES\n");
				outit(num,q,a[i].val,a[i].x,a[i].y);
				return 0;
			}
		}
	}
	printf("NO\n");
	return 0;
}
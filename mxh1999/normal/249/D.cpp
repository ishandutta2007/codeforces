#include<bits/stdc++.h>
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

typedef double db;
const db eps=1e-9;
#define maxn 100010
ll n,a,b,c,d;
struct Point
{
	db x,y,id;
	int pos;
}	s[maxn];
int mxhx[maxn],mxhy[maxn];
bool cmp(Point a,Point b)
{
	if (fabs(a.x-b.x)>eps)	return a.x<b.x;
	return a.y>b.y;
}
db num[maxn];
int cnt;
int ca[maxn],f[maxn];

int query(int t)
{
	int mjy=0;
	for (int i=t;i;i-=i&(-i))	mjy=max(mjy,ca[i]);
	return mjy;
}
int insert(int t,int val)
{
	for (int i=t;i<=cnt;i+=i&(-i))	ca[i]=max(ca[i],val);
}
int main()
{
	//freopen("249D.in","r",stdin);
	read(n);
	read(a),read(b),read(c),read(d);
	db len1=sqrt(a*a+b*b),len2=sqrt(c*c+d*d);
	n++;
	for (int i=1;i<=n;i++)
	{
		ll x0,y0;
		if (i!=n)	read(x0),read(y0);else x0=y0=0;
		mxhx[i]=x0,mxhy[i]=y0;
		ll fz=c*x0-d*y0;
		ll fm=b*c-a*d;
		s[i].x=len1*(db)fz/fm;
		fz=a*x0-b*y0;
		fm=a*d-b*c;
		s[i].y=len2*(db)fz/fm;
		num[i]=s[i].y;
		s[i].id=i;
	}
	sort(num+1,num+n+1);
	cnt=1;
	for (int i=2;i<=n;i++)
	if (num[i]-num[cnt]>eps)	num[++cnt]=num[i];
	sort(s+1,s+n+1,cmp);
	for (int i=1;i<=n;i++)	s[i].pos=lower_bound(num+1,num+cnt+1,s[i].y-eps)-num;
	for (int i=1;i<=n;i++)
	{
		f[i]=query(s[i].pos-1)+1;
		if (s[i].id==n || f[i]>1)	insert(s[i].pos,f[i]);
	}
	int mjy=0;
	for (int i=1;i<=n;i++)	mjy=max(mjy,f[i]-1);
	printf("%d\n",mjy);
	return 0;
}
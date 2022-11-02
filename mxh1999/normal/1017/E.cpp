#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
struct Point
{
	ll x,y;
	Point(ll _x=0,ll _y=0):x(_x),y(_y){}
};
Point operator-(const Point &a,const Point &b)
{
	return Point(a.x-b.x,a.y-b.y);
}
Point operator+(const Point &a,const Point &b)
{
	return Point(a.x+b.x,a.y+b.y);
}
Point operator*(const Point &a,const double &k)
{
	return Point(a.x*k,a.y*k);
}
Point operator/(const Point &a,const double &k)
{
	return Point(a.x/k,a.y/k);
}
bool operator<(const Point &a,const Point &b)
{
	if (a.x!=b.x)	return a.x<b.x;
	return a.y<b.y;
}
int sgn(ll x)
{
	return (x>0)-(x<0);
}
ll dot(const Point &a,const Point &b)
{
	return a.x*b.x+a.y*b.y;
}
ll det(const Point &a,const Point &b)
{
	return a.x*b.y-a.y*b.x;
}
bool turn_left(const Point &a,const Point &b,const Point &c)
{
	return sgn (det (b - a, c - a)) >= 0;
}

vector<Point> convex_hull(std::vector<Point> a)
{
	int cnt=0;
	sort(a.begin(),a.end());
	static vector<Point> ret;
	ret.resize(a.size()<<1);
	for (int i=0;i<a.size();++i)
	{
		while (cnt>1 && turn_left(ret[cnt-2],a[i],ret[cnt-1]))
			--cnt; 
		ret[cnt++]=a[i];
	}
	int fixed=cnt;
	for (int i=(int)a.size()-1;i>=0;i--)
	{
		while (cnt>fixed && turn_left(ret[cnt-2],a[i],ret[cnt-1])) cnt--;
		ret[cnt++]=a[i];
	}
	return vector<Point>(ret.begin(),ret.begin()+cnt-1);
}

int doit(ll *s, int l)
{  
	int i,j,k;
	i=0;j=1;k=0;
	while(i<l&&j<l)
	{
		k=0;
		while(s[i+k]==s[j+k]&&k<l) k++;
		if(k==l) return i;
		if(s[i+k]>s[j+k]) 
		 if(i+k+1>j) i=i+k+1;
		 else i=j+1;
		else if(j+k+1>i) j=j+k+1;
		else  j=i+1; 
	}
	if(i<l) return i;
	else return j;
}

const int maxn=100010;
int n,m;
vector<Point> a,b;
vector<Point> la,lb;
ll que1[maxn*3],que2[maxn*3];

int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		a.push_back(Point(x,y));
	}
	for (int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		b.push_back(Point(x,y));
	}
	la=convex_hull(a);
	lb=convex_hull(b);
	if (la.size()!=lb.size())
	{
		printf("NO\n");
		return 0;
	}
	int cnt1=0;
	int cnt2=0;
	for (int i=0;i<la.size();i++)
	{
		Point r=la[(i+1)%la.size()]-la[i];
		Point l=la[(i-1+la.size())%la.size()]-la[i];
		que1[cnt1++]=dot(l,r);
		que1[cnt1++]=det(l,r);
		que1[cnt1++]=r.x*r.x+r.y*r.y;
	}
	for (int i=0;i<lb.size();i++)
	{
		Point r=lb[(i+1)%lb.size()]-lb[i];
		Point l=lb[(i-1+lb.size())%lb.size()]-lb[i];
		que2[cnt2++]=dot(l,r);
		que2[cnt2++]=det(l,r);
		que2[cnt2++]=r.x*r.x+r.y*r.y;
	}
	int qwq1=doit(que1,cnt1);
	int qwq2=doit(que2,cnt2);
	for (int i=1;i<=cnt1;i++)
	{
		if (que1[qwq1]!=que2[qwq2])
		{
			printf("NO\n");
			return 0;
		}
		qwq1=(qwq1+1)%cnt1;
		qwq2=(qwq2+1)%cnt2;
	}
	printf("YES\n");
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
const int maxn=100000;
int n,x,y,z,pos,sz,cnt,cf;
struct point
{
	int x,y;
	bool operator == (const point &u) const
	{
		return (x==u.x && y==u.y);
	}
}p[1111111],o,xx,yy,A,B,C;
double r,R,la,lb,lc,alpha;
vector<point> v;
point operator + (point a,point b) 
{
	return (point){a.x+b.x,a.y+b.y};
}
point operator - (point a,point b) 
{
	return (point){a.x-b.x,a.y-b.y};
}
long long cross(point a,point b)
{
	return (1ll*a.x*b.y-1ll*b.x*a.y);
}
double len(point a)
{
	return sqrt((double)a.x*(double)a.x+(double)a.y*(double)a.y);
}
bool cmp(point a,point b)
{
	if (cross(a-o,b-o)) return cross(a-o,b-o)>0;
	if (a.x!=b.x) return a.x<b.x;
	return a.y<b.y;
}
void chk(point a,point b,point c)
{
	la=len(b-c);lb=len(a-c);lc=len(a-b);
	alpha=acos((lb*lb+lc*lc-la*la)/2.00/lb/lc);
	r=la/sin(alpha);
	if (r>R)
	{
		R=r;
		A=a;B=b;C=c;
	}
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		if (x+z<=maxn) p[++cnt]=(point){x+z,y};
		else 
		{
			cf=x+z-maxn;
			if (y+cf<=maxn) p[++cnt]=(point){maxn,y+cf};
			else p[++cnt]=(point){maxn,maxn};
			if (y-cf>=0) p[++cnt]=(point){maxn,y-cf};
			else p[++cnt]=(point){maxn,0};
		}
		if (x-z>=0) p[++cnt]=(point){x-z,y};
		else
		{
			cf=-(x-z);
			if (y+cf<=maxn) p[++cnt]=(point){0,y+cf};
			else p[++cnt]=(point){0,maxn};
			if (y-cf>=0) p[++cnt]=(point){0,y-cf};
			else p[++cnt]=(point){0,0};
		}
		if (y+z<=maxn) p[++cnt]=(point){x,y+z};
		else 
		{
			cf=y+z-maxn;
			if (x+cf<=maxn) p[++cnt]=(point){x+cf,maxn};
			else p[++cnt]=(point){maxn,maxn};
			if (x-cf>=0) p[++cnt]=(point){x-cf,maxn};
			else p[++cnt]=(point){0,maxn};
		}
		if (y-z>=0) p[++cnt]=(point){x,y-z};
		else
		{
			cf=-(y-z);
			if (x+cf<=maxn) p[++cnt]=(point){x+cf,0};
			else p[++cnt]=(point){maxn,0};
			if (x-cf>=0) p[++cnt]=(point){x-cf,0};
			else p[++cnt]=(point){0,0};
		}
	}
	n=cnt;pos=1;
	for (int i=2;i<=n;i++)
	{
		if (p[i].x<p[pos].x || (p[i].x==p[pos].x && p[i].y<p[pos].y)) pos=i;
	}
	swap(p[1],p[pos]);o=p[1];
	sort(p+2,p+n+1,cmp);v.push_back(p[1]);
	for (int i=2;i<=n;i++)
	{
		if (p[i]==p[i-1]) continue;
		while(v.size()>1)
		{
			xx=v[(int)v.size()-1];yy=v[(int)v.size()-2];
			if (cross(p[i]-xx,xx-yy)>=0) v.pop_back();
			else break;
		}
		v.push_back(p[i]);
	}
	sz=v.size();R=-1e9;
	for (int i=0;i<sz;i++)
	{
		chk(v[i],v[(i+1)%sz],v[(i+2)%sz]);
	}
	printf("%d %d\n",A.x,A.y);
	printf("%d %d\n",B.x,B.y);
	printf("%d %d\n",C.x,C.y);
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
struct Point
{
	int x,y,id;
	bool operator <(const Point &a)const{
		if(y==a.y) return x<a.x;
		return y<a.y;
	}
}p[100005];
int n;
long long cross(Point a,Point b,Point c)
{
	return 1ll*(b.x-a.x)*(c.y-a.y)-1ll*(b.y-a.y)*(c.x-a.x);
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) 
	{
		scanf("%d%d",&p[i].x,&p[i].y);
		p[i].id=i;
	}
	sort(p+1,p+n+1);
	for(int i=3;i<=n;i++)
	if(cross(p[1],p[2],p[i])) 
	{
		printf("%d %d %d\n",p[1].id,p[2].id,p[i].id);
		break;
	}
}
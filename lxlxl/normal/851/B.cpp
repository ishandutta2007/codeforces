#include<set>
#include<map>
#include<deque>
#include<queue>
#include<stack>
#include<cmath>
#include<ctime>
#include<bitset>
#include<string>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<complex>
#include<iostream>
#include<algorithm>
#define ll long long
#define inf 1e9
using namespace std;

int n,m,k;
struct point
{
	int x,y;
}a,b,c;

bool Same(point x,point y){return x.x==y.x&&x.y==y.y;}

int main()
{
	scanf("%d%d",&a.x,&a.y);
	scanf("%d%d",&b.x,&b.y);
	scanf("%d%d",&c.x,&c.y);
	
	if(Same(a,b)&&Same(b,c)) puts("Yes");
	else
	{
		if(Same(a,b)||Same(b,c)||Same(a,c)) puts("No");
		else
		{
			point x,y;
			x.x=b.x-a.x,x.y=b.y-a.y;
			y.x=c.x-b.x,y.y=c.y-b.y;
			if((ll)x.x*x.x+(ll)x.y*x.y!=(ll)y.x*y.x+(ll)y.y*y.y) puts("No");
			else
			{
				if(x.x<0) x.x=-x.x,x.y=-x.y;
				if(y.x<0) y.x=-y.x,y.y=-y.y;
				
				if((ll)x.x*y.y==(ll)x.y*y.x) puts("No");
				else puts("Yes");
			}
		}
	}
	
	return 0;
}
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
using namespace std;

const int maxn = 20005;

int n;
int ans[maxn];
struct point
{
	int x,y,i,j;
}p[maxn],sta;
int mul(point x,point y,point z)
{
	x.x-=z.x,x.y-=z.y;
	y.x-=z.x,y.y-=z.y;
	return x.x*y.y-x.y*y.x;
}
inline bool cmp(const point a,const point b) { return mul(a,b,sta)>0; }
void Divide(int l,int r)
{
	if(l>r) return;
	int mn=-1;
	for(int i=l;i<=r;i++) if(mn==-1||p[mn].y>p[i].y)
		mn=i;
	swap(p[mn],p[l]);
	sta=p[l]; sort(p+l+1,p+r+1,cmp);
	int k=0;
	for(int i=l+1;i<=r;i++)
	{
		if(p[i].j!=p[l].j&&k==0) { k=i;break; }
		k+=p[i].j;
	}
	ans[min(p[l].i,p[k].i)]=max(p[l].i,p[k].i);
	Divide(l+1,k-1); Divide(k+1,r);
}

int main()
{
	//freopen("tmp.in","r",stdin);
	//freopen("tmp.out","w",stdout);
	
	scanf("%d",&n);
	for(int i=1;i<=2*n;i++) scanf("%d%d",&p[i].x,&p[i].y),p[i].i=i,p[i].j=i<=n?-1:1;
	
	Divide(1,2*n);
	for(int i=1;i<=n;i++) printf("%d\n",ans[i]-n);
	
	return 0;
}
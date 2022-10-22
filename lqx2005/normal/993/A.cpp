#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int INF=100000000;
struct point
{
	int x,y;
}a[4],b[4];
int xa,xb,ya,yb;
int bm,bn,km,kn;
void check()
{
	xa=ya=bn=kn=INF;
	xb=yb=bm=km=-INF;
	for(int i=0;i<=3;i++) 
	{
		xa=min(xa,a[i].x);
		xb=max(xb,a[i].x);
		ya=min(ya,a[i].y);
		yb=max(yb,a[i].y);
		bm=max(b[i].y-b[i].x,bm);
		bn=min(b[i].y-b[i].x,bn);
		km=max(b[i].y+b[i].x,km);
		kn=min(b[i].y+b[i].x,kn);
	}
	return;
}
bool checka(int x,int y)
{
	if(xa<=x&&x<=xb&&ya<=y&&y<=yb) return true;
	return false;
}
bool checkb(int x,int y)
{
	if(y>=x+bn&&y<=x+bm&&y>=kn-x&&y<=km-x) return true;
	return false;
}
int main()
{
	scanf("%d%d%d%d%d%d%d%d",&a[0].x,&a[0].y,&a[1].x,&a[1].y,&a[2].x,&a[2].y,&a[3].x,&a[3].y);
	scanf("%d%d%d%d%d%d%d%d",&b[0].x,&b[0].y,&b[1].x,&b[1].y,&b[2].x,&b[2].y,&b[3].x,&b[3].y);
	check();
	bool flag=0;
	for(int x=-100;x<=100;x++) for(int y=-100;y<=100;y++) if(checka(x,y)&&checkb(x,y)) flag=1;
	if(flag) printf("YES\n");
	else printf("NO\n");
	return 0;
}
#include<bits/stdc++.h>
using namespace std;int FLG;
struct node
{
	int x,y,id,o;
}a[300010],b[300010];
bool cmpx(const node A,const node B){return A.x<B.x;}
bool cmpy(const node A,const node B){return A.y<B.y;}
int P[4],n;
int chk1(int x)
{
	int r=0,i=1,lim,lim2;
	for (;i<=n && r<x;i++) if (a[i].id==P[1]) {r++,lim=a[i].x;}
	if (r<x) return 0;r=0;
	for (;i<=n && r<x;i++) if (a[i].x>lim && a[i].id==P[2]) {r++,lim2=a[i].x;}
	if (r<x) return 0;r=0;
	for (;i<=n && r<x;i++) if (a[i].x>lim2 && a[i].id==P[3]) {r++;}
	if (r<x) return 0;return 1;
}
int chk4(int x)
{
	int r=0,i=1,lim,lim2;
	for (;i<=n && r<x;i++) if (b[i].id==P[1]) {r++,lim=b[i].y;}
	if (r<x) return 0;r=0;
	for (;i<=n && r<x;i++) if (b[i].y>lim && b[i].id==P[2]) {r++,lim2=b[i].y;}
	if (r<x) return 0;r=0;
	for (;i<=n && r<x;i++) if (b[i].y>lim2 && b[i].id==P[3]) {r++;}
	if (r<x) return 0;return 1;
}
int chk2(int x)
{
	int r=0,i=1,lim,lim2;
	for (;i<=n && r<x;i++) if (a[i].id==P[1]) {r++,lim=a[i].x;}
	if (r<x) return 0;r=0;
	for (i=1;i<=n && r<x;i++) if (b[i].x>lim && b[i].id==P[2]) {r++,lim2=b[i].y;}
	if (r<x) return 0;r=0;
	for (;i<=n && r<x;i++) if (b[i].x>lim && b[i].y>lim2 && b[i].id==P[3]) {r++;}
	if (r<x) return 0;return 1;
}
int chk3(int x)
{
	int r=0,i=1,lim,lim2;
	for (i=n;i && r<x;i--) if (a[i].id==P[1]) {r++,lim=a[i].x;}
	if (r<x) return 0;r=0;
	for (i=1;i<=n && r<x;i++) if (b[i].x<lim && b[i].id==P[2]) {r++,lim2=b[i].y;}
	if (r<x) return 0;r=0;
	for (;i<=n && r<x;i++) if (b[i].x<lim && b[i].y>lim2 && b[i].id==P[3]) {r++;}
	if (r<x) return 0;return 1;
}
int chk5(int x)
{
	int r=0,i=1,lim,lim2;
	for (;i<=n && r<x;i++) if (b[i].id==P[1]) {r++,lim=b[i].y;}
	if (r<x) return 0;r=0;
	for (i=1;i<=n && r<x;i++) if (a[i].y>lim && a[i].id==P[2]) {r++,lim2=a[i].x;}
	if (r<x) return 0;r=0;
	for (;i<=n && r<x;i++) if (a[i].y>lim && a[i].x>lim2 && a[i].id==P[3]) {r++;}
	if (r<x) return 0;return 1;
}
int chk6(int x)
{
	int r=0,i=1,lim,lim2;
	for (i=n;i && r<x;i--) if (b[i].id==P[1]) {r++,lim=b[i].y;}
	if (r<x) return 0;r=0;
	for (i=1;i<=n && r<x;i++) if (a[i].y<lim && a[i].id==P[2]) {r++,lim2=a[i].x;}
	if (r<x) return 0;r=0;
	for (;i<=n && r<x;i++) if (a[i].y<lim && a[i].x>lim2 && a[i].id==P[3]) {r++;}
	if (r<x) return 0;return 1;
}
int main()
{
	int i;scanf("%d",&n);
	for (i=1;i<=n;i++)
	{
		scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].id);a[i].o=i;
		b[i]=a[i];
	}
	if (a[1].x==79230851 && a[1].y==-108534798) FLG=1;
	sort(a+1,a+n+1,cmpx);
	sort(b+1,b+n+1,cmpy);
	int l=1,r=n,ans=0;
	while (l<=r)
	{
		int mid=(l+r)>>1,flg=0;
		P[1]=1;P[2]=2;P[3]=3;
		if (!flg)flg|=chk1(mid)|chk2(mid)|chk3(mid)|chk4(mid)|chk5(mid)|chk6(mid);
		P[1]=1;P[2]=3;P[3]=2;
		if (!flg)flg|=chk1(mid)|chk2(mid)|chk3(mid)|chk4(mid)|chk5(mid)|chk6(mid);
		P[1]=2;P[2]=1;P[3]=3;
		if (!flg)flg|=chk1(mid)|chk2(mid)|chk3(mid)|chk4(mid)|chk5(mid)|chk6(mid);
		P[1]=2;P[2]=3;P[3]=1;
		if (!flg)flg|=chk1(mid)|chk2(mid)|chk3(mid)|chk4(mid)|chk5(mid)|chk6(mid);
		P[1]=3;P[2]=1;P[3]=2;
		if (!flg)flg|=chk1(mid)|chk2(mid)|chk3(mid)|chk4(mid)|chk5(mid)|chk6(mid);
		P[1]=3;P[2]=2;P[3]=1;
		if (!flg)flg|=chk1(mid)|chk2(mid)|chk3(mid)|chk4(mid)|chk5(mid)|chk6(mid);
		if (flg) ans=mid,l=mid+1;
		else r=mid-1;
	}
	printf("%d\n",3*ans);
}
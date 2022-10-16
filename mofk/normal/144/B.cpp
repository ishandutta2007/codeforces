#include<stdio.h>
#include<math.h>
int x[1005],y[1005],r[1005],n;
double dist(int xa,int ya,int xb,int yb)
{
	return sqrt(pow((xa-xb),2)+pow((ya-yb),2));
}
int heat(int ox,int oy)
{
	for(int j=1;j<=n;j++) if(dist(ox,oy,x[j],y[j])<=r[j]) return 1;
}
int main(void)
{
	int i,j,xa,ya,xb,yb,tmp,ans;
	scanf("%d%d%d%d",&xa,&ya,&xb,&yb);
	if(xa<xb){tmp=xa;xa=xb;xb=tmp;}	//xa>xb
	if(ya<yb){tmp=ya;ya=yb;yb=tmp;}	//ya>yb
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d%d%d",&x[i],&y[i],&r[i]);
	ans=(xa-xb+ya-yb)*2;
	for(i=xb;i<xa;i++) if(heat(i,ya)==1) ans--;
	for(i=ya;i>yb;i--) if(heat(xa,i)==1) ans--;
	for(i=xa;i>xb;i--) if(heat(i,yb)==1) ans--;
	for(i=yb;i<ya;i++) if(heat(xb,i)==1) ans--;
	printf("%d",ans);
}
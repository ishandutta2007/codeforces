#include<bits/stdc++.h>
using namespace std;
//static char buf[1000000],*p1=buf,*p2=buf;
//#define getchar() p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++
#define re register
const int maxn=2e5+5;
inline int read()
{
	char ch=getchar();bool f=0;int x=0;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=1;
	for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	if(f==1)x=-x;return x;
}
void print(int x)
{
    if(x<0) putchar('-'),x=-x;
    if(x>9) print(x/10);
    putchar(x%10+'0');
}
double r,x,y,xx,yy,s,tx,ty,tmp;
double dis(double a,double b,double c,double d){return sqrt((a-c)*(a-c)+(b-d)*(b-d));}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%lf%lf%lf%lf%lf", &r, &x, &y, &xx, &yy);
	s=dis(x,y,xx,yy);
	if(s==0)printf("%.16lf %.16lf %.16lf",x+(r/2),y,r/2),exit(0);
	if(s>=r)printf("%.8lf %.8lf %.8lf",x,y,r),exit(0);
	tmp=(r/s);tx=(x-xx)*tmp+x;ty=(y-yy)*tmp+y;s=dis(tx,ty,xx,yy);
    printf("%.8lf %.8lf %.8lf",(tx+xx)/2,(ty+yy)/2,s/2);
 	return 0;
}
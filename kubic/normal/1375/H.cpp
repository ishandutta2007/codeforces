#include <bits/stdc++.h>
using namespace std;
#define N 5005
#define M 70005
#define M1 305
#define C 3000005
#define LIM 1000005
#define gc() (P1==P2 && (P2=(P1=buf)+fread(buf,1,LIM,stdin),P1==P2)?EOF:*P1++)
char *P1,*P2,buf[LIM];
int n,m,B,tp,a[N],id[N],ans1[M],h1[N],h2[N],pr[N],sf[N],z[M1][M1],z1[M1][M1];
struct Query {int l,r;}b[M];struct Answer {int x,y;}ans[C];
int rd()
{
	int res=0;char c=0;while(!isdigit(c)) c=gc();
	while(isdigit(c)) res=res*10+(c-48),c=gc();return res;
}
void print(int x) {if(x<10) {putchar(x+48);return;}print(x/10);putchar(x%10+48);}
int f(int x,int y) {if(!x || !y) return x|y;ans[++tp]=(Answer) {x,y};return n+tp;}
void slv(int l,int r,int x)
{
	if(l==r) {h1[l]=z[l-x][l-x]=id[l];return;}
	int mid=(l+r)/2,t1=mid+1,t2=l-1;slv(l,mid,x);slv(mid+1,r,x);
	for(int i=l;i<=mid;++i)
	{while(t1<=r && h1[i]>h1[t1]) sf[t1]=i,h2[++t2]=h1[t1++];h2[++t2]=h1[i];sf[i]=t1;}
	while(t1<=r) sf[t1]=mid+1,h2[++t2]=h1[t1++];
	for(int i=l,t1,t2,t3,t4;i<=mid;++i) for(int j=mid+1;j<=r;++j) if(h1[i]<h1[j])
	{
		t1=a[h1[i]]-x;t2=a[h1[j]]-x;t3=sf[j]>l?a[h1[sf[j]-1]]-x:0;
		t4=sf[i]<=r?a[h1[sf[i]]]-x:0;z1[t1][t2]=f(z[t1][t3],z[t4][t2]);
	}
	else
	{
		t1=a[h1[j]]-x;t2=a[h1[i]]-x;t3=sf[i]>mid+1?a[h1[sf[i]-1]]-x:0;
		t4=sf[j]<=mid?a[h1[sf[j]]]-x:0;z1[t1][t2]=f(z[t4][t2],z[t1][t3]);
	}
	for(int i=l,t1,t2,t3,t4;i<=mid;++i) for(int j=i+1;j<=mid;++j)
	{
		t1=a[h1[i]]-x;t2=a[h1[j]]-x;t3=sf[i]<=r?a[h1[sf[i]]]-x:0;
		t4=sf[j]>mid+1?a[h1[sf[j]-1]]-x:0;z1[t1][t2]=f(z[t1][t2],z[t3][t4]);
	}
	for(int i=mid+1,t1,t2,t3,t4;i<=r;++i) for(int j=i+1;j<=r;++j)
	{
		t1=a[h1[i]]-x;t2=a[h1[j]]-x;t3=sf[i]<=mid?a[h1[sf[i]]]-x:0;
		t4=sf[j]>l?a[h1[sf[j]-1]]-x:0;z1[t1][t2]=f(z[t3][t4],z[t1][t2]);
	}for(int i=l;i<=r;++i) h1[i]=h2[i];
	for(int i=l,t1,t2;i<=r;++i) for(int j=i+1;j<=r;++j)
		t1=a[h1[i]]-x,t2=a[h1[j]]-x,z[t1][t2]=z1[t1][t2];
}
int main()
{
	n=rd();m=rd();B=min(n,(int)sqrtl(m));for(int i=1;i<=n;++i) a[i]=rd(),id[a[i]]=i;
	for(int i=1;i<=m;++i) b[i].l=rd(),b[i].r=rd();
	for(int i=1,l,r,x,t1,t2;i<=(n-1)/B+1;++i)
	{
		l=(i-1)*B+1;r=min(i*B,n);x=(i-1)*B;slv(l,r,x);
		for(int j=1;j<=n;++j) pr[j]=a[j]>=l && a[j]<=r?a[j]-x:pr[j-1];
		for(int j=n;j;--j) sf[j]=a[j]>=l && a[j]<=r?a[j]-x:sf[j+1];
		for(int j=1;j<=m;++j) ans1[j]=f(ans1[j],z[sf[b[j].l]][pr[b[j].r]]);
		for(int j=l;j<=r;++j) for(int k=j+1;k<=r;++k)
			t1=a[h1[j]]-x,t2=a[h1[k]]-x,z[t1][t2]=z1[t1][t2]=0;
	}print(n+tp);putchar('\n');
	for(int i=1;i<=tp;++i) print(ans[i].x),putchar(' '),print(ans[i].y),putchar('\n');
	for(int i=1;i<=m;++i) print(ans1[i]),putchar(' ');return 0;
}
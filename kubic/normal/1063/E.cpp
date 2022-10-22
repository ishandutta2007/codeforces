#include <bits/stdc++.h>
using namespace std;
#define N 2005
int n,tp,nw,a[N],st[N];bool vs[N];char z[N][N];
void f(int x,int y) {++tp;z[tp][x]=x<y?'/':'\\';z[tp][y]=x<y?'/':'\\';}
void slv1(int x)
{
	int ps=0;vs[x]=1;st[0]=0;st[++st[0]]=x;
	for(int i=a[x];i!=x;i=a[i]) vs[i]=1,st[++st[0]]=i;
	for(int i=1;i<=st[0];++i) st[st[0]+i]=st[i];
	if(!nw) {nw=x;for(int i=st[0]-1;i;--i) f(st[i],st[i+1]);}
	else
	{
		for(int i=1;i<=st[0];++i) if(st[i]<st[i+1]) {ps=i;break;}
		f(st[ps],st[ps+1]);--tp;f(st[ps+1],nw);
		for(int i=st[0]+ps-1;i>ps+1;--i) f(st[i],st[i+1]);f(nw,st[ps+2]);
	}
}
void print() {for(int i=n;i;--i,puts("")) for(int j=1;j<=n;++j) putchar(z[i][j]);}
void slv()
{
	bool fl=0;for(int i=1;i<=n;++i) if(a[i]!=i) fl=1;
	if(!fl) {printf("%d\n",n);print();return;}
	for(int i=n;i;--i) if(i!=a[i] && !vs[i]) slv1(i);printf("%d\n",n-1);print();
}
int main()
{
	scanf("%d",&n);for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	for(int i=1;i<=n;++i) for(int j=1;j<=n;++j) z[i][j]='.';slv();return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define N 100005
#define M 2000005
int T,n,m,tp,a[N],lg[N];struct Answer {int x,y;}ans[M];
void f(int x,int y)
{
	--a[x];--a[y];++a[x+y];++a[abs(x-y)];
	ans[++tp]=(Answer) {x,y};
}
void slv1(int n,int w)
{
	if(!n) return;
	for(int i=n;i>1<<lg[n];--i) f(i*w,((1<<lg[n]+1)-i)*w);
	slv1((1<<lg[n]+1)-n-1,w);slv1(n-(1<<lg[n]),w*2);
}
void slv()
{
	scanf("%d",&n);if(n==2) {puts("-1");return;}
	tp=0;m=1;while(m<n) m*=2;for(int i=1;i<=m;++i) a[i]=i<=n;
	for(int i=2;i<=m;++i) lg[i]=lg[i/2]+1;slv1(n,1);
	for(int i=1;i<m;++i) if(a[i]>1) {f(i,i);break;}
	for(int i=1;i<m;++i) while(a[i]) f(i,0),f(i,i);f(m,0);
	printf("%d\n",tp);
	for(int i=1;i<=tp;++i) printf("%d %d\n",ans[i].x,ans[i].y);
}
int main() {scanf("%d",&T);while(T--) slv();return 0;}
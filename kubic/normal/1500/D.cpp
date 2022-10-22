#include <bits/stdc++.h>
using namespace std;
#define N 1505
#define M 15
const int INF=1e9;
int n,m,ans[N],vs[N*N],a[N][N],st1[N][M],st2[N][M];
int tp1,tp2,tp[N];struct Node {int col,w;}tmp[M*3],st[N][M];
bool cmp(Node x,Node y) {return x.w<y.w;}
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;++i) for(int j=1;j<=n;++j) scanf("%d",&a[i][j]);
	for(int i=1,t;i<=n;++i)
	{
		for(int j=n-1;j;--j)
			swap(tp[j],tp[j+1]),swap(st[j],st[j+1]);tp[1]=0;
		for(int j=1;j<=n;++j)
		{
			t=st1[j][0]+1;tp1=tp[j];tp2=0;++vs[0];
			for(int k=1;k<=st1[j][0];++k)
				if(a[st1[j][k]][j]==a[i][j]) {t=k;break;}
			if(t>st1[j][0]) ++st1[j][0];st1[j][t]=i;
			for(int k=t;k>1;--k) if(st1[j][k]>st1[j][k-1])
				swap(st1[j][k],st1[j][k-1]);
			if(st1[j][0]>m+1) --st1[j][0];
				
			st2[j][0]=st2[j-1][0];t=st2[j][0]+1;
			for(int k=1;k<=st2[j][0];++k) st2[j][k]=st2[j-1][k];
			for(int k=1;k<=st2[j][0];++k)
				if(a[i][st2[j][k]]==a[i][j]) {t=k;break;}
			if(t>st2[j][0]) ++st2[j][0];st2[j][t]=j;
			for(int k=t;k>1;--k) if(st2[j][k]>st2[j][k-1])
				swap(st2[j][k],st2[j][k-1]);
			if(st2[j][0]>m+1) --st2[j][0];
			
			for(int k=1;k<=tp1;++k) tmp[k]=st[j][k],++tmp[k].w;
			for(int k=1;k<=st1[j][0];++k)
				tmp[++tp1]=(Node) {a[st1[j][k]][j],i-st1[j][k]};
			for(int k=1;k<=st2[j][0];++k)
				tmp[++tp1]=(Node) {a[i][st2[j][k]],j-st2[j][k]};
			sort(tmp+1,tmp+tp1+1,cmp);
			for(int k=1;k<=tp1;++k) if(vs[tmp[k].col]!=vs[0])
				vs[tmp[k].col]=vs[0],tmp[++tp2]=tmp[k];
			tp[j]=min(tp2,m+1);
			for(int k=1;k<=tp[j];++k) st[j][k]=tmp[k];
			t=min(i,j);if(tp[j]>m) t=min(t,st[j][m+1].w);++ans[t];
		}
	}for(int i=n;i;--i) ans[i]+=ans[i+1];
	for(int i=1;i<=n;++i) printf("%d\n",ans[i]);return 0;
}
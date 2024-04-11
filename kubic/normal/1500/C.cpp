#include <bits/stdc++.h>
using namespace std;
#define N 1505
#define LIM 1000005
#define gc() (P1==P2 && (P2=(P1=buf)+fread(buf,1,LIM,stdin),P1==P2)?EOF:*P1++)
char *P1,*P2,buf[LIM];
int n,m,a[N],ans[N];bitset<N> vs1,vs2,z1,z[N]; 
vector<int> a1[N],a2[N],b1[N],b2[N];bool fl;
int rd()
{
	int res=0;char c=0;while(!isdigit(c)) c=gc();
	while(isdigit(c)) res=res*10+c-48,c=gc();return res;
}
int main()
{
	n=rd();m=rd(); 
	for(int i=1;i<=n;++i)
		a1[i].resize(m+2),a2[i].resize(m+2),b1[i].resize(m+2),b2[i].resize(m+2);
	for(int i=1;i<=n;++i) for(int j=1;j<=m;++j) a1[i][j]=b1[i][j]=rd();
	for(int i=1;i<=n;++i) for(int j=1;j<=m;++j) a2[i][j]=b2[i][j]=rd();
	for(int i=1;i<=n;++i) b1[i][m+1]=b2[i][m+1]=i;
	for(int i=1;i<=n;++i) for(int j=1;j<=m;++j) if(a1[i][j]!=a2[i][j]) {fl=1;break;}
	if(!fl) {puts("0");return 0;}fl=0;sort(b1+1,b1+n+1);sort(b2+1,b2+n+1);
	for(int i=1;i<=n;++i) for(int j=1;j<=m;++j) if(b1[i][j]!=b2[i][j]) {fl=1;break;}
	if(fl) {puts("-1");return 0;}for(int i=1;i<=n;++i) a[b2[i][m+1]]=b1[i][m+1];
	for(int i=1;i<n;++i) for(int j=1;j<=m;++j) if(a2[i][j]>a2[i+1][j]) z[i][j]=1;
	while(1)
	{
		fl=0;z1=0;for(int i=1;i<n;++i) if(!vs1[i]) z1|=z[i];
		for(int i=1;i<=m;++i) if(!z1[i] && !vs2[i])
		{
			fl=vs2[i]=1;ans[++ans[0]]=i;
			for(int j=1;j<n;++j) if(a2[j][i]<a2[j+1][i]) vs1[j]=1;
		}if(!fl) break;
	}for(int i=1;i<n;++i) if(a[i]>a[i+1] && !vs1[i]) {puts("-1");return 0;}
	printf("%d\n",ans[0]);for(int i=ans[0];i;--i)	printf("%d ",ans[i]);return 0;
}
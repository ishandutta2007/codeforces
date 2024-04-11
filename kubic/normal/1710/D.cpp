#include <bits/stdc++.h>
using namespace std;
#define N 2005
int T,n,bl[N],vl[N],st[2][N];char a[N][N];
void slv()
{
	scanf("%d",&n);for(int i=1;i<=n;++i) scanf("%s",a[i]+i);
	for(int i=1;i<=n;++i) bl[i]=vl[i]=0;
	for(int i=1,fl;i<=n;++i)
	{
		for(int j=1;j<i;++j) if(a[j][i]=='1')
			vl[bl[j]]=max(vl[bl[j]],j);bl[i]=i;
		fl=st[0][0]=st[1][0]=0;
		for(int j=i-1;j;--j) if(bl[j]==j)
		{
			st[fl][++st[fl][0]]=max(vl[j],j);fl^=1;
			if(vl[j])
			{
				st[0][++st[0][0]]=i;st[1][++st[1][0]]=i;
				for(int k=1;k<st[0][0];++k)
					printf("%d %d\n",st[0][k],st[0][k+1]);
				for(int k=1;k<st[1][0];++k)
					printf("%d %d\n",st[1][k],st[1][k+1]);
				fl=st[0][0]=st[1][0]=0;bl[i]=j;
			}
		}for(int j=bl[i];j<i;++j) bl[j]=bl[i];vl[bl[i]]=0;
	}
}
int main() {scanf("%d",&T);while(T--) slv();return 0;}
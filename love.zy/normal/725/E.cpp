#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int a[200005];
int b[200005][2];
int c[200005];
int i,j,k,l,m,n;
int main()
{
	scanf("%d",&m);
	scanf("%d",&n);
	for(i=1;i<=n;i++)scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    k=0;a[n+1]=0;
    for(i=n;i>=1;i--)
    {
        if(a[i]!=a[i+1])
        {
            b[++k][0]=a[i];
            b[k][1]=1;
        }else b[k][1]++;
    }
    n=k;k=0;
    //for(i=1;i<=n;i++)printf("%d %d\n",b[i][0],b[i][1]);
    b[0][0]=20000000;
    l=1;
    for(i=m;i>=1;i--)
    {
        c[i]=l;
        if(i==b[l][0] && l<n)l++;
        if(i==b[n][0])break;
    }
    //for(i=1;i<=m;i++)printf("%d %d\n",i,c[i]);
	for(i=1;i<=m;i++)
    {
        l=m;int now=c[l];
        bool f=false;
        while(l>0 && now<=n)
        {
            if(b[now][0]<=i && l>=i && !f)
            {
                l-=i;f=true;
                now=c[l];
                if(l==0)break;
            }else
            {
                l-=b[now][0]*min(b[now][1],l/b[now][0]);
                now=max(now+1,c[l]);
                if(l==0)break;
            }
        }
        if(l>=i && (!f))l-=i;
        if(l!=0){k=i;break;}
    }
	if(k==0)printf("Greed is good");else printf("%d",k);
	return 0;
}
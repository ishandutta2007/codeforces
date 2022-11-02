# include <iostream>
# include <cstdio>
using namespace std;

const int N=1005;

int n;
int a[N][N];
int t21[N][N],t51[N][N];
int t22[N][N],t52[N][N];
int t1,t2;
int f[N][N],g[N][N];
int ans[N][N];
int ok,x,y;
int answer,opt;
char d[N];

void work1 (int xx,int yy,int zz)
{
    t21[xx][yy]=f[xx][yy-1];
    t51[xx][yy]=g[xx][yy-1];
    while (zz%2==0)
        t21[xx][yy]++,zz/=2;
    while (zz%5==0)
        t51[xx][yy]++,zz/=5;
}

void work2 (int xx,int yy,int zz)
{
    t22[xx][yy]=f[xx-1][yy];
    t52[xx][yy]=g[xx-1][yy];
    while (zz%2==0)
        t22[xx][yy]++,zz/=2;
    while (zz%5==0)
        t52[xx][yy]++,zz/=5;
}

void pr (int xx,int yy,int t)
{
	if(opt==2){
		if(f[xx][yy]==t22[xx][yy])
			d[t]='D';
		else
			d[t]='R';
	}
	if(opt==5){
		if(g[xx][yy]==t52[xx][yy])
			d[t]='D';
		else
			d[t]='R';
	}
    if (t==0)
        return ;
    if (d[t]=='D')
        pr (xx-1,yy,t-1);
    else
        pr (xx,yy-1,t-1);
}

int main ()
{
    scanf ("%d",&n);
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            scanf ("%d",&a[i][j]);
    a[1][0]=a[0][1]=233;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
        {
            if (a[i][j]==0)
            {
                if (!ok)
                {
                    ok=1;
                    x=i;
                    y=j;
                }
                continue;
            }
            t21[i][j]=t22[i][j]=1<<30;
            t51[i][j]=t52[i][j]=1<<30;
            if (a[i][j-1]!=0)
                work1 (i,j,a[i][j]);
            if (a[i-1][j]!=0)
                work2 (i,j,a[i][j]);
            f[i][j]=min(t21[i][j],t22[i][j]);
            g[i][j]=min(t51[i][j],t52[i][j]);
        }
    answer=min(f[n][n],g[n][n]);
    if (!ok||(ok&&answer==0))
    {
        printf ("%d\n",answer);
        if(answer==f[n][n])
        	opt=2;
        else
        	opt=5;
        pr (n,n,2*n-2);
        for (int i=1;i<=n*2-2;i++)
            printf ("%c",d[i]);
    }
    else
    {
        printf ("1\n");
        for (int i=1;i<x;i++)
            printf ("D");
        for (int i=1;i<y;i++)
            printf ("R");
        for (int i=x;i<n;i++)
            printf ("D");
        for (int i=y;i<n;i++)
            printf ("R");
    }
    return 0;
}
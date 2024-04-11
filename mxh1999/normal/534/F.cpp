#include<bits/stdc++.h>
using namespace std;

struct PII
{
    int first;
    short second;
};
#define fi first
#define se second
int n,m;
int a[30],b[30];
bool f[21][161060][33];
PII c[5154000],d[5154000];
int h1,h2;
int ans[30][30],ans1,ans2;

int haha(int s,int t)
{
    int q=1;
    int sum=0;
    for (int i=1;i<=n;i++)
    {
        if ((s%2==0) && (t%2==1))   sum+=q;
        q*=11;
        t>>=1;
        s>>=1;
    }
    return sum;
}
bool ok(int s,int t)
{
    int q=0;bool bo=false;
    while (t>0)
    {
        if (t&1)
        {
            if (!bo)    q++;
            bo=true;
        }   else bo=false;
        t>>=1;
    }
    return b[s]==q;
}
int main()
{
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
    {
        scanf("%d",a+i);
        ans1*=11;
        ans1+=a[i];
    }
    for (int i=1;i<=m;i++)  scanf("%d",b+i);
    PII *x=c,*y=d;
    x[1]=(PII){0,0};
    h1=1;
    for (int i=1;i<=m;i++)
    {
        h2=0;
        for (int k=0;k<(1<<n);k++)
            if (ok(i,k))
            for (int j=1;j<=h1;j++)
            {
                if (i==12 && x[j].fi==45256 && x[j].se==16 && k==31)
                {
                    int qqqqq=31;
                }
                int qqq=x[j].fi+haha(x[j].se,k);
                if (!f[i][qqq][k])  f[i][qqq][k]=true,y[++h2]=(PII){qqq,k};
                //if (h2>=5154000)  cerr<<"biubiu"<<endl;
                if (i==m && qqq==ans1)  ans2=k;
            }
        swap(x,y);
        //cerr<<h2<<endl;
        swap(h1,h2);
    }
    for (int i=m;i>=1;i--)
    {
        int last=ans2;
        for (int j=n;j>=1;j--)
        {
            ans[j][i]=last&1;
            last>>=1;
        }
        for (int k=0;k<(1<<n);k++)
        if (ok(i-1,k))
        {
            int qqq=ans1-haha(k,ans2);
            if (f[i-1][qqq][k])
            {
                ans2=k;
                ans1=qqq;
                break;
            }
        }
    }
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=m;j++)
        if (ans[i][j])  printf("*");else printf(".");
        printf("\n");
    }
    return 0;
}
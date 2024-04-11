//xudyh bless me;
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void read(int &digit)
{
    digit=0;
    char c;
    for (c=getchar();(c<'0' || c>'9') && c!='-';c=getchar());
    bool type=false;
    if (c=='-')
        type=true,c=getchar();
    for (;c>='0' && c<='9';digit=digit*10+c-'0',c=getchar());
    if (type==true)
        digit=-digit;
}

#define maxn 210
int n,m;
int a[maxn];
int num[maxn];
int f[maxn][maxn];
int cnt;

struct Matrix
{
    int a[maxn][maxn];
    void clear()
    {
        memset(a,-1,sizeof(a));
    }
}   b,ans;

Matrix operator*(Matrix a,Matrix b)
{
    Matrix c;
    for (int i=1;i<=cnt;i++)
        for (int j=1;j<=cnt;j++)
        {
            int qqq=-1;
            for (int k=1;k<=cnt;k++)
            {
                if (a.a[i][k]!=-1 && b.a[k][j]!=-1)
                if (qqq<a.a[i][k]+b.a[k][j])    qqq=a.a[i][k] + b.a[k][j];
            }
            c.a[i][j]=qqq;
        }
    return c;
}
Matrix po(Matrix a,int b)
{
    if (b==1)   return a;
    return (b&1)?(po(a*a,b>>1)*a):(po(a*a,b>>1));
}
int main()
{
    read(n),read(m);
    for (int i=1;i<=n;i++)  read(a[i]),num[i]=a[i];
    sort(num+1,num+n+1);
    cnt=unique(num+1,num+n+1)-(num+1);
    for (int i=1;i<=n;i++)
        a[i]=lower_bound(num+1,num+cnt+1,a[i])-num;
    b.clear();
    for (int s=1;s<=cnt;s++)
    {
        memset(f,-1,sizeof(f));
        for (int i=1;i<=n;i++)
        {
            if (a[i]>=s)
            if (f[i][a[i]]<0)   f[i][a[i]]=0;
            for (int j=1;j<=cnt;j++)
            if (f[i][j]!=-1)
            {
                if (f[i+1][j]<f[i][j])  f[i+1][j]=f[i][j];
                if (a[i]>=j)
                if (f[i+1][a[i]]<f[i][j]+1) f[i+1][a[i]]=f[i][j]+1;
            }
        }
        int qqq=-1;
        for (int i=1;i<=cnt;i++)
        {
            qqq=max(qqq,f[n+1][i]);
            if (qqq>b.a[s][i])  b.a[s][i]=qqq;
        }
        
    }
    ans=po(b,m);
    int sum=0;
    for (int i=1;i<=cnt;i++)
        for (int j=1;j<=cnt;j++)
        if (ans.a[i][j]>sum)    sum=ans.a[i][j];
    printf("%d\n",sum);
    return 0;
}
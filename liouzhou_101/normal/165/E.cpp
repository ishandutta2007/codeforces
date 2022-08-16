#include<cstdio>

int pow[30];
int F[1<<22];
int n;
int a[1<<20];

int find(int p)
{
    if (F[p]) return F[p];
    F[p]=-1;
    for (int k=0;k<22;++k)
        if (!(p&pow[k]))
        {
            F[p]=find(p|pow[k]);
            if (F[p]!=-1) return F[p];
        }
    return F[p];
}

int main()
{
    for (int i=pow[0]=1;i<30;++i)
        pow[i]=pow[i-1]<<1;
    scanf("%d",&n);
    for (int i=1;i<=n;++i)
    {
        scanf("%d",&a[i]);
        int tmp=0;
        for (int k=0;k<22;++k)
            if (!(a[i]&pow[k])) tmp+=pow[k];
        F[tmp]=a[i];
    }
    for (int i=1;i<=n;++i)
    {
        int tmp=0;
        for (int k=0;k<22;++k)
            if (a[i]&pow[k]) tmp+=pow[k];
        printf("%d",find(tmp));
        if (i<n) putchar(' ');
    }
    return 0;
}
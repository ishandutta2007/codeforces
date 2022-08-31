#include<cstdio>

const int MaxN=20010;

int n;
int a[MaxN];

int main()
{
    scanf("%d",&n);
    int ans=0;
    for (int i=0;i<n;++i)
    {
        scanf("%d",&a[i]);
        ans+=a[i];
    }
    for (int i=2;i<n;++i)
    {
        if (n%i>0) continue;
        if (n/i<3) break;
        for (int p=0;p<i;++p)
        {
            int tmp=0;
            for (int k=p;k<n;k+=i)
                tmp+=a[k];
            if (tmp>ans) ans=tmp;
        }
    }
    printf("%d\n",ans);
    return 0;
}
#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;

const int MaxN=1010;

int n;
int a[MaxN],b[MaxN],p[MaxN];

inline bool cmp(const int &i,const int &j)
{
    return b[i]>b[j]||(b[i]==b[j]&&a[i]>a[j]);
}

int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;++i)
    {
        scanf("%d%d",a+i,b+i);
        p[i]=i;
    }
    sort(p+1,p+n+1,cmp);
    int ans=0,left=1;
    for (int i=1;i<=n;++i)
    {
        if (!left) break;
        --left;
        ans+=a[p[i]];
        left+=b[p[i]];
    }
    printf("%d\n",ans);
    return 0;
}
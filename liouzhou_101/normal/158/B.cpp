#include<cstdio>

int n;
int v[10];

int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;++i)
    {
        int x;
        scanf("%d",&x);
        ++v[x];
    }
    int ans=v[4];
    v[4]=0;
    while (v[3]>0)
    {
        ++ans;
        --v[3];
        if (v[1]>0) --v[1];
    }
    while (v[2]>0)
    {
        ++ans;
        --v[2];
        if (v[2]>0) --v[2];
        else
        {
            if (v[1]>0) --v[1];
            if (v[1]>0) --v[1];
        }
    }
    while (v[1]>0)
    {
        ++ans;
        v[1]-=4;
    }
    printf("%d\n",ans);
    return 0;
}
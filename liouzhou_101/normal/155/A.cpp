#include<cstdio>

int main()
{
    int n,x;
    scanf("%d",&n);
    scanf("%d",&x);
    int L=x,R=x;
    int ans=0;
    for (int i=2;i<=n;++i)
    {
        scanf("%d",&x);
        if (x<L)
        {
            ++ans;
            L=x;
        }
        else if (x>R)
        {
            ++ans;
            R=x;
        }
    }
    printf("%d\n",ans);
    return 0;
}
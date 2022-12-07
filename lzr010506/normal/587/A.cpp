#include<stdio.h>
#include<string.h>
#define maxn 1111111
int n,w,num[maxn],ans;
int main()
{
    while(~scanf("%d",&n))
    {
        memset(num,0,sizeof(num));
        ans=0;
        for(int i = 0; i < n; i ++)
        {
            scanf("%d",&w);
            num[w] ++;
        }
        for(int i = 1; i < maxn; i ++)
            num[i] += (num[i - 1] / 2), num[i - 1] %= 2;
        for(int i = 0; i < maxn; i ++)
            ans += num[i];
        printf("%d\n",ans);
    }
    return 0;
}
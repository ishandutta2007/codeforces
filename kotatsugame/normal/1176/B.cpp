#include<cstdio>
using namespace std;
int T,N;
main()
{
    scanf("%d",&T);
    for(;T--;)
    {
        scanf("%d",&N);
        int cnt[3]={};
        for(int i=0;i<N;i++)
        {
            int a;scanf("%d",&a);cnt[a%3]++;
        }
        int ans=cnt[0];
        int mn=cnt[1]<cnt[2]?cnt[1]:cnt[2];
        ans+=mn;
        cnt[1]-=mn;
        cnt[2]-=mn;
        ans+=cnt[1]/3;
        ans+=cnt[2]/3;
        printf("%d\n",ans);
    }
}
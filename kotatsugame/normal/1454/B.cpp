#include<cstdio>
using namespace std;
int T,N;
int id[2<<17];
main()
{
    scanf("%d",&T);
    for(;T--;)
    {
        scanf("%d",&N);
        for(int i=1;i<=N;i++)id[i]=-1;
        for(int i=1;i<=N;i++)
        {
            int A;scanf("%d",&A);
            if(id[A]==-1)id[A]=i;
            else id[A]=N+1;
        }
        int ans=1;
        while(ans<=N&&(id[ans]==-1||id[ans]==N+1))ans++;
        printf("%d\n",ans<=N?id[ans]:-1);
    }
}
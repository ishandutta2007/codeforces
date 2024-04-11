#include<bits/stdc++.h>
#define int long long
using namespace std;
int t, n, i, j, k, m, q, a, b, c, chk[300010], sparse[300010][20], A[300010], C[300010];
int get(int v, int a)
{
    for(int j=19;j>=0;j--)
    {
        if((1<<j)<=a)
        {
            a-=(1<<j);
            v=sparse[v][j];
        }
    }
    return v;
}
main()
{
    for(j=0;j<20;j++)sparse[0][j]=-1;
    for(scanf("%lld %lld %lld", &q, &A[0], &C[0]);i++<q;)
    {
        scanf("%lld", &t);
        if(t==1)
        {
            scanf("%lld %lld %lld", &k, &A[i], &C[i]);
            sparse[i][0]=k;
            for(j=1;j<20;j++)
            {
                if(sparse[i][j-1]==-1)
                {
                    sparse[i][j]=-1;
                    continue;
                }
                sparse[i][j]=sparse[sparse[i][j-1]][j-1];
            }
        }
        else
        {
            scanf("%lld %lld", &k, &a);
            int kk=k;
            if(chk[k])
            {
                puts("0 0");
                fflush(stdout);
                continue;
            }
            b=0;
            for(j=19;j>=0;j--)
            {
                if(sparse[k][j]==-1)continue;
                if(!chk[sparse[k][j]])k=sparse[k][j],b+=(1<<j);
            }
            int ans1=0, ans2=0;
            for(j=b;j>=0;j--)
            {
                c=get(kk, j);
                if(a<A[c])
                {
                    ans1+=a;
                    ans2+=C[c]*a;
                    A[c]-=a;
                    break;
                }
                chk[c]=1;
                ans1+=A[c];
                ans2+=C[c]*A[c];a-=A[c];
            }
            printf("%lld %lld\n", ans1, ans2);
            fflush(stdout);
        }
    }
}
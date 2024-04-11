#include<bits/stdc++.h>
using namespace std;
int t, n, i, j, k, a, b, A[510][510];
vector<pair<int, int> >adj[250010];
long long dist[250010];
int f(int i, int j)
{
    return (i-1)*2*n+j;
}
main()
{
    for(scanf("%d", &t);t--;)
    {
        scanf("%d", &n);
        long long ans=0;
        for(i=0;i++<2*n;)
        {
            for(j=0;j++<2*n;)
            {
                scanf("%d", &A[i][j]);
                if(i>n&&j>n)ans+=A[i][j],A[i][j]=0;
            }
        }
        ans+=min({A[n+1][1], A[n+1][n], A[2*n][n], A[1][n+1], A[n][n+1], A[n][2*n], A[1][2*n], A[2*n][1]});
        printf("%lld\n", ans);
    }
}
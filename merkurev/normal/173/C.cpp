#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;


long long inf=1e17;
int q[505][505];
int colst[505][505];

int rowst[505][505];

int main()
{

    int n,m;
    scanf("%d%d",&n,&m);
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
            scanf("%d",&q[i][j]);
    for (int i=0;i<n;i++)
    {
        rowst[i][0]=0;
        for (int j=0;j<m;j++)
            rowst[i][j+1]=rowst[i][j]+q[i][j];
    }
    for (int j=0;j<m;j++)
    {
        colst[0][j]=0;
        for (int i=0;i<n;i++)
            colst[i+1][j]=colst[i][j]+q[i][j];
    }

    long long ans=-inf;
    
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
        {
            int maxsize=min(min(i,j),min(n-i-1,m-j-1));
            if (maxsize>=1)
            {
                long long curans=
                    q[i-1][j-1]+q[i-1][j]+q[i-1][j+1]
                +
                    q[i][j+1]
                +
                    q[i+1][j-1]+q[i+1][j]+q[i+1][j+1];

                long long kvsize=curans+q[i][j-1]+q[i][j];

                ans=max(curans,ans);

                for (int l=2;l<=maxsize;l++)
                {
                    kvsize+=rowst[i-l][j+l+1]-rowst[i-l][j-l];
                    kvsize+=rowst[i+l][j+l+1]-rowst[i+l][j-l];
                    kvsize+=colst[i+l][j-l]-colst[i-l+1][j-l];
                    kvsize+=colst[i+l][j+l]-colst[i-l+1][j+l];

                    curans=kvsize-curans-q[i-l+1][j-l];

                    ans=max(curans,ans);
                }
            }
        }
    printf("%I64d",ans);

    return 0;
}
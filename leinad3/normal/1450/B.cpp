#include<bits/stdc++.h>
using namespace std;
int t, n, i, j, k, A[110][2];
int dist(int a, int b)
{
    return abs(A[b][0]-A[a][0])+abs(A[b][1]-A[a][1]);
}
int main()
{
    for(scanf("%d", &t);t--;)
    {
        scanf("%d %d", &n, &k);
        for(i=0;i++<n;)scanf("%d %d", &A[i][0], &A[i][1]);
        for(i=0;i++<n;)
        {
            bool flag=true;
            for(j=0;j++<n;)
            {
                if(dist(i, j)>k)
                {
                    flag=false;
                    break;
                }
            }
            if(flag)
            {
                puts("1");
                goto w;
            }
        }
        puts("-1");
        w:;
    }
}
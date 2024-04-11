#include<bits/stdc++.h>
using namespace std;
int t, n, i, j, k, a, b, A[300010];
long long B[300010], sparse[300010][20], sparse2[300010][20];
map<long long, vector<int> >V;
main()
{
    for(scanf("%d", &t);t--;)
    {
        long long ans=0;
        scanf("%d", &n);
        for(i=0;i++<n;)scanf("%d", &A[i]);
        V.clear();
        for(i=0;i++<n;)B[i]=-B[i-1]+A[i];
        for(i=0;i++<n;)
        {
            if(i%2)V[B[i]].push_back(i);
            else V[-B[i]].push_back(i);
        }
        for(i=0;i++<n;)
        {
            if(i%2==0)sparse[i][0]=1e18;
            else sparse[i][0]=B[i];
        }
        for(i=0;i++<n;)
        {
            if(i%2==1)sparse2[i][0]=1e18;
            else sparse2[i][0]=B[i];
        }
        for(j=1;j<20;j++)
        {
            for(i=0;i++<n;)
            {
                sparse[i][j]=sparse[i][j-1];
                if(i+(1<<(j-1))<=n)sparse[i][j]=min(sparse[i][j], sparse[i+(1<<(j-1))][j-1]);
                sparse2[i][j]=sparse2[i][j-1];
                if(i+(1<<(j-1))<=n)sparse2[i][j]=min(sparse2[i][j], sparse2[i+(1<<(j-1))][j-1]);
            }
        }
        for(i=0;i++<n;)
        {
            int a=i, b=i;
            if(i%2)
            {
                for(j=19;j>=0;j--)
                {
                    if(a+(1<<j)<=n+1&&sparse[a][j]>=-B[i-1])a+=(1<<j);
                }
                for(j=19;j>=0;j--)
                {
                    if(b+(1<<j)<=n+1&&sparse2[b][j]>=B[i-1])b+=(1<<j);
                }
            }
            else
            {
                for(j=19;j>=0;j--)
                {
                    if(a+(1<<j)<=n+1&&sparse2[a][j]>=-B[i-1])a+=(1<<j);
                }
                for(j=19;j>=0;j--)
                {
                    if(b+(1<<j)<=n+1&&sparse[b][j]>=B[i-1])b+=(1<<j);
                }
            }
            int x=min(a, b)-1;
            if(i%2)
            {
                ans+=(lower_bound(V[-B[i-1]].begin(), V[-B[i-1]].end(), x+1)-lower_bound(V[-B[i-1]].begin(), V[-B[i-1]].end(), i));
            }
            else
            {
                ans+=(lower_bound(V[B[i-1]].begin(), V[B[i-1]].end(), x+1)-lower_bound(V[B[i-1]].begin(), V[B[i-1]].end(), i));
            }
        }
        printf("%lld\n", ans);
    }
}
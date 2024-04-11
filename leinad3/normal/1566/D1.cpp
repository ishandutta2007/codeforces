#include<bits/stdc++.h>
using namespace std;
int t, n, m, i, j, k, a, b, A[310][310], B[310], C[310];
main()
{
    for(scanf("%d", &t);t--;)
    {
        scanf("%d %d", &n, &m);
        for(i=0;i++<n;)for(j=0;j++<m;)scanf("%d", &A[i][j]);
        vector<pair<int, int> >v;
        for(j=0;j++<m;)v.push_back({A[1][j], -j});
        sort(v.begin(), v.end());
        for(i=0;i<v.size();i++)
        {
            B[-v[i].second]=i+1;
        }
        int ans=0;
        for(i=0;i++<m;)C[i]=0;
        for(i=0;i++<m;)
        {
            C[B[i]]=1;
            for(j=1;j<B[i];j++)ans+=C[j];
        }
        printf("%d\n", ans);
    }
}
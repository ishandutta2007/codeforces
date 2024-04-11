#include<bits/stdc++.h>
using namespace std;
int t, n, m, i, j, k, a, b, A[310][310], B[100010], C[310][310], D[100010];
struct st
{
    int a, b, ind;
};
int X(int k)
{
    return (k-1)/m+1;
}
int Y(int k)
{
    return (k-1)%m+1;
}
bool cmp(st x, st y)
{
    if(x.a!=y.a)return x.a<y.a;
    if(X(x.b)!=X(y.b))return X(x.b)<X(y.b);
    return Y(x.b)>Y(y.b);
}
main()
{
    for(scanf("%d", &t);t--;)
    {
        scanf("%d %d", &n, &m);
        for(i=0;i++<n;)for(j=0;j++<m;)scanf("%d", &A[i][j]),C[i][j]=0;
        vector<pair<int, int> >V;
        vector<st>v;
        for(i=0;i++<n;)for(j=0;j++<m;)
        {
            V.push_back({A[i][j], (i-1)*m+j});
        }
        sort(V.begin(), V.end());
        for(i=0;i<V.size();i++)D[i+1]=V[i].first,v.push_back({D[i+1], i+1, V[i].second});
        sort(v.begin(), v.end(), cmp);
        for(i=0;i<v.size();i++)
        {
            B[v[i].ind]=i+1;
        }
        int ans=0;
        for(i=0;i++<n*m;)
        {
            a=X(B[i]);b=Y(B[i]);
            for(j=1;j<b;j++)ans+=C[a][j];
            C[a][b]=1;
        }
        printf("%d\n", ans);
    }
}
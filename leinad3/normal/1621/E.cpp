#include<bits/stdc++.h>
using namespace std;
int t, n, m, i, j, k, a, b, A[100010], C[100010], D[100010], E[100010];
long long sum[100010];
pair<long long, int>B[100010];
vector<int>ans[100010];
bool cmp2(pair<long long, int>a, pair<long long, int>b){return a.first>b.first;}
bool cmp(int a, int b){return a>b;}
vector<int>v[100010];
int Find(int a, int i)
{
    int s=0, e=m;
    while(s<e)
    {
        int mid=s+e+1>>1;
        if(B[mid].first>=a)s=mid;
        else e=mid-1;
    }
    if(s<i)return s+1;
    return s;
}
main()
{
    for(scanf("%d", &t);t--;)
    {
        scanf("%d %d", &n, &m);
        for(i=0;i++<n;)scanf("%d", &A[i]);sort(A+1, A+n+1, cmp);
        for(i=0;i++<n;)B[i]={0, 0},v[i].clear(),sum[i]=C[i]=D[i]=E[i]=0,ans[i].clear();
        vector<int>V;
        for(i=0;i++<m;)
        {
            long long s=0;
            scanf("%d", &a);
            for(j=0;j++<a;)
            {
                scanf("%d", &b);
                s+=b;
                v[i].push_back(b);
            }
            sum[i]=s;
            B[i].first=(s+a-1)/a;
            B[i].second=i;
        }
        sort(B+1, B+m+1, cmp2);
        for(i=1;i<=m;i++)if(A[i]<B[i].first)C[i]=1;
        for(i=2;i<=m;i++)if(A[i]<B[i-1].first)D[i]=1;
        for(i=2;i<=m;i++)if(A[i-1]<B[i].first)E[i-1]=1;
        for(i=1;i<=m;i++)C[i]+=C[i-1],D[i]+=D[i-1],E[i]+=E[i-1];
        for(j=1;j<=m;j++)
        {
            i=B[j].second;
            int a=v[i].size();a--;
            for(auto p:v[i])
            {
                long long k=(sum[i]-p+a-1)/a;
                int x=Find(k, j);
                if(x<=j)
                {
                    if(A[x]>=k&&D[j]-D[x]==0&&C[m]-C[j]==0&&C[x-1]==0)ans[i].push_back(1);
                    else ans[i].push_back(0);
                }
                else
                {
                    if(A[x]>=k&&E[x-1]-E[j-1]==0&&C[m]-C[x]==0&&C[j-1]==0)ans[i].push_back(1);
                    else ans[i].push_back(0);
                }
            }
        }
        for(i=1;i<=m;i++)for(auto p:ans[i])printf("%d", p);puts("");
    }
}
#include<bits/stdc++.h>
#define int long long
using namespace std;
int t, n, i, j, k, B[200010];
char A[200010];
main()
{
    for(i=0;i<=200000;i++)B[i]=(i*(i+1))/2;
    for(scanf("%lld", &t);t--;)
    {
        scanf("%s", &A);
        n=strlen(A);
        vector<pair<int, int> >v;
        int a=-1, b=0;
        for(i=0;i<n;i++)
        {
            if(A[i]=='?')continue;
            if(A[i]=='0')
            {
                if(a>=0)
                {
                    if((a+b)%2!=i%2)v.push_back({a, i});
                }
                a=i;b=0;
            }
            if(A[i]=='1')
            {
                if(a>=0)
                {
                    if((a+b)%2!=(i+1)%2)v.push_back({a, i});
                }
                a=i;b=1;
            }
        }
        if(v.size()==0)
        {
            printf("%lld\n", B[n]);continue;
        }
        int ans=0;
        for(i=0;i+1<v.size();i++)
        {
            ans+=B[v[i+1].second-v[i].first-1];
        }
        if(v.size())
        {
            ans+=B[v[0].second];
            ans+=B[n-v.back().first-1];
        }
        for(i=0;i<v.size();i++)
        {
            ans-=B[v[i].second-v[i].first-1];
        }
        printf("%lld\n", ans);
    }
}
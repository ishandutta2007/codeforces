#include<bits/stdc++.h>
using namespace std;
int t, n, i, j, k, a, b, A[200010], ans;
vector<int>v[200010];
vector<pair<int, int> >V, res;
int nex(int i)
{
    int j=0;
    for(j=i;j<res.size();j++)
    {
        if(res[j].first>res[i].second)break;
    }
    return j-1;
}
main()
{
    for(scanf("%d", &n);i++<n;)scanf("%d", &A[i]);
    for(i=0;i++<n;)v[A[i]].push_back(i);
    for(i=0;i++<n;)if(v[i].size()>=2)
    {
        V.push_back({v[i][0], v[i].back()});
    }
    sort(V.begin(), V.end());
    for(auto p:V)
    {
        if(a<p.second)
        {
            res.push_back(p);
            a=p.second;
        }
    }
    if(res.size()==0)
    {
        puts("0");
        return 0;
    }
    ans+=(res[0].second-res[0].first-1);
    i=0;
    while(i+1<res.size())
    {
        int a=nex(i);
        if(a==i)a++;
        ans+=(res[a].second-max(res[i].second, res[a].first)-1);
        i=a;
    }
    cout<<ans;
}
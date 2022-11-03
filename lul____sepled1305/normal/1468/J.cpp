/** This problem is boring + hard to code **/
#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using piii = pair<int,pii>;

struct DSU
{
    int n;
    vector<int> par;

    DSU(int n)
    {
        this ->n = n;
        for(int i=0;i<n;i++)
            par.push_back(i);
    }

    int find_par(int cur)
    {
        if(par[cur] == cur)
            return cur;
        par[cur] = find_par(par[cur]);
        return par[cur];
    }

    void merge(int a, int b)
    {
        a = find_par(a);
        b = find_par(b);

        if(a == b)
            return;

        par[b] = a;
        return;
    }
};

void solve()
{
    int n,m,k,i;
    cin>>n>>m>>k;
    vector<piii> v;
    DSU dsu = DSU(n);
    long long ans = 0;
    int closest = 2e9;
    for(i=0;i<m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        closest = min(closest,abs(c-k));
        a--,b--;
        v.push_back({max(0,c-k),{a,b}});
    }
    sort(v.begin(),v.end());
    for(auto it: v)
    {
        if(dsu.find_par(it.second.first) == dsu.find_par(it.second.second))
            continue;
        ans+=it.first;
        dsu.merge(it.second.first,it.second.second);
    }
    if(ans == 0)
        ans = closest;
    cout<<ans<<endl;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}
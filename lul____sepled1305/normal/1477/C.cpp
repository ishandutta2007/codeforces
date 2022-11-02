#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;

long long dist(pii a, pii b)
{
    return 1LL * (a.first - b.first) * (a.first - b.first) + 1LL * (a.second - b.second) * (a.second - b.second);
}

int main()
{
    int n,i;
    cin>>n;
    vector<int> ans;
    vector<pii> v;
    set<int> del;
    for(i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        v.push_back({a,b});
    }
    ans.push_back(0);
    del.insert(0);
    pii last = v[0];
    while(del.size() != n)
    {
        long long maxi = 0, idx = 0;
        for(i=0;i<n;i++)
        {
            if(del.count(i))
                continue;
            long long cur = dist(last,v[i]);
            if(cur > maxi)
            {
                maxi = cur;
                idx = i;
            }
        }
        last = v[idx];
        ans.push_back(idx);
        del.insert(idx);
    }
    for(auto it: ans)
        cout<<it+1<<' ';
    return 0;
}
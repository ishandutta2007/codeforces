/*iie senpai, WATASHITACHI NO PROBLEM DESU!!!*/
#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
using pii = pair<int,int>;
using pll = pair<long long, long long>;
int n,m,i,topic;
vector<vector<int>> tree;
pii desire[N];
int depth[N];


int main()
{
    cin>>n>>m;
    for(i=0;i<n;i++)
    {
        vector<int> v;
        tree.push_back(v);
    }
    for(i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        tree[a-1].push_back(b-1);
        tree[b-1].push_back(a-1);
    }
    for(i=0;i<n;i++)
    {
        int a;
        cin>>a;
        pii here = {a-1,i};
        desire[i] = here;
    }
    sort(desire, desire+n);
    bool pass = true;
    for(i=0;i<n;i++)
    {
        int node = desire[i].second;
        int val = desire[i].first;
        if(val != depth[node])
            pass = false;
        for(auto it: tree[node])
            if(depth[it] == depth[node])
                depth[it]++;
    }
    if(!pass)
        cout<<-1;
    else
    {
        for(i=0;i<n;i++)
            cout<<desire[i].second+1<<" ";
    }
    return 0;
}
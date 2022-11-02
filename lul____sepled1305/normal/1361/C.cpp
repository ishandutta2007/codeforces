/*iie senpai, WATASHITACHI NO PROBLEM DESU!!!*/
#include<bits/stdc++.h>
using namespace std;
const int N=2e6;
int n,i,j,powe=1,k;
vector<int> arr;
int deg[N];
bool visit[N];
map<long long,int> big_mp;
vector<pair<int,int>> tree[N];
vector<pair<int,int>> refi[N], co_refi[N];
stack<int> st;
vector<int> v;
using pii = pair<int,int>;
bool vis[N];

void dfs (int node)
{
    visit[node] = true;
    for(auto it: tree[node])
        if(!visit[it.first])
            dfs(it.first);
}

void euler (int node,int previous)
{
    while(tree[node].size())
    {
        auto it = tree[node].back();
        tree[node].pop_back();
        if(vis[it.second/2])
            continue;

        vis[it.second/2] = true;
        euler(it.first,it.second);
    }

    if(previous !=-1)
    {
        v.push_back(previous);
        v.push_back(previous^1);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    for(i=0; i<n; i++)
    {
        int a,b;
        cin>>a>>b;
        arr.push_back(a);
        arr.push_back(b);
    }
    for(i=0; i<21; i++)
        powe*=2;
    for(i=20; i>=0; i--)
    {
        /**if(i==2 && n==500000)
        {
            cout<<"Sad still bug";
            break;
        }**/
        powe/=2;
        int bits = powe-1;
        bool pass = true;
        int counti = 0;
        for(j=0; j<powe; j++)
            tree[j].clear();
        for(j=0; j<n; j++)
        {
            int a = arr[2*j]&bits, b = arr[2*j+1]&bits;
            tree[a].push_back({b,2*j+1});
            tree[b].push_back({a,2*j});
        }
        for(j=0; j<powe; j++)
        {
            deg[j] = tree[j].size();
            visit[j] = false;
        }
        int comp=0;
        for(j=0; j<powe; j++)
        {
            if(deg[j]>0)
            {
                if(!visit[j])
                {
                    comp++;
                    dfs(j);
                }
                if(deg[j]&1==1)
                {
                    pass = false;
                    break;
                }
            }
        }
        if(pass && comp == 1)
        {
            cout<<i<<"\n";
            int first = 0;
            while(!deg[first])
                first++;
            for(j=0; j<powe; j++)
                visit[j] = false;
            euler(first,-1);
            while(!v.empty())
            {
                cout<<v.back()+1<<" ";
                v.pop_back();
            }
            break;
        }
    }
    return 0;
}
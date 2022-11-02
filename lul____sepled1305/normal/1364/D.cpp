#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int n,k,m,i,j,last = -1, aim =0;
vector<int> tree[N];
bool visit[N];
int depth[N];
int previous[N];
int last_previous;
int cycle[N];

void dfs(int node, int prv,int d)
{
    if(!visit[node])
    {
        visit[node] = true;
        depth[node] = d;
        previous[node] = prv;
        for(auto it: tree[node])
        {
            if(it != prv)
                dfs(it, node, d+1);
            if(last!=-1)
                break;
        }
    }
    else
    {
        last = node;
        last_previous = prv;
    }
}

void trackcycle(int cycle[], int siz, int tar)
{
    if(siz > tar)
    {
        map<int,int> mp;
        int counti = 0, i;
        for(i=0; i<siz; i++)
        {
            mp.insert({cycle[i],counti});
            counti++;
        }
        int newi=-1;
        for(i=0; i<siz; i++)
        {
            for(auto it: tree[cycle[i]])
                if(it!=cycle[(i+siz-1)%siz] && it!=cycle[(i+1)%siz] && mp.count(it))
                {
                    newi = it;
                    break;
                }
            if(newi!=-1)
                break;
        }
        if(newi != -1)
        {
            int node1 = mp[cycle[i]], node2 = mp[newi];
            bool left = false;
            if((node1-node2+siz)%siz <= siz/2)
                left = true;
            if(left)
                swap(node1,node2);
            int i = node1;
            int new_siz = 0;
            int new_cycle[N];
            while(i!=node2)
            {
                new_cycle[new_siz] = cycle[i];
                new_siz++;
                i++;
                if(i>=siz)
                    i%=siz;
            }
            new_cycle[new_siz] = cycle[node2];
            new_siz++;
            for(i=0;i<new_siz;i++)
                cycle[i] = new_cycle[i];
            trackcycle(cycle,new_siz,tar);
        }
        else
        {
            cout<<"1\n";
            tar = (tar+1)/2;
            for(i=0;i<siz;i++)
            {
                if(i%2==0 && tar)
                {
                    cout<<cycle[i]+1<<" ";
                    tar--;
                }
            }
        }
    }
    else
    {
        cout<<"2\n";
        cout<<siz<<"\n";
        for(i=0;i<siz;i++)
        {
            cout<<cycle[i]+1<<" ";
        }
    }
}

int main()
{
    cin>>n>>m>>k;
    for(i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        tree[a-1].push_back(b-1);
        tree[b-1].push_back(a-1);
    }
    dfs(0,-1,1);
    if(last == -1)
    {
        int odd = 0, even = 0;
        for(i=0;i<n;i++)
        {
            if(depth[i]%2)
                odd++;
            else
                even++;
        }
        if(odd>=(k+1)/2)
            aim = 1;
        int counti = 0;
        cout<<1<<"\n";
        for(i=0;i<n;i++)
        {
            if(depth[i]%2==aim && counti <(k+1)/2)
            {
                cout<<i+1<<" ";
                counti++;
            }
        }
    }
    else
    {
        int siz = 2;
        int i = 1;
        cycle[0] = last;
        cycle[1] = last_previous;
        while(previous[cycle[i]]!=last)
        {
            cycle[siz] = previous[cycle[i]];
            i++;
            siz++;
        }
        cycle[siz] = previous[cycle[i]];
        trackcycle(cycle,siz,k);
    }
    return 0;
}
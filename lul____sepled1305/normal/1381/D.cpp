#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int T;
int dp[N][3];
int dpar[N];
 
int find_depth(int node, int par, vector<int> G[])
{
    if(G[node].size() == 1 && par!=node)
        return 0;
    for(auto it: G[node])
    {
        if(it != par)
        {
            int cur = find_depth(it,node,G)+1;
            if(cur>dp[node][2])
            {
                dp[node][2] = cur;
                sort(dp[node],dp[node]+3,greater<int>());
            }
        }
    }
    return dp[node][0];
}
 
void find_depth_from_par(int node, int par, vector<int> G[], int root)
{
    if(node!=root)
    {
        if(dp[par][0] == dp[node][0]+1)
            dpar[node] = dp[par][1]+1;
        else
            dpar[node] = dp[par][0]+1;
 
        if(dpar[node] > dp[node][2])
        {
            dp[node][2] = dpar[node];
            sort(dp[node],dp[node]+3,greater<int>());
        }
    }
 
    for(auto it: G[node])
        if(it != par)
            find_depth_from_par(it,node,G,root);
}
 
int find_size(int node, int par, vector<int> G[], int root, int tar)
{
    if(node == tar)
        return 0;
    int cur = -1;
    for(auto it: G[node])
    {
        if(it!=par)
            cur = max(cur,find_size(it,node,G,root,tar));
    }
    if(cur==-1)
        return -1;
    else
        return cur+1;
}
 
int find_par_depth_son(int node,int pa,vector<int> G[], int deepness, int par[], int depth[], int son[])
{
    par[node] = pa;
    depth[node] = deepness;
    son[node] = -1;
    int cur=0;
    for(auto it: G[node])
    {
        if(it != pa)
        {
            int here  = find_par_depth_son(it,node,G,deepness+1,par,depth,son)+1;
            if(here > cur)
            {
                son[node] = it;
                cur = here;
            }
        }
    }
    return cur;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin>>T;
    while(T--)
    {
        int n,a,b,i,j,des = -1;
        cin>>n>>a>>b;
        a--,b--;
        vector<int> G[n];
        for(j=0;j<n;j++)
            for(i=0;i<3;i++)
                dp[j][i] = 0;
        for(i=0;i<n;i++)
            dpar[i] = 0;
        for(i=0;i<n-1;i++)
        {
            int x,y;
            cin>>x>>y;
            x--,y--;
            G[x].push_back(y);
            G[y].push_back(x);
        }
        find_depth(0,0,G);
        find_depth_from_par(0,0,G,0);
        int siz = find_size(a,a,G,a,b) +1;
        for(i=0;i<n;i++)
        {
            if(dp[i][2] >= siz -1 )
                des = i;
        }
        if(des == -1)
            cout<<"NO\n";
        else
        {
            int par[n];
            int depth[n];
            int son[n];
            map<int,int> mphead;
            map<int,int> mptail;
            find_par_depth_son(des,des,G,0,par,depth,son);
            int head = a, tail = b, maxi = -1;
            bool pass = false;
            bool hea = true;
            while(true)
            {
                while(son[head]!=-1)
                {
                    tail = par[tail];
                    head = son[head];
                }
                if(depth[head]-depth[tail] >= siz-1)
                {
                    pass = true;
                    break;
                }
                if(hea)
                {
                    if(mphead.count(depth[head]))
                        break;
                    else
                        mphead.insert({depth[head],0});
                }
                else
                {
                    if(mptail.count(depth[head]))
                        break;
                    else
                        mptail.insert({depth[head],0});
                }
                swap(head, tail);
                if(hea)
                    hea = false;
                else
                    hea = true;
            }
            if(pass)
                cout<<"YES\n";
            else
                cout<<"NO\n";
        }
    }
    return 0;
}
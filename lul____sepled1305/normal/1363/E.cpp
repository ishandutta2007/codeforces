#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9;
const int N = 2e5+10;
int n,i,deep,b_count,c_count;
vector<vector<int>> tree;
int parent[N];
pair<int,int> depth[N];
int node[N][3];
int mini[N];
int bur[N][2];
long long ans = 0LL;

int main()
{
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>node[i][0]>>node[i][1]>>node[i][2];
        b_count+=node[i][1];
        c_count+=node[i][2];
    }
    if(b_count!=c_count)
        cout<<-1;
    else
    {
        for(i=0;i<n;i++)
        {
            vector<int> v;
            tree.push_back(v);
            depth[i].first = INF;
        }
        for(i=0;i<n-1;i++)
        {
            int a,b;
            cin>>a>>b;
            tree[a-1].push_back(b-1);
            tree[b-1].push_back(a-1);
        }
        stack<int> st;
        st.push(0);
        depth[0].first = 0;
        depth[0].second = 0;
        mini[0] = node[0][0];
        while(!st.empty())
        {
            int here = st.top();
            st.pop();
            for(auto it: tree[here])
            {
                if(depth[it].first==INF)
                {
                    parent[it] = here;
                    mini[it] = min(mini[here],node[it][0]);
                    depth[it].first = depth[here].first + 1;
                    depth[it].second = it;
                    st.push(it);
                }
            }
        }
        sort(depth,depth+n,greater<pair<int,int>>());
        for(i=0;i<n;i++)
        {
            int here = depth[i].second;
            if(node[here][1]!=node[here][2])
            {
                if(node[here][1])
                    bur[here][0]++;
                else
                    bur[here][1]++;
            }
            int add = min(bur[here][0],bur[here][1]);
            ans+=1LL*mini[here]*add*2;
            bur[here][0]-=add;
            bur[here][1]-=add;
            bur[parent[here]][0]+=bur[here][0];
            bur[parent[here]][1]+=bur[here][1];
        }
        cout<<ans;
    }
    return 0;
}
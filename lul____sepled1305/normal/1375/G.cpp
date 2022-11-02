#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
int n,i,a,b,black,white;
int depth[N];
bool visit[N];
vector<int> tree[N];

int main()
{
    cin>>n;
    for(i=0;i<n-1;i++)
    {
        cin>>a>>b;
        tree[a-1].push_back(b-1);
        tree[b-1].push_back(a-1);
    }
    stack<int> st;
    st.push(0);
    depth[0] = 0;
    while(!st.empty())
    {
        int node = st.top();
        st.pop();
        for(auto it: tree[node])
        {
            if(!visit[it])
            {
                visit[it] = true;
                depth[it] = depth[node] + 1;
                st.push(it);
            }
        }
    }
    for(i=0;i<n;i++)
    {
        if(depth[i]%2)
            white++;
        else
            black++;
    }
    cout<<min(black,white)-1;
    return 0;
}
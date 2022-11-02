#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int i,j,k,n,m,g,r;
vector<int> arr;
using pii = pair<int,int>;
vector<vector<bool>> visit;
vector<vector<queue<pii>>> q;
vector<queue<pii>> standard;
queue<pii> qu;

int dijkstra()
{
    int mod = g+r;
    int mini = INF;
    int distance,counti,pointer1=0,pointer2=0;
    for(i=0;i<m;i++)
    {
        for(j=0;j<g;j++)
        {
            visit[i][j]=false;
        }
    }
    visit[0][0] = true;
    standard.resize(g, qu);
    q.resize(3, standard);
    counti = 1;
    q[pointer1][pointer2].push({0,0});
    while(counti)
    {
        int to=0,d_to=0,v_to=0,pointer3=0,loop=0;
        while(q[pointer1][pointer2].empty())
        {
            if(pointer2 == g-1)
            {
                pointer1++;
                pointer1=pointer1%2;
                pointer2=0;
                loop++;
                if(loop>=3)
                {
                    cout<<"STUPID BUG";
                    break;
                }
            }
            else
                pointer2++;
        }
        pii here = q[pointer1][pointer2].front();
        q[pointer1][pointer2].pop();
        counti--;
        int v = here.second;
        int d_v = here.first;
        int ss = d_v%mod;
        if(d_v >= mini)
            break;
        else
        {
            if(v==0)
            {
                to = 1;
                d_to = d_v + arr[1]-arr[0];
                v_to = ss + arr[1]-arr[0];
                pointer3 = pointer1;
                if(v_to > g)
                    continue;
                if (v_to == g)
                {
                    pointer3 = pointer1+1;
                    d_to+=r;
                }
                v_to = v_to%g;
                if (!visit[to][v_to])
                {
                    visit[to][v_to] = true;
                    q[pointer3%2][v_to].push({d_to,to});
                    counti++;
                }
            }
            else if(v<m-1)
            {
                pointer3=pointer1;
                to = v+1;
                v_to = ss + arr[to]-arr[to-1];
                d_to = d_v + arr[to]-arr[to-1];
                if(v_to <= g){
                    if (v_to == g && to!=m-1)
                    {
                        pointer3 = pointer1+1;
                        d_to+=r;
                    }
                    if(to == m-1)
                    {
                        if(d_to < mini)
                            mini = d_to;
                    }
                    v_to = v_to%g;
                    if (!visit[to][v_to])
                    {
                        visit[to][v_to] = true;
                        q[pointer3%2][v_to].push({d_to,to});
                        counti++;
                    }
                }
 
                to = v-1;
                pointer3 = pointer1;
                v_to = ss + arr[to+1]-arr[to];
                d_to = d_v + arr[to+1]-arr[to];
                if(v_to <= g){
                    if (v_to == g)
                    {
                        pointer3=pointer1+1;
                        d_to+=r;
                    }
                    v_to = v_to%g;
                    if (!visit[to][v_to])
                    {
                        visit[to][v_to] = true;
                        q[pointer3%2][v_to].push({d_to,to});
                        counti++;
                    }
                }
            }
        }
    }
    if(mini == 1e9)
        mini = -1;
    return mini;
}
 
int main()
{
    cin>>n>>m;
    for(i=0;i<m;i++)
    {
        cin>>j;
        arr.push_back(j);
    }
    sort(arr.begin(),arr.end());
    cin>>g>>r;
 
    visit.resize(m, vector<bool>(g));
 
    cout<<dijkstra();
    return 0;
}
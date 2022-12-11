#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int > g[3333];
int colour[3333];
int p[3333];
int d[3333];
int used[3333];
queue<int> que,que1;
bool flag;

void dfs(int v)
{
    //cout<<"v ="<<v<<endl;
    colour[v]=1;
    for(int i=0;i<g[v].size();i++)
    {
        if (flag==true)
        return ;
        if(colour[g[v][i]]==0)
        {
            p[g[v][i]]=v;
            //cout<<"predok "<<g[v][i]<<" eto "<<v<<endl;
            dfs(g[v][i]);
            continue;
        }
        if(colour[g[v][i]]==1 && p[v]!=g[v][i])
        {
            //que.push(g[v][i]);
            p[g[v][i]]=-1;

            for(int j=v; j!=-1; j=p[j])
                {
                    //cout<<"j = "<<j<<" p[j] = "<<p[j]<<endl;
                    que.push(j);
                    used[j]=true;
                    //cout<<j<<" v cycle"<<endl;
                }
            flag=true;
            break;
        }
    }
if (flag==true)
        return ;
    colour[v]=2;

}

void bfs (int q)
{
    que1.push(q);
    //used[q]=true;
    while(!que1.empty())
    {
        int v=que1.front();
        que1.pop();
        for(int i=0;i<g[v].size();i++)
        {
            if(used[g[v][i]]==false)
            {
                used[g[v][i]]=true;
                que1.push(g[v][i]);
                d[g[v][i]]=d[v]+1;
            }
        }

    }
}


int main()
{
    int n,tmp1,tmp2;
    cin>>n;
    for(int i=0;i<3333;i++)
        p[i]=-1;
    for(int i=0;i<n;i++)
    {
        cin>>tmp1>>tmp2;
        g[tmp1-1].push_back(tmp2-1);
        g[tmp2-1].push_back(tmp1-1);
    }
        dfs(0);


    while(!que.empty())
    {
        d[que.front()]=0;
        bfs(que.front());
        que.pop();
    }

    for(int i=0;i<n;i++)
        cout<<d[i]<<" ";

    return 0;
}
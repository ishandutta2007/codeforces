#include<bits/stdc++.h>
using namespace std;

const int nmax=3e5+42;

void wrong()
{
    printf("0\n");
    exit(0);
}

int n,q;

vector<int> edges[nmax];

int nxt[nmax];
bool used[nmax];

vector<int> adj[nmax];
int in[nmax];

int where_in_path[nmax];

int component[nmax],comp;

vector<int> path[nmax];

vector<int> compressed[nmax];

int force_path(int start)
{
    comp++;

    path[comp]={start};

    where_in_path[start]=0;

    while(nxt[start])
    {
        start=nxt[start];

        where_in_path[start]=path[comp].size();

        path[comp].push_back(start);
    }

    //cout<<"path: ";for(auto w:path[comp])cout<<w<<" ";cout<<endl;

    for(auto w:path[comp])
        component[w]=comp;

    for(auto u:path[comp])
        for(auto v:adj[u])
            if(component[u]==component[v])
            {
                if(where_in_path[u]>where_in_path[v])
                    wrong();
            }
}

void make()
{
    for(int i=1;i<=n;i++)
        if(component[i]==0)
            wrong();

    for(int t=1;t<=comp;t++)
    {

    for(auto u:path[t])
        for(auto v:adj[u])
            if(component[u]!=component[v])
            {
                //cout<<"edge: "<<component[u]<<" "<<component[v]<<endl;

                compressed[component[u]].push_back(component[v]);
                in[component[v]]++;
            }
    }

}

queue<int> que;

int order[nmax];

void print()
{
    for(int i=1;i<=comp;i++)
    {
        for(auto w:path[order[i]])
            printf("%i ",w);
    }

    printf("\n");
}

void topo()
{
    for(int i=1;i<=comp;i++)
        if(in[i]==0)que.push(i);

    for(int i=1;i<=comp;i++)
    {
        if(que.size()==0)wrong();

        int cur=que.front();

        //cout<<"cur= "<<cur<<endl;

        que.pop();

        order[i]=cur;

        for(auto w:compressed[cur])
        {
            in[w]--;

            if(in[w]==0)
            {
                que.push(w);
            }
        }
    }

    print();
}

int main()
{
    memset(where_in_path,-1,sizeof(where_in_path));

    scanf("%i%i",&n,&q);

    for(int i=1;i<=n;i++)
    {
        int p;

        scanf("%i",&p);

        if(p)
        {
            adj[p].push_back(i);
        }
    }

    for(int i=1;i<=q;i++)
    {
        int u,v;

        scanf("%i%i",&u,&v);

        nxt[u]=v;
        used[v]=1;
    }

    for(int i=1;i<=n;i++)
        if(used[i]==0)
            force_path(i);

    make();

    topo();

    return 0;
}
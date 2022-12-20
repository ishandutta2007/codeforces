#include<bits/stdc++.h>
using namespace std;
const int nmax=5e5+42,kmax=51;

int n,m,k,q;

pair<int,int> input[nmax];

pair<int/*edge*/,int/*new colour*/> queries[nmax];

bool can[nmax];

int nxt[nmax];

int last_seen[nmax];

int parent[kmax][nmax];
int height[kmax][nmax];
bool add[kmax][nmax];

vector< pair<int/*edge*/,int/*colour*/> > tree[4*nmax];

pair<int/*root*/,int/*height*/> root(int colour,int node)
{
    //cout<<"root "<<colour<<" "<<node<<" -> ";

    int ret=0;
    while(parent[colour][node]!=node)
    {
        ret=ret+1+add[colour][node];
        node=parent[colour][node];
    }

    //cout<<node<<" "<<ret<<endl;
    return {node,ret};
}

int current_colour_of_edge[nmax];

pair<int/*edge*/,int/*colour*/> current;

void note(int node,int l,int r,int lq,int rq)
{
    if(l==lq&&r==rq)
    {
        tree[node].push_back(current);
        return;
    }
    int av=(l+r)/2;
    if(lq<=av)note(node*2,l,av,lq,min(av,rq));
    if(av<rq)note(node*2+1,av+1,r,max(av+1,lq),rq);
}
void solve(int node,int l,int r)
{
    vector< pair< pair< pair<int/*big*/,int/*small*/> ,int/*was the height of the bigger increased*/>,int/*colour*/> > added={};
    /*
    cout<<"node= "<<node<<" l= "<<l<<" r= "<<r<<endl;

    for(int i=1;i<=n;i++)
    {
        cout<<i<<" -> "<<root(1,i).first<<" "<<root(1,i).second<<" "<<add[1][i]<<endl;
    }
    */
    for(int i=0;i<tree[node].size();i++)
    {
        pair<int/*edge*/,int/*colour*/> k=tree[node][i];
        int colour=k.second;

        pair<int/*root*/,int/*height*/> le=root(k.second,input[k.first].first);
        pair<int/*root*/,int/*height*/> ri=root(k.second,input[k.first].second);
        /*
        cout<<"k: "<<k.first<<" "<<k.second<<endl;
        cout<<"le: "<<le.first<<" "<<le.second<<endl;
        cout<<"ri: "<<ri.first<<" "<<ri.second<<endl;
        */
        if(le.first==ri.first)
        {
            assert((le.second%2!=ri.second%2));
            continue;
        }
        if(height[colour][le.first]<height[colour][ri.first])swap(le,ri);

        parent[colour][ri.first]=le.first;

        added.push_back({{{le.first,ri.first},0},colour});

        if(height[colour][le.first]==height[colour][ri.first])
        {
            height[colour][le.first]++;
            added[added.size()-1].first.second=1;
        }

        if(le.second%2!=ri.second%2)
        {
            add[colour][ri.first]=1;
        }
    }

    if(l==r)
    {
        int colour=queries[l].second;

        pair<int/*root*/,int/*height*/> le=root(colour,input[queries[l].first].first);
        pair<int/*root*/,int/*height*/> ri=root(colour,input[queries[l].first].second);

        if(le.first==ri.first&&le.second%2==ri.second%2)
        {
            can[l]=0;
            current={queries[l].first,current_colour_of_edge[queries[l].first]};
        }
        else
        {
            can[l]=1;
            current=queries[l];
        }

        current_colour_of_edge[current.first]=current.second;
        /*
        cout<<"testing: "<<le.first<<" "<<le.second<<" "<<ri.first<<" "<<ri.second<<endl;
        cout<<"during node= "<<node<<" l= "<<l<<endl;
        */
        /*
        for(int i=1;i<=k;i++)
        {
            cout<<i<<" -> ";for(int j=1;j<=n;j++)cout<<root(i,j).first<<" "<<root(i,j).second<<"\t";cout<<endl;
        }
        */
        if(l+1<=nxt[r]-1&&current.second)
        {
            //cout<<"noted edge "<<current.first<<" with colour "<<current.second<<" on interval "<<l+1<<" "<<nxt[r]-1<<endl;
            note(1,1,q,l+1,nxt[r]-1);
        }
    }
    else
    {
        int av=(l+r)/2;
        solve(node*2,l,av);
        solve(node*2+1,av+1,r);
    }

    reverse(added.begin(),added.end());
    for(auto k:added)
    {
        height[k.second][k.first.first.first]-=k.first.second;

        parent[k.second][k.first.first.second]=k.first.first.second;

        add[k.second][k.first.first.second]=0;
    }
}
int main()
{
    scanf("%i%i%i%i",&n,&m,&k,&q);

    for(int i=1;i<=k;i++)
        for(int j=1;j<=n;j++)
        {
            parent[i][j]=j;
            height[i][j]=0;
        }
    for(int i=1;i<=m;i++)
    {
        scanf("%i%i",&input[i].first,&input[i].second);
        if(input[i].first>input[i].second)swap(input[i].first,input[i].second);
    }

    for(int i=1;i<=q;i++)
    {
        scanf("%i%i",&queries[i].first,&queries[i].second);
    }

    for(int i=1;i<=m;i++)last_seen[i]=q+1;

    for(int i=q;i>=1;i--)
    {
        nxt[i]=last_seen[queries[i].first];
        last_seen[queries[i].first]=i;
    }

    //for(int i=1;i<=q;i++)cout<<nxt[i]<<" ";cout<<endl;

    solve(1,1,q);

    for(int i=1;i<=q;i++)
        if(can[i])printf("YES\n");
        else printf("NO\n");

    return 0;
}
/*
5 10 1 15

3 4
2 4
3 4
2 5
2 5
2 3
2 4
1 2
1 4
3 5

1 1
8 1
9 1
2 1
4 1
8 1
6 1
9 1
3 1
2 1
7 1
3 1
5 1
9 1
1 1
*/
#include<bits/stdc++.h>
using namespace std;

const int nmax=5e5+42;

int n,m,k;

int group[nmax];

int colour[nmax];

int parent[nmax];
int add[nmax],sz[nmax];

pair<int,int> root(int u)
{
    int sum=0;

    while(parent[u]!=u)
    {
        sum+=add[u];
        u=parent[u];
    }
    return {u,sum};
}

int pointer=0;

pair< pair< pair<int,int> , pair<int,int> >,int> done[nmax];

bool my_merge(int u,int v)
{
    /*
    cout<<"parent: ";for(int i=1;i<=n;i++)cout<<parent[i]<<" ";cout<<endl;
    cout<<"add: ";for(int i=1;i<=n;i++)cout<<add[i]<<" ";cout<<endl;
    */
    if(sz[u]<sz[v])swap(u,v);

    pair<int,int> help_u=root(u),help_v=root(v);
    /*
    cout<<"my_merge "<<u<<" "<<v<<endl;
    cout<<help_u.first<<" "<<help_u.second<<" "<<help_v.first<<" "<<help_v.second<<endl<<"---"<<endl;
    */
    if(help_u.first==help_v.first&&(help_u.second+help_v.second)%2==0)return 0;

    if(help_u.first==help_v.first)return 1;

    pointer++;
    done[pointer]={{{u,v},{help_u.first,help_v.first}},(help_u.second+help_v.second)%2};

    sz[u]=sz[u]+sz[v];
    parent[help_v.first]=help_u.first;

    if((help_u.second+help_v.second)%2==0)add[help_v.first]=!add[help_v.first];
    return 1;
}

map< pair<int,int>, vector< pair<int,int> > > mem;

void my_pop(int to)
{
    while(pointer>to)
    {
        int u=done[pointer].first.first.first;
        int v=done[pointer].first.first.second;

        int help_u=done[pointer].first.second.first;
        int help_v=done[pointer].first.second.second;

        int extra=done[pointer].second;

        sz[u]=sz[u]-sz[v];

        parent[help_v]=help_v;

        if(extra%2==0)add[help_v]=!add[help_v];

        pointer--;
    }
}
bool wrong(int comp_1,int comp_2)
{
    /*
    cout<<"---"<<endl;
    cout<<"\t testing "<<comp_1<<" "<<comp_2<<endl;
    */
    int mem_pointer=pointer;

    for(auto k:mem[{comp_1,comp_2}])
    {
        if(my_merge(k.first,k.second)==0)
        {
            my_pop(mem_pointer);
            return 1;
        }
    }

    my_pop(mem_pointer);
    return 0;
}

bool bad[nmax];

int main()
{
    scanf("%i%i%i",&n,&m,&k);

    for(int i=1;i<=n;i++)scanf("%i",&group[i]);

    for(int i=1;i<=n;i++)parent[i]=i,sz[i]=1;

    for(int i=1;i<=m;i++)
    {
        int u,v;

        scanf("%i%i",&u,&v);

        if(group[u]==group[v])
        {
            if(my_merge(u,v)==0)bad[group[u]]=1;
        }
        else
        {
            if(group[u]>group[v])swap(u,v);
            mem[{group[u],group[v]}].push_back({u,v});
        }
    }

    int cnt=0;

    long long outp=0;

    for(int i=1;i<=k;i++)
        if(bad[i]==0)cnt++;

    outp=1LL*cnt*(cnt-1)/2;

    //cout<<"cnt= "<<cnt<<endl;

    for(auto k:mem)
        if(bad[k.first.first]||bad[k.first.second])continue;
        else if(wrong(k.first.first,k.first.second))outp--;

    printf("%lld\n",outp);
    return 0;
}
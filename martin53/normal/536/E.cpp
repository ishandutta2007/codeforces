#include<bits/stdc++.h>
using namespace std;
const int nmax=1e5+42;

int n,q;
int values[nmax];

struct edge
{
    int from,to,cost;
    int id;
    //id>0 => edge, id<0 => query
};

edge input[nmax*2];

vector< edge > adj[nmax];

bool cmp(edge a,edge b)
{
    if(a.cost!=b.cost)return a.cost>b.cost;
    return a.id>b.id;
}

int parent_edge_id[nmax];

int up[nmax][20];

int h[nmax];

int SZ[nmax];

void dfs(int node,int par,int edge_id)
{
    parent_edge_id[node]=edge_id;
    up[node][0]=par;

    h[node]=h[par]+1;

    SZ[node]=1;

    for(auto k:adj[node])
        if(k.to!=par)
        {
            dfs(k.to,node,k.id);
            SZ[node]+=SZ[k.to];
        }
}

int chain[nmax];
int c=1;

vector<int> path[nmax];
map<int,int> seen[nmax];/*which is the number in the path i*/

void create_chains(int node,int par)
{
    chain[node]=c;
    int big=0;
    for(auto k:adj[node])
        if(k.to!=par)
            if(SZ[big]<SZ[k.to])big=k.to;

    if(big==0)
    {
        //cout<<"create_chains: "<<node<<" "<<par<<" "<<c<<endl;

        seen[chain[node]][node]=path[chain[node]].size();
        path[chain[node]].push_back(node);
        return;
    }
    create_chains(big,node);

    for(auto k:adj[node])
        if(k.to!=par&&k.to!=big)
        {
            c++;
            create_chains(k.to,node);
        }

    //cout<<"create_chains: "<<node<<" "<<par<<" "<<c<<endl;

    seen[chain[node]][node]=path[chain[node]].size();
    path[chain[node]].push_back(node);
}
bool on[nmax];

struct info
{
    long long sum;
    int sz_total,sz_left,sz_right;
};

void print(info a)
{
    cout<<a.sum<<" "<<a.sz_total<<" "<<a.sz_left<<" "<<a.sz_right<<endl;
}
info my_merge(info le,info ri)
{
    info ret;
    ret.sz_total=le.sz_total+ri.sz_total;

    ret.sz_left=le.sz_left;
    if(le.sz_left==le.sz_total)ret.sz_left=le.sz_left+ri.sz_left;

    ret.sz_right=ri.sz_right;
    if(ri.sz_right==ri.sz_total)ret.sz_right=ri.sz_right+le.sz_right;

    ret.sum=le.sum+ri.sum;
    ret.sum=ret.sum-values[le.sz_right]-values[ri.sz_left]+values[le.sz_right+ri.sz_left];
    /*
    cout<<"le: ";print(le);
    cout<<"ri: ";print(ri);
    cout<<"ret: ";print(ret);
    */
    return ret;
}

info idle()
{
    info ret;
    ret.sum=0;ret.sz_left=0;ret.sz_right=0;ret.sz_total=0;
    return ret;
}
vector< info > tree[nmax];

void build(int colour,int node,int l,int r)
{
    //cout<<"build "<<colour<<" "<<node<<" "<<l<<" "<<r<<endl;
    while(tree[colour].size()<=node)
        tree[colour].push_back(idle());

    if(l==r)
    {
        tree[colour][node].sz_total=1;
        return;
    }

    int av=(l+r)/2;
    build(colour,node*2+1,l,av);
    build(colour,node*2+2,av+1,r);

    tree[colour][node]=my_merge(tree[colour][node*2+1],tree[colour][node*2+2]);
}

void update(int colour,int node,int l,int r,int pos)
{
    if(l==r)
    {
        //cout<<"\t"<<colour<<" "<<node<<" "<<l<<" "<<r<<" "<<pos<<" is now on"<<endl;
        tree[colour][node].sum=values[1];
        tree[colour][node].sz_left=1;
        tree[colour][node].sz_right=1;
        tree[colour][node].sz_total=1;
        return;
    }

    int av=(l+r)/2;

    if(pos<=av)update(colour,node*2+1,l,av,pos);
    else update(colour,node*2+2,av+1,r,pos);

    tree[colour][node]=my_merge(tree[colour][node*2+1],tree[colour][node*2+2]);

    //cout<<"\t"<<colour<<" "<<node<<" "<<l<<" "<<r<<" -> "<<tree[colour][node].sum<<" "<<tree[colour][node].sz_total<<" "<<tree[colour][node].sz_left<<" "<<tree[colour][node].sz_right<<endl;
}

info query(int colour,int node,int l,int r,int lq,int rq)
{
    if(l==lq&&r==rq)return tree[colour][node];
    int av=(l+r)/2;
    info ret=idle();

    if(lq<=av)ret=my_merge(ret,query(colour,node*2+1,l,av,lq,min(av,rq)));
    if(av<rq)ret=my_merge(ret,query(colour,node*2+2,av+1,r,max(av+1,lq),rq));

    return ret;
}
info ask(int low,int high)
{
    info ret=idle();
    if(low==high)return ret;

    while(low!=high)
    {
        //cout<<"low= "<<low<<" high= "<<high<<endl;
        if(chain[low]!=chain[up[low][0]])
        {
            //cout<<"light"<<endl;
            //the parent edge is light
            info current=idle();

            if(on[parent_edge_id[low]])
            {
            current.sum=values[1];
            current.sz_left=1;
            current.sz_right=1;
            current.sz_total=1;
            }
            else current.sz_total=1;

            ret=my_merge(ret,current);
            low=up[low][0];
            continue;
        }


        if(chain[low]!=chain[high])
        {
            //cout<<"different chains"<<endl;
            //different chains
            info current=idle();
            current=query(chain[low],0,0,path[chain[low]].size()-2,seen[chain[low]][low],path[chain[low]].size()-2);

            ret=my_merge(ret,current);
            low=path[chain[low]][path[chain[low]].size()-1];

        }
        else
        {
            //cout<<"same chains"<<endl;
            //same chains
            int ri=seen[chain[high]][high]-1;

            int le=seen[chain[low]][low];

            info current=query(chain[low],0,0,path[chain[low]].size()-2,le,ri);

            ret=my_merge(ret,current);
            low=high;
        }
    }

    return ret;
}
int lca(int u,int v)
{
    if(h[u]<h[v])swap(u,v);

    for(int i=19;i>=0;i--)
        if(h[u]-(1<<i)>=h[v])
            u=up[u][i];
    if(u==v)return u;

    for(int i=19;i>=0;i--)
        if(up[u][i]!=up[v][i])
        {
            u=up[u][i];
            v=up[v][i];
        }
    return up[u][0];
}

long long output[nmax];
int main()
{
    scanf("%i%i",&n,&q);

    for(int i=1;i<n;i++)scanf("%i",&values[i]);

    for(int i=1;i<n;i++)
    {
        scanf("%i%i%i",&input[i].from,&input[i].to,&input[i].cost);

        input[i].id=i;

        adj[input[i].from].push_back(input[i]);
        swap(input[i].from,input[i].to);
        adj[input[i].from].push_back(input[i]);
        swap(input[i].from,input[i].to);
    }
    /*
    for(int i=1;i<=n;i++)
    {
        cout<<i<<" -> ";for(auto k:adj[i])cout<<k.to<<" ";cout<<endl;
    }
    */
    for(int i=1;i<=q;i++)
    {
        scanf("%i%i%i",&input[i+n-1].from,&input[i+n-1].to,&input[i+n-1].cost);
        input[i+n-1].id=-i;
    }

    sort(input+1,input+n+q-1+1,cmp);

    dfs(1,1,1);

    create_chains(1,1);

    //for(int i=1;i<=n;i++)cout<<chain[i]<<" ";cout<<endl;

    for(int i=1;i<=c;i++)
    {
        //cout<<i<<" -> ";for(auto k:path[i])cout<<k<<" ";cout<<endl;

        if(path[i].size()>=2)build(i,0,0,path[i].size()-2);
    }


    for(int level=1;level<20;level++)
        for(int i=1;i<=n;i++)
            up[i][level]=up[up[i][level-1]][level-1];

    for(int i=1;i<=n+q-1;i++)
    {
        //cout<<i<<" -> "<<input[i].from<<" "<<input[i].to<<" "<<input[i].cost<<" "<<input[i].id<<endl;

        if(input[i].id>0)
        {
            on[input[i].id]=1;
            int low=input[i].from,high=input[i].to;
            if(h[low]<h[high])swap(low,high);

            if(chain[low]!=chain[high])continue;

            int id=seen[chain[low]][low];

            //cout<<"id= "<<id<<endl;

            update(chain[low],0,0,path[chain[low]].size()-2,id);
        }
        else
        {
            int where=lca(input[i].from,input[i].to);

            //cout<<"where= "<<where<<endl;

            info a=ask(input[i].from,where);

            //cout<<"a: ";print(a);

            info b=ask(input[i].to,where);

            //cout<<"b: ";print(b);

            swap(b.sz_left,b.sz_right);

            output[-input[i].id]=my_merge(a,b).sum;
        }

        //cout<<"---"<<endl;
    }

    for(int i=1;i<=q;i++)
        printf("%lld\n",output[i]);
    return 0;
}
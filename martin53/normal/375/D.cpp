#include<bits/stdc++.h>
using namespace std;
const int nmax=1e5+42;
struct que
{
    int k,index;
};

struct node
{
    int SZ=0;
    map<int,int> seen={};
    vector<int> times_seen={0};
    vector<int> fenwick={0};
};
node all[nmax];

void upd(int node,int index,int add)
{
    //cout<<
    all[node].SZ+=add;
    if(all[node].times_seen.size()==index)
    {
        int j=index-(index&(-index));
        j++;
        all[node].times_seen.push_back(1);
        all[node].fenwick.push_back(0);
        for(int k=j;k<=index;k++)
            all[node].fenwick[index]+=all[node].times_seen[k];
        return;
    }
    all[node].times_seen[index]+=add;
    while(index<all[node].times_seen.size())
    {
        all[node].fenwick[index]+=add;
        index=index+(index&(-index));
    }
}
void update(int node,int value)
{
    if(all[node].seen[value])upd(node,all[node].seen[value],-1);
    upd(node,all[node].seen[value]+1,1);
    all[node].seen[value]++;
}
int sum(int node,int index)
{
    //cout<<"sum "<<node<<" "<<index<<" -> ";
    int ret=0;
    while(index)
    {
        ret=ret+all[node].fenwick[index];
        index=index-(index&(-index));
    }
    //cout<<ret<<endl;
    return ret;
}
int query(int node,int req)
{
    //cout<<"query "<<node<<" "<<req<<endl;
    if(req>=all[node].times_seen.size())return 0;
    return sum(node,all[node].times_seen.size()-1)-sum(node,req-1);
}

vector<int> adj[nmax];
vector< que > queries[nmax];
int arr[nmax];
int n,m;

int output[nmax];
int dfs(int node,int parent)
{
    update(node,arr[node]);
    int where=node;
    for(auto k:adj[node])
        if(k!=parent)
        {
            int now=dfs(k,node);
            if(all[where].SZ<all[now].SZ)swap(where,now);
            for(auto k:all[now].seen)
            {
                for(int i=1;i<=k.second;i++)
                    update(where,k.first);
            }
        }
    /*
    cout<<"node= "<<node<<" parent= "<<parent<<endl;
    for(auto k:all[where].seen)
        cout<<k.first<<" "<<k.second<<endl;
    cout<<"---"<<endl;
    for(auto k:all[where].times_seen)
        cout<<k<<" ";cout<<endl;
    cout<<"---"<<endl;
    for(auto k:all[where].fenwick)
        cout<<k<<" ";cout<<endl;
    cout<<"---"<<endl;
    */
    for(auto k:queries[node])
        {
        //cout<<"asking "<<node<<" "<<k.k<<" "<<k.index<<endl;
        output[k.index]=query(where,k.k);
        }
    return where;
}
int main()
{
scanf("%i%i",&n,&m);
for(int i=1;i<=n;i++)scanf("%i",&arr[i]);

int a,b;
for(int i=1;i<n;i++)
{
    scanf("%i%i",&a,&b);
    adj[a].push_back(b);
    adj[b].push_back(a);
}

int q;
que now;
for(int i=1;i<=m;i++)
{
    scanf("%i",&q);
    scanf("%i",&now.k);
    now.index=i;
    queries[q].push_back(now);
}

dfs(1,0);

for(int i=1;i<=m;i++)
    printf("%i\n",output[i]);
return 0;
}
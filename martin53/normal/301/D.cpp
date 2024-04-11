#include<bits/stdc++.h>
using namespace std;
const int nmax=2e5+42;

int n,arr[nmax];
int where[nmax];

vector<int> adj[nmax];

struct query
{
    int id,l,r;
};
int output[nmax];

int q;
query inp[nmax];
bool cmp(query a,query b)
{
    return a.l>b.l;
}

int fenwick[nmax];
void update(int position)
{
    while(position<=n)
    {
        fenwick[position]++;
        position=position+(position&(-position));
    }
}
int ask(int position)
{
    int ret=0;
    while(position)
    {
        ret=ret+fenwick[position];
        position=position-(position&(-position));
    }
    return ret;
}
int sum(int l,int r)
{
    return ask(r)-ask(l-1);
}
int main()
{
    scanf("%i%i",&n,&q);
    for(int i=1;i<=n;i++)
    {
        scanf("%i",&arr[i]);
        where[arr[i]]=i;
    }

    for(int i=1;i<=n;i++)
        for(int j=i;j<=n;j=j+i)
        {
            int l=where[i],r=where[j];
            if(l>r)swap(l,r);
            adj[l].push_back(r);
        }

    for(int i=1;i<=q;i++)
    {
        scanf("%i%i",&inp[i].l,&inp[i].r);
        inp[i].id=i;
    }

    sort(inp+1,inp+q+1,cmp);
    int id_query=1;

    for(int i=n;i>=1;i--)
    {
        for(auto k:adj[i])
            update(k);

        while(id_query<=q&&inp[id_query].l==i)
        {
            output[inp[id_query].id]=sum(inp[id_query].l,inp[id_query].r);
            id_query++;
        }
    }

    for(int i=1;i<=q;i++)
        printf("%i ",output[i]);
    return 0;
}
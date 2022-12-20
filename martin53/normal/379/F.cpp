#include<bits/stdc++.h>
using namespace std;
const int nmax=1e6+42,st=23;
int n;
int go[nmax][st];
int p=2,q=4,dist=2;
int h[nmax];
void add(int parent,int node)
{
    go[node][0]=parent;
    for(int i=1;i<st;i++)
        go[node][i]=go[go[node][i-1]][i-1];
    /*
    for(int i=0;i<st;i++)
        cout<<node<<" st= "<<i<<" "<<go[node][i]<<endl;
    */
    h[node]=h[parent]+1;
}
int lca(int a,int b)
{
    if(h[a]<h[b])swap(a,b);
    for(int i=st-1;i>=0;i--)
        if(h[a]-(1<<i)>=h[b])a=go[a][i];
    if(a==b)return a;
    for(int i=st-1;i>=0;i--)
        if(go[a][i]!=go[b][i])
        {
            a=go[a][i];
            b=go[b][i];
        }
    return go[a][0];
}
int find_dist(int a,int b)
{
    //cout<<a<<" "<<b<<" -> "<<h[a]+h[b]-2*h[lca(a,b)]<<" "<<lca(a,b)<<endl;
    return h[a]+h[b]-2*h[lca(a,b)];
}
int precomp(int x)
{
    int d1=find_dist(p,x),d2=find_dist(q,x);
    if(dist<=d1&&d2<=d1)
    {
        dist=d1;
        q=x;
    }
    else if(dist<=d2&&d1<=d2)
    {
        dist=d2;
        p=x;
    }
}
int main()
{
for(int i=0;i<st;i++)
    go[1][i]=1;
add(1,2);
add(1,3);
add(1,4);
scanf("%i",&n);
int v;
for(int i=1;i<=n;i++)
{
    scanf("%i",&v);
    int j=2*i+3;
    add(v,j);
    precomp(j);
    j++;
    add(v,j);
    precomp(j);
    /*cout<<"ans: ";cout<<p<<" "<<q<<" -> ";*/
    printf("%i\n",dist);
}
return 0;
}
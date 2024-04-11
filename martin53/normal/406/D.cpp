#include<bits/stdc++.h>
using namespace std;
const int nmax=1e5+42;
int n;
pair<long long,long long> inp[nmax];
int parent[nmax];
int h[nmax];
int up[20][nmax];
void prec()
{
    for(int i=1;i<=n;i++)
        up[0][i]=parent[i];
    for(int i=1;(1<<i)<=n;i++)
        for(int j=1;j<=n;j++)
        up[i][j]=up[i-1][up[i-1][j]];
    for(int j=n;j>=1;j--)
        h[j]=h[parent[j]]+1;
}
int lca(int a,int b)
{
    if(h[a]>h[b])swap(a,b);
    for(int i=19;i>=0;i--)
        if(h[b]-(1<<i)>=h[a])b=up[i][b];
    if(a==b)return a;
    for(int i=19;i>=0;i--)
        if(up[i][a]!=up[i][b])a=up[i][a],b=up[i][b];
    return parent[a];
}
int dist(int a,int b)
{
    return h[a]+h[b]-2*h[lca(a,b)];
}
stack<int> active;
long long area(pair<long long,long long> a,pair<long long,long long> b,pair<long long,long long> c)
{
    long long x1=a.first-b.first,x2=a.second-b.second;
    long long y1=b.first-c.first,y2=b.second-c.second;
    return x1*y2-x2*y1;
}
bool rem(int i)
{
    int p=active.top();
    active.pop();
    int q=active.top();
    active.push(p);

    return area(inp[i],inp[p],inp[q])>0;
}
int main()
{
scanf("%i",&n);
for(int i=1;i<=n;i++)scanf("%lld%lld",&inp[i].first,&inp[i].second);

for(int i=n;i>=1;i--)
{
    while(active.size()>=2&&rem(i))active.pop();
    if(active.size())parent[i]=active.top();
    else parent[i]=i;
    active.push(i);
    //cout<<i<<" -> "<<parent[i]<<endl;
}

prec();
int m,a,b;
scanf("%i",&m);
for(int i=1;i<=m;i++)
{
    scanf("%i%i",&a,&b);
    printf("%i\n",lca(a,b));
}
return 0;
}
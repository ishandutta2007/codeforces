#include<bits/stdc++.h>
using namespace std;
const int nmax=1e5+42;
int n,m;
vector<int> adj[nmax];
int out[nmax];
int output[nmax];
priority_queue< int > pq;
int main()
{
scanf("%i%i",&n,&m);
int x,y;
for(int i=1;i<=m;i++)
{
    scanf("%i%i",&x,&y);
    adj[y].push_back(x);
    out[x]++;
}

for(int i=1;i<=n;i++)
    if(out[i]==0)pq.push(i);

for(int t=n;t>=1;t--)
{
    int now=pq.top();
    pq.pop();
    output[now]=t;
    for(auto k:adj[now])
    {
        out[k]--;
        if(out[k]==0)pq.push(k);
    }
}
for(int i=1;i<=n;i++)printf("%i ",output[i]);printf("\n");
return 0;
}
/*
4 1
4 1
*/
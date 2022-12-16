#include<bits/stdc++.h>
using namespace std;
const int nmax=3e5+42;
int n,m;
struct edge
{
int u,v,c;
};
edge inp[nmax];
edge make_edge(int u,int v,int c)
{
edge x;
x.u=u;
x.v=v;
x.c=c;
return x;
}
bool cmp(edge a,edge b)
{
return a.c<b.c;
}
int ans[nmax],new_values[nmax];
int main()
{

cin>>n>>m;
int a,b,c;
for(int i=1;i<=m;i++)
{
scanf("%i%i%i",&a,&b,&c);
inp[i]=make_edge(a,b,c);
}
sort(inp+1,inp+m+1,cmp);
for(int i=1;i<=m;i++)
{
    int j=i+1;
    while(j<=m&&inp[i].c==inp[j].c)j++;
    for(int k=i;k<j;k++)
    {
        new_values[inp[k].v]=max(new_values[inp[k].v],ans[inp[k].u]+1);
    }
    for(int k=i;k<j;k++)
    {
        ans[inp[k].v]=new_values[inp[k].v];
    }
    i=j-1;
}
int outp=0;
for(int i=1;i<=n;i++)outp=max(outp,ans[i]);
cout<<outp<<endl;
return 0;
}
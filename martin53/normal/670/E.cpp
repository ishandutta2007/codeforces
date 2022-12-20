#include<bits/stdc++.h>
using namespace std;
const int nmax=5e5+42;
int n,m,p;
char inp[nmax];
struct node
{
int l,r;
};
node all[nmax];
int other[nmax];
stack<int> open;
int main()
{
ios_base::sync_with_stdio(false);
cin.tie();
cout.tie();
cin>>n>>m>>p;
for(int i=1;i<=n;i++)
{
cin>>inp[i];
if(inp[i]=='(')open.push(i);
    else
    {
    other[i]=open.top();
    other[open.top()]=i;
    open.pop();
    }
}
for(int i=1;i<=n;i++)all[i].l=i-1,all[i].r=i+1;
char now;
for(int i=1;i<=m;i++)
{
cin>>now;
    if(now=='L')
    {
        if(all[p].l==0)continue;
        p=all[p].l;
    }
    if(now=='R')
    {
        if(all[p].r==n+1)continue;
        p=all[p].r;
    }
    if(now=='D')
    {
        if(other[p]==1&&all[p].r==n+1)continue;
        if(other[p]==n&&all[p].l==0)continue;

    int p1=min(p,other[p]),p2=max(p,other[p]);
    int prev=all[p1].l,next=all[p2].r;

    all[prev].r=next;
    all[next].l=prev;

    if(next!=n+1)p=next;
    else p=prev;
    }
}

while(all[p].l)p=all[p].l;
while(p<=n)
{
cout<<inp[p];
p=all[p].r;
}
cout<<endl;
return 0;
}
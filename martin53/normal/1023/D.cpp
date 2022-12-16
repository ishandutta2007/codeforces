#include<bits/stdc++.h>
using namespace std;
const int nmax=2e5+42;
int n,q,arr[nmax];
stack<int> s;
int l[nmax],r[nmax];
int tree[4*nmax];
int help[nmax];
void build(int node,int l,int r)
{
    if(l==r)
    {
    tree[node]=help[l];
    return;
    }
    int av=(l+r)/2;
    build(node*2,l,av);
    build(node*2+1,av+1,r);
    tree[node]=min(tree[node*2],tree[node*2+1]);
}
int query(int node,int l,int r,int lq,int rq)
{
    if(l==lq&&r==rq)
    {
    return tree[node];
    }
    int av=(l+r)/2,mini=1e9;
    if(lq<=av)mini=min(mini,query(node*2,l,av,lq,min(av,rq)));
    if(av<rq)mini=min(mini,query(node*2+1,av+1,r,max(av+1,lq),rq));
    return mini;
}
int main()
{
cin>>n>>q;
for(int i=1;i<=n;i++)cin>>arr[i];
bool zeros=1;
for(int j=1;j<=n;j++)
    if(arr[j])zeros=0;
if(zeros)
{
    cout<<"YES"<<endl;
    for(int j=1;j<=n;j++)cout<<q<<" ";cout<<endl;
    return 0;
}
bool big=0;
for(int j=1;j<=n;j++)
    if(arr[j]==q)big=1;
if(big==0)
{
    bool zero=0;
    for(int j=1;j<=n;j++)
        if(arr[j]==0)
        {
        arr[j]=q;
        zero=1;
        break;
        }
    if(zero==0)
    {
        cout<<"NO"<<endl;
        return 0;
    }
}
for(int i=1;i<=n;i++)
    if(arr[i])
    {
        if(s.size())
        {
            if(arr[i]!=s.top())s.push(arr[i]);
        }
        else s.push(arr[i]);
    }
for(int i=2;i<=n;i++)
    if(arr[i]==0)arr[i]=arr[i-1];
for(int i=n-1;i>=1;i--)
    if(arr[i]==0)arr[i]=arr[i+1];

int SZ=s.size();
for(int j=1;j<=SZ;j++)
{
help[j]=s.top();
s.pop();
if(l[help[j]]==0)l[help[j]]=j;
r[help[j]]=j;
}
//for(int j=1;j<=SZ;j++)cout<<help[j]<<" ";cout<<endl;
build(1,1,SZ);

for(int i=q;i>=1;i--)
    if(l[i]&&r[i])
    if(query(1,1,SZ,l[i],r[i])<i)
    {
    cout<<"NO"<<endl;
    return 0;
    }
cout<<"YES"<<endl;
for(int j=1;j<=n;j++)
    cout<<arr[j]<<" ";cout<<endl;
return 0;
}
#include<bits/stdc++.h>
using namespace std;
const int nmax=1e4+42;
bitset<nmax> seen,idle;
int n;
vector<int> tree[nmax*4];
void update(int node,int l,int r,int lq,int rq,int val)
{
    if(l==lq&&r==rq)
    {
        tree[node].push_back(val);
        return;
    }
    int av=(l+r)/2;
    if(lq<=av)update(node*2,l,av,lq,min(av,rq),val);
    if(av<rq)update(node*2+1,av+1,r,max(lq,av+1),rq,val);
}
void solve(int node,int l,int r,bitset<nmax> now)
{
    for(auto k:tree[node])
        now=now|(now<<k);
    if(l==r)
    {
        seen=seen|now;
        return;
    }
    int av=(l+r)/2;
    solve(node*2,l,av,now);
    solve(node*2+1,av+1,r,now);
}
int main()
{
int q;
cin>>n>>q;
int l,r,x;
for(int i=1;i<=q;i++)
{
    cin>>l>>r>>x;
    update(1,1,n,l,r,x);
}
idle[0]=1;
solve(1,1,n,idle);
vector<int> output={};
for(int i=1;i<=n;i++)
    if(seen[i])output.push_back(i);
cout<<output.size()<<endl;
for(auto k:output)cout<<k<<" ";cout<<endl;
return 0;
}
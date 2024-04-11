#include<bits/stdc++.h>
using namespace std;
const int nmax=1e5+42;
int n,k;
vector<int> tree[4*nmax];
int arr[nmax];
int values[nmax];
map<int, vector<int> > seen;
void build(int node,int l,int r)
{
    if(l==r)
    {
        tree[node].push_back(values[l]);
        return;
    }
    int av=(l+r)/2;

    build(node*2,l,av);
    build(node*2+1,av+1,r);

    tree[node]=tree[node*2];
    for(auto k:tree[node*2+1])tree[node].push_back(k);
    sort(tree[node].begin(),tree[node].end());
}
int query(int node,int l,int r,int lq,int rq,int mx)
{
    if(l==lq&&r==rq)
    {
        int p=lower_bound(tree[node].begin(),tree[node].end(),mx)-tree[node].begin();
        return p;
    }

    int av=(l+r)/2,sum=0;
    if(lq<=av)sum=sum+query(node*2,l,av,lq,min(av,rq),mx);
    if(av<rq)sum=sum+query(node*2+1,av+1,r,max(av+1,lq),rq,mx);
    return sum;
}
int main()
{
scanf("%i%i",&n,&k);
for(int i=1;i<=n;i++)scanf("%i",&arr[i]);

for(int i=1;i<=n;i++)
{
    if(seen[arr[i]].size()>=k)values[i]=seen[arr[i]][seen[arr[i]].size()-k];
    seen[arr[i]].push_back(i);
    //cout<<i<<" -> "<<values[i]<<endl;
}

build(1,1,n);


int q;
scanf("%i",&q);

int last=0,x,y;
for(int i=1;i<=q;i++)
{
    scanf("%i%i",&x,&y);
    int l=((x+last)%n)+1;
    int r=((y+last)%n)+1;
    if(l>r)swap(l,r);
    last=query(1,1,n,l,r,l);
    printf("%i\n",last);
}
return 0;
}
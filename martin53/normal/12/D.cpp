#include<bits/stdc++.h>
using namespace std;
const int nmax=5e5+42;
int n;
struct person
{
    int value[3];
};
person inp[nmax];
pair<int/*value*/,int/*index*/> help[nmax];
void compress(int ind)
{
    for(int i=1;i<=n;i++)help[i]={inp[i].value[ind],i};
    sort(help+1,help+n+1);
    for(int i=1;i<=n;i++)
    {
        int j=i;
        while(help[i].first==help[j].first&&j<=n)j++;
        for(int k=i;k<j;k++)
            inp[help[k].second].value[ind]=i;
        i=j-1;
    }
}
bool cmp(person a,person b)
{
    return a.value[0]>b.value[0];
}
int tree[1<<20];
int query(int node,int l,int r,int lq,int rq)
{
    if(l==lq&&r==rq)return tree[node];
    int av=(l+r)/2,ret=0;
    if(lq<=av)ret=max(ret,query(node*2,l,av,lq,min(av,rq)));
    if(av<rq)ret=max(ret,query(node*2+1,av+1,r,max(av+1,lq),rq));
    return ret;
}
void update(int node,int l,int r,int pos,int val)
{
    if(l==r)
    {
        tree[node]=max(tree[node],val);
        return;
    }
    int av=(l+r)/2;
    if(pos<=av)update(node*2,l,av,pos,val);
    else update(node*2+1,av+1,r,pos,val);
    tree[node]=max(tree[node*2],tree[node*2+1]);
}
int go[nmax];
int main()
{
scanf("%i",&n);
for(int j=0;j<3;j++)
for(int i=1;i<=n;i++)scanf("%i",&inp[i].value[j]);
compress(1);
sort(inp+1,inp+n+1,cmp);

int ans=0;
for(int i=1;i<=n;i++)
{
    int j=i,id=0;
    while(inp[i].value[0]==inp[j].value[0]&&j<=n)j++;
    for(int k=i;k<j;k++)
        if(query(1,1,nmax,inp[k].value[1]+1,nmax)>inp[k].value[2])ans++;
        else
        {
            id++;
            go[id]=k;
        }
    for(int k=1;k<=id;k++)
        update(1,1,nmax,inp[go[k]].value[1],inp[go[k]].value[2]);
    i=j-1;

}
printf("%i\n",ans);
return 0;
}
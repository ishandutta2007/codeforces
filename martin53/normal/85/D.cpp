#include<bits/stdc++.h>
using namespace std;
const int nmax=1e5+42;
struct node
{
int numbers,l=-1,r=-1;
long long sums[5]={0,0,0,0,0};
};
int n;
node tree[1<<21];
int ind=1;
node my_merge(int l,int r)
{
    node ret;
    ret.numbers=0;
    ret.l=l;
    ret.r=r;
    if(l!=-1)
    {
        for(int j=0;j<5;j++)
            ret.sums[j]=tree[l].sums[j];
        ret.numbers=ret.numbers+tree[l].numbers;
    }
    if(r!=-1)
    {
        for(int j=0;j<5;j++)
            ret.sums[(j+ret.numbers)%5]+=tree[r].sums[j];
        ret.numbers=ret.numbers+tree[r].numbers;
    }
    return ret;
}
void update(int node,int l,int r,int pos,int value)
{
    if(l==r)
    {
        tree[node].numbers=tree[node].numbers+value;
        tree[node].sums[0]=tree[node].sums[0]+value*pos;
        return;
    }
    int av=(l+r)/2;
    if(pos<=av)
    {
        if(tree[node].l==-1)
        {
            ind++;
            tree[node].l=ind;
        }
        update(tree[node].l,l,av,pos,value);
    }
    else
    {
        if(tree[node].r==-1)
        {
            ind++;
            tree[node].r=ind;
        }
        update(tree[node].r,av+1,r,pos,value);
    }
    tree[node]=my_merge(tree[node].l,tree[node].r);
    /*
    cout<<l<<" "<<r<<" "<<tree[node].l<<" "<<tree[node].r<<" -> ";cout<<tree[node].numbers<<" : ";
    for(int j=0;j<5;j++)cout<<tree[node].sums[j]<<" ";cout<<endl;
    */
}
int main()
{
scanf("%i",&n);
for(int i=1;i<=n;i++)
{
    char inp[3];
    for(int j=0;j<3;j++)
    {
        scanf("%c",&inp[j]);
        if('a'>inp[j]||inp[j]>'z')j--;
    }
    int x;
    if(inp[0]=='a')
    {
        scanf("%i",&x);
        update(1,1,1e9,x,1);
    }
    if(inp[0]=='d')
    {
        scanf("%i",&x);
        update(1,1,1e9,x,-1);
    }
    if(inp[0]=='s')printf("%I64d \n",tree[1].sums[2]);
}
return 0;
}
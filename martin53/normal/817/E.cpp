#include<bits/stdc++.h>
using namespace std;
const int MX=29;
struct node
{
int l,r;
int sum;
};
vector<node> tree;
void add_node()
{
    node my;
    my.l=-1;
    my.r=-1;
    my.sum=0;
    tree.push_back(my);
}
int ask(int node)
{
    if(node==-1)return 0;
    return tree[node].sum;
}
void update(int bit,int node,int value,int add)
{
    if(bit<0)
    {
        tree[node].sum+=add;
        return;
    }

    if(tree[node].l==-1)
    {
    tree[node].l=tree.size();
    add_node();
    }

    if(tree[node].r==-1)
    {
    tree[node].r=tree.size();
    add_node();
    }

    if(((1<<bit)&value)==0)update(bit-1,tree[node].l,value,add);
    else update(bit-1,tree[node].r,value,add);
    tree[node].sum=ask(tree[node].l)+ask(tree[node].r);
}
int query(int bit,int node,int p,int l)
{
    //cout<<bit<<" "<<node<<" "<<p<<" "<<l<<endl;
    if(bit==-1||node==-1)return 0;
    int sum=0;
    int p_=((1<<bit)&p)>>bit,l_=((1<<bit)&l)>>bit;
    //add 0
    if(p_<l_)sum=sum+ask(tree[node].l);
    if(p_==l_)sum=sum+query(bit-1,tree[node].l,p,l);
    //add 1
    if((1^p_)<l_)sum=sum+ask(tree[node].r);
    if((1^p_)==l_)sum=sum+query(bit-1,tree[node].r,p,l);
    return sum;
}
int main()
{
add_node();
int q;
int type,p,l;
scanf("%i",&q);
for(int i=1;i<=q;i++)
{
    scanf("%i%i",&type,&p);
    if(type==1)update(MX,0,p,1);
    if(type==2)update(MX,0,p,-1);
    if(type==3)
    {
        scanf("%i",&l);
        printf("%i\n",query(MX,0,p,l));
    }
}
return 0;
}
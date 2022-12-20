#include<bits/stdc++.h>
using namespace std;
const int nmax=1e5+42;
struct tree
{
    int l,r;
    int sum;
};
vector<tree> all[nmax];
void make_node(int id)
{
    tree idle;
    idle.l=-1;
    idle.r=-1;
    idle.sum=0;
    all[id].push_back(idle);
}
void add_node(int id,int node,int bit,int value)
{
    if(bit<0)
    {
        all[id][node].sum++;
        return;
    }
    if(all[id][node].l==-1){all[id][node].l=all[id].size();make_node(id);}
    if(all[id][node].r==-1){all[id][node].r=all[id].size();make_node(id);}
    if((value&(1<<bit))==0)add_node(id,all[id][node].l,bit-1,value);
    else add_node(id,all[id][node].r,bit-1,value);
    all[id][node].sum=all[id][all[id][node].l].sum+all[id][all[id][node].r].sum;
}
int my_search(int id,int node,int bit,int mx,int value)
{
    //cout<<id<<" "<<node<<" "<<bit<<" "<<mx<<" "<<value<<" "<<all[id][node].sum<<endl;
    if(all[id][node].sum==0)return -1;
    if(bit<0)return 0;
    if(all[id][node].l==-1){all[id][node].l=all[id].size();make_node(id);}
    if(all[id][node].r==-1){all[id][node].r=all[id].size();make_node(id);}
    int bt=(value&(1<<bit))>>bit,v;
    //forced left
    if((1<<bit)>mx)return my_search(id,all[id][node].l,bit-1,mx,value);
    //bt=0
    if(bt==0)
    {
        //try going right
        v=my_search(id,all[id][node].r,bit-1,mx-(1<<bit),value);
        if(v!=-1)return (1<<bit)+v;
        //go left
        v=my_search(id,all[id][node].l,bit-1,mx,value);
        if(v!=-1)return v;
        return -1;
    }
    //try going left
    v=my_search(id,all[id][node].l,bit-1,mx,value);
    if(v!=-1)return v;
    //go right
    v=my_search(id,all[id][node].r,bit-1,mx-(1<<bit),value);
    if(v!=-1)return (1<<bit)+v;
    return -1;
}
bool seen[nmax];
int main()
{
for(int i=1;i<nmax;i++)
    make_node(i);
int q;
cin>>q;
int type,u,x,k,s;
for(int i=1;i<=q;i++)
{
    cin>>type;
    if(type==1)
    {
        cin>>u;
        if(seen[u])continue;
        for(int j=1;j*j<=u;j++)
            if(u%j==0)
            {
                add_node(j,0,19,u);
                if(j*j!=u)add_node(u/j,0,19,u);
            }
        /*
        for(int j=2;u*j<nmax;j++)
            add_node(j*u,0,19,u);
        */
    }
    else
    {
        cin>>x>>k>>s;
        if(x%k||x>=s)
        {
            cout<<-1<<"\n";
            continue;
        }
        cout<<my_search(k,0,19,s-x,x)<<"\n";
    }
}
return 0;
}
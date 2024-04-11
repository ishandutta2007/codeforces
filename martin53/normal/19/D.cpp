#include<bits/stdc++.h>
using namespace std;
const int nmax=2e5+42;
int n;
struct quer
{
    string type;
    int x,y;
};
quer inp[nmax];

map<int,int> original_x={},original_y={};

pair<int,int> points[nmax];
map< pair<int,int>,int> where;

struct info
{
    long long sum,maxi;
};
info tree[nmax*4];
info my_merge(info a,info b)
{
    info ret;
    ret.sum=a.sum+b.sum;
    ret.maxi=max(a.maxi,b.maxi);
    return ret;
}
void update(int node,int l,int r,int pos,int value)
{
    if(l==r)
    {
        //cout<<"updated "<<l<<" "<<pos<<" with "<<value<<endl;
        tree[node].sum+=value;
        if(tree[node].sum==0)tree[node].maxi=0;
        else tree[node].maxi=points[l].second;
        //cout<<node<<" -> "<<tree[node].maxi<<endl;
        return;
    }
    int av=(l+r)/2;
    if(pos<=av)update(node*2,l,av,pos,value);
    else update(node*2+1,av+1,r,pos,value);
    tree[node]=my_merge(tree[node*2],tree[node*2+1]);
}
bool solved;
void query(int node,int l,int r,int lq,int rq,int at_least)
{
    if(solved)return;

    if(tree[node].sum==0||tree[node].maxi<at_least)return;

    if(r<lq)return;

    if(l==r)
    {
        //cout<<"compressed answer: "<<points[l].first<<" "<<points[l].second<<endl;
        cout<<original_x[points[l].first]<<" "<<original_y[points[l].second]<<"\n";
        solved=1;
        return;
    }

    int av=(l+r)/2;

    query(node*2,l,av,lq,rq,at_least);
    query(node*2+1,av+1,r,lq,rq,at_least);
}

void compress()
{
    set<int> work={};
    for(int i=1;i<=n;i++)
        work.insert(inp[i].x);

    int pos=0;
    map<int,int> seen={};
    for(auto k:work)
    {
        pos++;
        seen[k]=pos;
        original_x[pos]=k;
    }

    for(int i=1;i<=n;i++)
        inp[i].x=seen[inp[i].x];


    work={};
    for(int i=1;i<=n;i++)
        work.insert(inp[i].y);

    pos=0;
    seen={};
    for(auto k:work)
    {
        pos++;
        seen[k]=pos;
        original_y[pos]=k;
    }

    for(int i=1;i<=n;i++)
        inp[i].y=seen[inp[i].y];
}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie();
cout.tie();

cin>>n;
for(int i=1;i<=n;i++)
{
    cin>>inp[i].type>>inp[i].x>>inp[i].y;
    if(inp[i].type=="find")inp[i].x++,inp[i].y++;
}

compress();
/*
cout<<"compressed: "<<endl;
for(int i=1;i<=n;i++)
{
    cout<<inp[i].type<<" "<<inp[i].x<<" "<<inp[i].y<<endl;
}
*/
for(int i=1;i<=n;i++)
    points[i]={inp[i].x,inp[i].y};

sort(points+1,points+n+1);

for(int i=1;i<=n;i++)
    where[points[i]]=i;

for(int i=1;i<=n;i++)
{
    if(inp[i].type=="add")update(1,1,n,where[{inp[i].x,inp[i].y}],1);
    if(inp[i].type=="remove")update(1,1,n,where[{inp[i].x,inp[i].y}],-1);
    if(inp[i].type=="find")
    {
        solved=0;

        int ok=n+1,not_ok=0;

        while(ok-not_ok>1)
        {
            int av=(ok+not_ok)/2;
            if(points[av].first>=inp[i].x)ok=av;
            else not_ok=av;
        }
        if(ok<=n)query(1,1,n,ok,n,inp[i].y);
        if(solved==0)cout<<-1<<"\n";
    }
}
return 0;
}
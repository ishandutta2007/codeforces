#include<bits/stdc++.h>
using namespace std;

const int nmax=2e5+42;

int n,q;

int inp[nmax];

bool can[nmax];

set<int> active[3];

int type(char c)
{
    if(c=='R')return 0;
    if(c=='P')return 1;
    return 2;
}

int ask_first(int colour)
{
    colour=colour%3;

    return *active[colour].begin();
}
int ask_last(int colour)
{
    colour=colour%3;

    set<int>::iterator it=active[colour].end();
    it--;

    return *it;
}


int fenwick[3][nmax];

int query(int colour,int pos)
{
    int ret=0;

    while(pos)
    {
        ret+=fenwick[colour][pos];
        pos=pos-(pos&(-pos));
    }
    return ret;
}
void update(int colour,int pos,int val)
{
    while(pos<=n)
    {
        fenwick[colour][pos]+=val;
        pos=pos+(pos&(-pos));
    }
}
int up_to(int colour,int pos)
{
    return query(colour,pos);
}
int cnt(int colour,pair<int,int> into)
{
    if(into.first>into.second)return 0;

    return up_to(colour,into.second)-up_to(colour,into.first-1);
}
int cnt_wrong(int colour)
{
    pair<int,int> lhs={ask_first(colour+1),ask_first(colour+2)-1};

    pair<int,int> rhs={ask_last(colour+2),ask_last(colour+1)-1};

    return cnt(colour,lhs)+cnt(colour,rhs)-cnt(colour,{max(lhs.first,rhs.first),min(lhs.second,rhs.second)});
}

int query()
{
    int in=(active[0].size()>0)+(active[1].size()>0)+(active[2].size()>0);

    if(in==1)return n;

    for(int i=0;i<3;i++)
        if(active[i].size()&&active[(i+1)%3].size()&&active[(i+2)%3].size()==0)return active[(i+1)%3].size();

    //all colours are active
    return n-cnt_wrong(0)-cnt_wrong(1)-cnt_wrong(2);
}

int main()
{
    cin>>n>>q;

    for(int i=1;i<=n;i++)
    {
        char c;
        cin>>c;

        inp[i]=type(c);

        active[inp[i]].insert(i);
        update(inp[i],i,1);
    }

    cout<<query()<<"\n";

    for(int i=1;i<=q;i++)
    {
        int pos;
        char c;

        cin>>pos>>c;

        update(inp[pos],pos,-1);

        active[inp[pos]].erase(pos);

        inp[pos]=type(c);

        active[inp[pos]].insert(pos);

        update(inp[pos],pos,1);

        cout<<query()<<"\n";
    }
    return 0;
}
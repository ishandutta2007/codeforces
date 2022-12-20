#include<bits/stdc++.h>
using namespace std;

const int nmax=5000;

int n,outp[nmax];

map< pair<int,int>,int> mem;

mt19937 rng(42);

int order[nmax];

int ask(int l,int r)
{
    if(l>r)swap(l,r);

    if(mem.count({l,r}))return mem[{l,r}];

    cout<<"? "<<l<<" "<<r<<endl;
    cout.flush();

    int ret;
    cin>>ret;
    mem[{l,r}]=ret;
    return ret;
}

void gen(int id)
{
    outp[id]=0;

    for(int i=1;i<=n;i++)
        if(i!=id)outp[i]=ask(i,id);

    cout<<"!";
    for(int i=1;i<=n;i++)cout<<" "<<outp[i];
    cout<<endl;

    cout.flush();
    exit(0);
}
int main()
{
    cin>>n;

    for(int i=1;i<=n;i++)order[i]=i;
    shuffle(order+1,order+n+1,rng);

    int possible[2]={order[1],order[2]};

    for(int i=3;i<=n;i++)
    {
        if(ask(possible[0],possible[1])<ask(possible[1],order[i]))continue;

        if(ask(possible[0],possible[1])>ask(possible[1],order[i]))
        {
            possible[0]=order[i];
            continue;
        }

        possible[1]=order[i];
    }

    for(int i=1;i<=n;i++)
    {
        if(order[i]==possible[0]||order[i]==possible[1])continue;

        if(ask(possible[0],order[i])<ask(possible[1],order[i]))gen(possible[0]);
        if(ask(possible[0],order[i])>ask(possible[1],order[i]))gen(possible[1]);
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

const int nmax=2e5+42;

int n,q,inp[nmax];

long long fenwick[nmax];

set<int> non_zero;

void update(int pos,int val)
{
    while(pos<=n)
    {
        fenwick[pos]+=val;
        pos=pos+(pos&(-pos));
    }
}
long long query(int pos)
{
    //cout<<"query "<<pos<<" -> ";

    long long ret=0;

    while(pos)
    {
        ret+=fenwick[pos];
        pos=pos-(pos&(-pos));
    }

    //cout<<ret<<endl;

    return ret;
}

bool check(int pos)
{
    return inp[pos]==query(pos-1);
}

int around(int pos)
{
    set<int>::iterator it=non_zero.upper_bound(pos);

    if(it!=non_zero.end())
    {
        if(check(*it))return *it;
    }

    if(it!=non_zero.begin())
    {
        it--;
        if(check(*it))return *it;
    }
    return 0;
}
int solve()
{
    if(inp[1]==0)return 1;

    for(int bit=0;bit<=30;bit++)
    {
        long long cur=1LL<<bit;

        int ok=0,not_ok=n+1;

        while(not_ok-ok>1)
        {
            int av=(ok+not_ok)/2;

            //cout<<ok<<" "<<not_ok<<" "<<av<<endl;

            if(query(av)<=cur)ok=av;
            else not_ok=av;
        }

        //cout<<bit<<" -> "<<cur<<" "<<ok<<endl;

        int mem=around(ok);

        if(mem)return mem;
    }

    return -1;
}

int main()
{
    scanf("%i%i",&n,&q);
    for(int i=1;i<=n;i++)
    {
        scanf("%i",&inp[i]);
        if(inp[i])non_zero.insert(i);
    }
    for(int i=1;i<=n;i++)update(i,inp[i]);

    for(int i=1;i<=q;i++)
    {
        int pos,val;
        scanf("%i%i",&pos,&val);

        update(pos,-inp[pos]);
        non_zero.erase(pos);

        inp[pos]=val;
        update(pos,inp[pos]);
        if(inp[pos])non_zero.insert(pos);

        printf("%i\n",solve());
    }
    return 0;
}
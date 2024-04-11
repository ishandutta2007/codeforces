#include<bits/stdc++.h>
using namespace std;

set<long long> seen;

bool ask(long long cur)
{
    seen.insert(cur);

    cout<<"? "<<cur<<endl;

    int ret;
    cin>>ret;
    return ret;
}
void print(long long C)
{
    cout<<"= "<<C<<endl;

}

long long n;

bool test(long long &on,long long &av, long long &ok,long long &not_ok)
{
    if(1>av||av>n)return 0;

    if(on+av<=n&&seen.count(on+av)==0)
    {
        long long help=on+av;

        on=help;

        if(ask(help)==0)ok=max(ok,av);
        else not_ok=min(not_ok,av);
        return 1;
    }

    else if(on-av>=1&&seen.count(on-av)==0)
    {
        long long help=on-av;

        on=help;

        if(ask(help)==0)ok=max(ok,av);
        else not_ok=min(not_ok,av);
        return 1;
    }
    return 0;
}


void solve()
{
    seen={};

    cin>>n;

    if(n==1)
    {
        print(1);
        return;
    }

    vector<long long> would_be={};

    long long ok=0,not_ok=n;

    while(not_ok-ok>1)
    {
        long long av=(ok+not_ok)/2;

        would_be.push_back(av);

        ok=av;
    }

    reverse(would_be.begin(),would_be.end());

    vector<long long> order={n};

    long long cur=n;
    int mult=-1;

    for(auto k:would_be)
    {
        cur+=mult*k;

        order.push_back(cur);

        mult=-mult;
    }

    reverse(order.begin(),order.end());

    //for(auto k:order)cout<<k<<" ";cout<<endl;

    ok=0,not_ok=n+1;

    ask(order[0]);

    int wrong=-1;

    long long on;

    for(int i=1;i<order.size();i++)
    {
        if(ask(order[i])==0)ok=abs(order[i]-order[i-1]);
        else
        {
            not_ok=abs(order[i]-order[i-1]);
            wrong=i;

            on=order[i];

            break;
        }
    }

    if(wrong==-1)
    {
        print(n);
        return;
    }

    while(not_ok-ok>1)
    {
        long long av=(ok+not_ok)/2;

        if(test(on,av,ok,not_ok)==0)
        {
            for(int diff=0;true;diff++)
            {
                long long av_now=av+diff;

                if(test(on,av_now,ok,not_ok))break;

                av_now=av-diff;

                if(test(on,av_now,ok,not_ok))break;
            }
        }
    }

    print(ok+1);
}

int main()
{
    int t;
    cin>>t;

    while(t)
    {
        t--;
        solve();
    }
    return 0;
}
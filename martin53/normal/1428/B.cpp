#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;

int n;

char inp[nmax];

void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)cin>>inp[i];

    bool full=0;

    bool lll=1,rrr=1;

    for(int i=1;i<=n;i++)
    {
        if(inp[i]=='<')lll=0;
        if(inp[i]=='>')rrr=0;
    }

    int outp=0;

    for(int i=1;i<=n;i++)
    {
        char le=inp[i],ri=inp[i-1==0?n:i-1];

        if(le=='-'||ri=='-')outp++;
        else if(le=='>'&&ri=='<')continue;
        else if(le=='<'&&ri=='>')continue;
        else if(lll||rrr)outp++;
    }


    cout<<outp<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();

    int t;
    cin>>t;
    while(t)
    {
        solve();
        t--;
    }
    return 0;
}
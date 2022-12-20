#include<bits/stdc++.h>
using namespace std;

const int MX=(1<<12),other=1e6;

int seen[MX],help[MX];

int actual[other];

int outp;

string inp;

void go(int pos,int val)
{
    if(pos==inp.size())
    {
        outp+=actual[val];
        return;
    }

    if(inp[pos]=='A')
    {
        go(pos+1,val*3+0);
        go(pos+1,val*3+1);
    }
    else if(inp[pos]=='a')
    {
        go(pos+1,val*3+2);
    }

    if(inp[pos]=='X')
    {
        go(pos+1,val*3+0);
        go(pos+1,val*3+2);
    }
    else if(inp[pos]=='x')
    {
        go(pos+1,val*3+1);
    }

    if(inp[pos]=='o')
    {
        go(pos+1,val*3+1);
        go(pos+1,val*3+2);
    }
    else if(inp[pos]=='O')
    {
        go(pos+1,val*3+0);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();

    int w,n,m;

    cin>>w>>n>>m;

    for(int i=1;i<=n;i++)
    {
        int val;
        cin>>val;
        seen[val]++;
    }

    for(int i=0;i<(1<<w);i++)
    {
        int cur=0,mem_i=i;

        int mult=1;

        for(int t=0;t<w;t++)
        {
            cur=cur+(mem_i%2)*mult;

            mem_i=mem_i/2;
            mult=mult*3;
        }

        help[i]=cur;
    }

    for(int i=0;i<(1<<w);i++)
        for(int j=0;j<(1<<w);j++)
        {
            actual[help[i]+help[j]]+=seen[i]*seen[j];
        }

    for(int i=1;i<=m;i++)
    {
        cin>>inp;

        outp=0;

        go(0,0);

        cout<<outp<<"\n";
    }
    return 0;
}
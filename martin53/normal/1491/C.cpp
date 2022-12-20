#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;
int n,inp[nmax];

int jump[nmax];

void solve()
{
    scanf("%i",&n);
    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    /*
    n=5e3;
    for(int i=1;i<=n;i++)inp[i]=(i<=n/2?n/2:1);
    */
    for(int i=1;i<=n;i++)jump[i]=i;
    jump[n+1]=n+1;

    for(int i=n;i>=1;i--)
        if(inp[i]==1)jump[i]=jump[i+1];

    long long outp=0;

    int start=1;

    while(start<=n)
    {
        //for(int i=1;i<=n;i++)cout<<jump[i]<<" ";cout<<endl;

        //cout<<"start= "<<start<<" "<<inp[start]<<endl;

        if(inp[start]==1)
        {
            start++;
            continue;
        }

        if(inp[start]+start>n+1)
        {
            int skip=inp[start]+start-n-1;
            outp+=skip;
            inp[start]=inp[start]-skip;
            continue;
        }

        int cur=start;

        outp++;

        while(cur<=n)
        {
            if(inp[cur]==1)
            {
                cur=jump[cur];
                continue;
            }

            int go=cur+inp[cur];

            if(inp[cur]>1)
            {
                inp[cur]--;
                if(inp[cur]==1)
                {
                    jump[cur]=jump[cur+1];

                    for(int j=cur;j>=1&&inp[j]==1;j--)
                        jump[j]=jump[j+1];
                }
            }
            cur=go;
        }
    }

    printf("%lld\n",outp);
}

int main()
{
    int t;

    scanf("%i",&t);
    //t=1;

    while(t)
    {
        t--;
        solve();
    }

    return 0;
}
#include<bits/stdc++.h>
using namespace std;

const int nmax=1e5+42;

int n,k,inp[nmax];

int l[nmax],mini[nmax];

void my_move(int id)
{
    int c=inp[id]/l[id];

    l[id]=inp[id]/c+1;
}

int solve()
{
    scanf("%i%i",&n,&k);

    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    if(inp[n]<k)return 0;

    for(int i=0;i<=inp[n];i++)
        mini[i]=0;

    for(int i=1;i<=n;i++)
    {
        mini[0]=max(mini[0],inp[i]/k);

        //cout<<"i= "<<i<<endl;

        l[i]=1;

        while(l[i]<=min(k,inp[i]))
        {
            int LHS=inp[i]/l[i];

            my_move(i);

            int RHS=inp[i]/l[i]+1;

            mini[RHS]=max(mini[RHS],LHS);

            //cout<<"update "<<RHS<<" "<<LHS<<" "<<l[i]<<endl;
        }
    }

    for(int i=0;i<=inp[1];i++)
        mini[i]=max(mini[i],mini[i-1]);

    int outp=inp[n];

    for(int i=inp[1]/k;i<=inp[1];i++)
        outp=min(outp,mini[i]-i);

    return outp;
}

int main()
{
    int t;
    scanf("%i",&t);

    while(t)
    {
        t--;

        printf("%i\n",solve());
    }

    return 0;
}
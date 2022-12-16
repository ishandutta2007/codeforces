#include <bits/stdc++.h>
using namespace std;
const int nmax=1e5+42;
int n;

int sz[3],inp[3][nmax];

long long eval(long long x,long long y,long long z)
{
     return (x-y)*(x-y)+(y-z)*(y-z)+(z-x)*(z-x);
}

int prior[3];
long long solve()
{
    scanf("%i%i%i",&sz[0],&sz[1],&sz[2]);

    for(int id=0;id<3;id++)
    {
        for(int j=1;j<=sz[id];j++)scanf("%i",&inp[id][j]);

        sort(inp[id]+1,inp[id]+sz[id]+1);
    }

    for(int i=0;i<3;i++)prior[i]=i;

    long long output=3e18;
    do
    {
        int most=prior[0];
        int sec=prior[1];
        int least=prior[2];

        //cout<<most<<" "<<sec<<" "<<least<<endl;

        for(int i=1;i<=sz[most];i++)
        {
            int start=inp[most][i];

            int largest=lower_bound(inp[least]+1,inp[least]+sz[least]+1,start)-inp[least];
            if(largest>sz[least])continue;

            largest=inp[least][largest];

            int mid=lower_bound(inp[sec]+1,inp[sec]+sz[sec]+1,(start+largest)/2)-inp[sec];

            if(1<=mid&&mid<=sz[sec])output=min(output,eval(start,largest,inp[sec][mid]));

            mid--;

            if(1<=mid&&mid<=sz[sec])output=min(output,eval(start,largest,inp[sec][mid]));
        }
    }
    while(next_permutation(prior,prior+3));
    return output;
}
int main()
{
    int t;
    scanf("%i",&t);
    for(int i=1;i<=t;i++)
        printf("%lld\n",solve());
    return 0;
}
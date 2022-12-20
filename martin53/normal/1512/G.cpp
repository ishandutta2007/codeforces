#include<bits/stdc++.h>
using namespace std;

const int nmax=1e7+42;

int sum[nmax],outp[nmax];

int main()
{
    memset(outp,-1,sizeof(outp));

    for(int i=1;i<nmax;i++)
        for(int j=i;j<nmax;j=j+i)
            sum[j]+=i;

    for(int i=1;i<nmax;i++)
        if(sum[i]<nmax)
        {
            if(outp[sum[i]]==-1)outp[sum[i]]=i;
        }

    int t;
    scanf("%i",&t);

    while(t)
    {
        t--;

        int val;
        scanf("%i",&val);

        printf("%i\n",outp[val]);
    }

    return 0;
}
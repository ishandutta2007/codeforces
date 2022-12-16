#include<bits/stdc++.h>
using namespace std;

const int nmax=5e5+42;
int n,inp[nmax];

int help[nmax],pref[nmax],suff[nmax];

int solve()
{
    scanf("%i",&n);

    for(int i=1;i<=2*n;i++)help[i]=-1;

    for(int i=1;i<=n;i++)
    {
        scanf("%i",&inp[i]);
        help[inp[i]]=1;
    }

    pref[0]=0;
    for(int i=1;i<=2*n;i++)pref[i]=pref[i-1]+help[i];

    suff[2*n+1]=0;
    for(int j=2*n;j>=1;j--)suff[j]=suff[j+1]+help[j];

    int MX_pref=0,MX_suff=0;
    for(int i=1;i<=2*n;i++)
    {
        MX_pref=max(MX_pref,pref[i]);
        MX_suff=max(MX_suff,suff[i]);
    }

    return n+1-MX_pref-MX_suff;
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
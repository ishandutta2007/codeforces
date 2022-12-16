#include<bits/stdc++.h>
using namespace std;

const int nmax=2e5+42,mod=998244353;

int n,k;

int dp_total[nmax],dp_current[nmax];
int pref[nmax];

int main()
{
    scanf("%i%i",&n,&k);

    dp_total[0]=1;
    dp_current[0]=1;

    bool go=1;

    for(int dvd=k;go;dvd++)
    {
        go=0;

        for(int i=0;i<=n;i++)
        {
            pref[i]=dp_current[i];

            if(i>=dvd)pref[i]=(pref[i]+pref[i-dvd])%mod;
        }

        for(int i=0;i<=n;i++)
        {
            dp_current[i]=(pref[i]-dp_current[i]+mod)%mod;
        }

        for(int i=0;i<=n;i++)
            if(dp_current[i])
            {
                go=1;

                dp_total[i]=(dp_current[i]+dp_total[i])%mod;
            }

        //cout<<dvd<<" -> ";for(int j=1;j<=n;j++)cout<<dp_current[j]<<" ";cout<<endl;
    }

    for(int i=1;i<=n;i++)
        printf("%i ",dp_total[i]);
    printf("\n");

    return 0;
}
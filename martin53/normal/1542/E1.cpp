#include<bits/stdc++.h>
using namespace std;

const int nmax=5e2+42;

int mod;

int dp[nmax][nmax*nmax/2];

int pref[nmax];

int pref_dp[nmax*nmax/2];

int rec(int n)
{
    if(n==1)return 0;

    //p[1]=q[1]
    long long ret=rec(n-1);
    ret=ret*n%mod;

    long long add=0;

    for(int i=1;i<=n;i++)
        pref[i]=n*(n-1)/2-(n-i)*(n-i+1)/2;

    /*
    for(int i=1;i<=n;i++)
        cout<<pref[i]<<" ";cout<<endl;
    */

    //p[1]<q[1]
    int SZ=1+(n-1)*(n-2)/2;

    pref_dp[0]=dp[n-1][0];

    for(int i=1;i<=SZ;i++)
        pref_dp[i]=(pref_dp[i-1]+dp[n-1][i])%mod;

    for(int i=0;i<=SZ;i++)
    {
        if(0<=i-n)add=(add+1LL*dp[n-1][i]*pref_dp[i-n]%mod*pref[n])%mod;

        for(int j=max(i-n+1,0);j<i;j++)
            add=(add+1LL*dp[n-1][i]*dp[n-1][j]%mod*pref[i-j])%mod;

        //cout<<"i= "<<i<<" add= "<<add<<endl;
    }

    //cout<<"n= "<<n<<" ret= "<<ret<<" add= "<<add<<endl;

    return (ret+add)%mod;
}

int main()
{
    int n;

    scanf("%i%i",&n,&mod);

    for(int pos=1;pos<=n;pos++)
    {
        dp[pos][0]=1;

        for(int inv=1;inv<=pos*(pos-1)/2;inv++)
        {
            long long cur=dp[pos][inv-1];

            cur=cur+dp[pos-1][inv];

            if(inv-pos>=0)cur=cur-dp[pos-1][inv-pos];

            cur=(cur+mod)%mod;

            dp[pos][inv]=cur;
        }

        /*
        for(int i=0;i<=pos*(pos-1)/2;i++)cout<<pos<<" "<<i<<" -> "<<dp[pos][i]<<endl;
        cout<<"---"<<endl;
        */
    }

    printf("%i\n",rec(n));

    return 0;
}
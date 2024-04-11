#include<bits/stdc++.h>
using namespace std;
long long int n,m,k,i,j;
long long int mod=998244353;
long long int C[2005][2005];
long long int F[2005];
int main()
{
    for(i=0;i<=2003;i++)
    {
        C[i][0]=1;
        C[i][i]=1;
    }
    for(i=2;i<=2003;i++)
    {
        for(j=1;j<=i-1;j++)
        {
            C[i][j]=C[i-1][j]+C[i-1][j-1];
            C[i][j]=C[i][j]%mod;
        }
    }
    //cout<<C[2][0];
    cin>>n>>m>>k;
    F[1]=m;
    for(i=2;i<=2003;i++)
    {
        F[i]=(m-1)*F[i-1];
        F[i]=F[i]%mod;
    }
    cout<<(C[n-1][k]*F[k+1])%mod;
    return 0;
}
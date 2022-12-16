#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42,mod=998244353;

int n;
int inp[nmax];

long long fact[nmax],inv[nmax];

int solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        char c;
        cin>>c;

        inp[i]=c-'0';
    }

    int cnt_0=0,cnt_11=0;

    for(int i=1;i<=n;i++)
        if(inp[i]==0)cnt_0++;

    for(int i=1;i<n;i++)
        if(inp[i]==1&&inp[i+1]==1)cnt_11++,i++;

    //cout<<"cnt_0= "<<cnt_0<<" cnt_11= "<<cnt_11<<endl;

    return fact[cnt_0+cnt_11]*inv[cnt_0]%mod*inv[cnt_11]%mod;
}



int main()
{
    fact[0]=1;
    fact[1]=1;

    for(int i=2;i<nmax;i++)
        fact[i]=fact[i-1]*i%mod;

    inv[0]=1;
    inv[1]=1;

    for(int i=2;i<nmax;i++)
        inv[i]=(mod-mod/i)*inv[mod%i]%mod;

    for(int i=2;i<nmax;i++)
        inv[i]=inv[i-1]*inv[i]%mod;

    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    int t;
    cin>>t;

    while(t)
    {
        t--;

        cout<<solve()<<"\n";
    }

    return 0;
}
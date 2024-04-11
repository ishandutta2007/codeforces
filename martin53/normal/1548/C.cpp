#include<bits/stdc++.h>
using namespace std;

const int nmax=3e6+42,mod=1e9+7;

int n;

long long fact[nmax],inv[nmax];

vector<long long> outp;

long long C(int p,int q)
{
    return fact[p]*inv[q]%mod*inv[p-q]%mod;
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

    for(int i=1;i<nmax;i++)
        inv[i]=inv[i-1]*inv[i]%mod;

    int n;
    scanf("%i",&n);

    for(int i=0;i<=3*n+3;i++)
        outp.push_back(C(3*n+3,i));
    outp[0]--;

    outp.erase(outp.begin(),outp.begin()+1);

    for(int i=outp.size()-1;i>=2;i--)
    {
        outp[i-1]=(outp[i-1]-3*outp[i]+3LL*mod)%mod;
        outp[i-2]=(outp[i-2]-3*outp[i]+3LL*mod)%mod;
    }

    outp.erase(outp.begin(),outp.begin()+2);

    int q;
    scanf("%i",&q);

    for(int i=1;i<=q;i++)
    {
        int x;

        scanf("%i",&x);

        printf("%i\n",outp[x]);
    }


    return 0;
}
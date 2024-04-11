#include<bits/stdc++.h>
using namespace std;

const int nmax=4e5+42,mod=998244353;

int n,q;

char inp[nmax];

int even_q,odd_q,even_b,odd_b;

long long fact[nmax];

long long inv[nmax];

long long C(int n_,int k_)
{
    //cout<<"C "<<n_<<" "<<k_<<endl;

    if(k_<0||n_<k_)return 0;

    return fact[n_]*inv[k_]%mod*inv[n_-k_]%mod;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    cin>>n>>q;

    for(int i=1;i<=n;i++)
    {
        cin>>inp[i];

        if(inp[i]=='?')
        {
            if(i%2==0)even_q++;
            else odd_q++;
        }

        if(inp[i]=='b')
        {
            if(i%2==0)even_b++;
            else odd_b++;
        }
    }

    fact[0]=1;
    for(int i=1;i<nmax;i++)
        fact[i]=1LL*fact[i-1]*i%mod;

    inv[0]=1;
    inv[1]=1;
    for(int i=2;i<nmax;i++)
        inv[i]=1LL*(mod-mod/i)*inv[mod%i]%mod;

    //cout<<inv[2]<<" "<<inv[3]<<endl;

    for(int i=1;i<nmax;i++)
        inv[i]=inv[i-1]*inv[i]%mod;

    long long outp=0;

    int c=even_q-odd_q;

    for(int i=0;i<=even_q+odd_q;i++)
        {
            long long cur=abs(even_b-odd_b+even_q-i);

            //cout<<i<<" "<<cur<<endl;

            if(cur%2)continue;

            cur=cur/2;

            cur=cur*C(even_q+odd_q,i)%mod;

            //cout<<"cur= "<<cur<<endl;

            outp=(outp+cur)%mod;
        }

    for(int i=1;i<=even_q+odd_q-1;i++)
        outp=outp*inv[2]%mod;

    printf("%lld\n",outp);
    return 0;
}
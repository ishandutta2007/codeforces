#include<bits/stdc++.h>
using namespace std;

const int nmax=1e5+42,mod=1e9+7;

int n,inp[nmax];

vector<int> seen[nmax],dvd[nmax];

int phi[nmax];

int cnt[nmax];

long long sum_gcd(vector<int> cur)
{
    long long alone=0;
    for(auto w:cur)alone=(alone+w)%mod;

    long long together=0;

    for(auto p:cur)
    {
        for(auto q:dvd[p])
        {
            together=(together+1LL*phi[q]*cnt[q])%mod;
            cnt[q]++;
        }
    }

    for(auto p:cur)
    {
        for(auto q:dvd[p])
            cnt[q]=0;
    }

    long long ret=(alone+together*2)%mod;

    //cout<<"ret= "<<ret<<" : ";for(auto w:cur)cout<<w<<" ";cout<<endl;

    return ret;
}

int main()
{
    scanf("%i",&n);
    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    for(int i=1;i<nmax;i++)phi[i]=i;
    for(int i=2;i<nmax;i++)
        if(phi[i]==i)
        {
            for(int j=i;j<nmax;j=j+i)
                phi[j]=phi[j]/i*(i-1);
        }

    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j=j+i)
            seen[i].push_back(inp[j]);
    }

    for(int i=1;i<nmax;i++)
    {
        for(int j=i;j<nmax;j=j+i)
            dvd[j].push_back(i);
    }

    long long outp=0;
    for(int i=1;i<=n;i++)
        outp=(outp+1LL*phi[i]*sum_gcd(seen[i]))%mod;

    printf("%lld\n",outp);

    return 0;
}
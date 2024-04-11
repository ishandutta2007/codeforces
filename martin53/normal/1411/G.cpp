#include<bits/stdc++.h>
using namespace std;

const int nmax=1e5+42,mod=998244353,MX=512;

long long proper(long long x)
{
    x=x%mod;
    x=(x+mod)%mod;
    return x;
}
long long my_pwr(long long a,int b)
{
    long long ret=1;

    while(b)
    {
        if(b%2)ret=ret*a%mod;
        a=a*a%mod;
        b=b/2;
    }
    return ret;
}
int n,m;
vector<int> adj[nmax];

int sg[nmax];

int rec(int node)
{
    if(sg[node]!=-1)return sg[node];

    set<int> in={};

    for(auto w:adj[node])
        in.insert(rec(w));

    int g=0;

    while(in.count(g))g++;

    sg[node]=g;

    return g;
}

struct row
{
    long long coeff[MX];
    long long sum;
};
row to_solve[MX];

int seen[nmax];

void make_normal(int row,int id)
{
    if(to_solve[row].coeff[id]==0)return;

    long long mult=to_solve[row].coeff[id];

    mult=my_pwr(mult,mod-2);

    to_solve[row].sum=(to_solve[row].sum*mult)%mod;

    for(int i=0;i<MX;i++)
        to_solve[row].coeff[i]=(to_solve[row].coeff[i]*mult)%mod;
}

void sub(int small,int big)
{
    to_solve[small].sum=proper(to_solve[small].sum-to_solve[big].sum);

    for(int i=0;i<MX;i++)
        to_solve[small].coeff[i]=proper(to_solve[small].coeff[i]-to_solve[big].coeff[i]);
}
int main()
{
    scanf("%i%i",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int u,v;
        scanf("%i%i",&u,&v);
        adj[u].push_back(v);
    }

    memset(sg,-1,sizeof(sg));

    for(int i=1;i<=n;i++)
        rec(i);

    for(int i=1;i<=n;i++)
        seen[sg[i]]++;

    long long inv=my_pwr(n+1,mod-2);

    for(int i=0;i<MX;i++)
    {
        to_solve[i].sum=inv*(i==0?0:1);

        to_solve[i].coeff[i]=1;

        for(int j=0;j<MX;j++)
        {
            int where=i^j;

            long long sum=to_solve[i].coeff[where]-inv*seen[j];

            sum=(sum%mod+mod)%mod;

            to_solve[i].coeff[where]=sum;
        }

        //cout<<"i= "<<i<<" : ";for(int j=0;j<=MX;j++)cout<<to_solve[i].coeff[j]<<" ";cout<<" expected= "<<to_solve[i].sum<<endl;
    }

    for(int i=MX-1;i>=0;i--)
    {
        for(int j=0;j<=i;j++)
            if(to_solve[j].coeff[i])
            {
                swap(to_solve[j],to_solve[i]);
                break;
            }

        if(to_solve[i].coeff[i]==0)continue;

        for(int j=0;j<=i;j++)
            make_normal(j,i);

        for(int j=0;j<i;j++)
            if(to_solve[j].coeff[i])
            {
                sub(j,i);
            }
    }

    printf("%i\n",to_solve[0].sum);

    return 0;
}
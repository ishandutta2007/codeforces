#include <bits/stdc++.h>
using namespace std;
long long n;
int LIM=0;
long long mem[64];

vector<long long> pows[64];

long long rec(int st)
{
    if(mem[st]!=-1)return mem[st];
    long long ret,sum=0;

    if(st==1)ret=n;
    else if(st==2)
    {
        ret=sqrt(n);
        while(ret*ret>n)ret--;
        while((ret+1)*(ret+1)<=n)ret++;
    }
    else
    {
        int ok=0,not_ok=pows[st].size(),av;
        while(not_ok-ok>1)
        {
            av=(ok+not_ok)/2;
            if(pows[st][av]<=n)ok=av;
            else not_ok=av;
        }
        ret=ok;
    }



    //cout<<ret<<" "<<st<<" "<<n<<endl;
    ret--;
    for(int i=2;i*st<=LIM;i++)
        sum=sum+rec(i*st);
    //cout<<st<<" -> "<<ret<<" "<<sum<<endl;
    ret=ret-sum;
    mem[st]=ret;
    //cout<<IN<<endl;
    return ret;
}
int main()
{
for(int st=3;st<64;st++)
{
    pows[st].push_back(0);
    for(int i=1;true;i++)
    {
        long long now=1e18;
        for(int j=1;j<=st;j++)now=now/i;
        if(now==0)break;
        long long prod=1;
        for(int j=1;j<=st;j++)prod=prod*i;
        pows[st].push_back(prod);
    }
}
int t;
scanf("%i",&t);
for(int i=1;i<=t;i++)
{
    for(int j=0;j<64;j++)mem[j]=-1;
    scanf("%lld",&n);
    LIM=0;
    while((1LL<<LIM)<=n)LIM++;
    printf("%lld\n",rec(1));
}
return 0;
}
#include <bits/stdc++.h>
#define int long long
#pragma GCC optimize("O3")
using namespace std;

int sum=0;
int n, a[1000005];
int b[1000005];

int check(int cac)
{
    int lol=0;
    int owe=0, out=0;
    for(int i=1; i<=n; i++)
    {
        b[i]=a[i];
    }
    for(int i=1; i<=n; i++)
    {
        lol+=owe+out;
        b[i]+=out;
        out=0;
        if(owe>0)
        {
            int ok=min(b[i], owe);
            owe-=ok;
            b[i]-=ok;
        }
        if(owe>0) continue;
        else
        {
            int ok=b[i]%cac;
            if(ok>cac-ok)
            {
                owe+=cac-ok;
            }
            else
            {
                out+=ok;
            }
        }
    }
    return lol;
}

signed main()
{
    ios::sync_with_stdio(false);
    int ans=2000000000000000000;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
    for(int i=2; i*i<=sum; i++)
    {
        if(sum%i==0)
        {
            while(sum%i==0) sum/=i;
            ans=min(ans, check(i));
        }
    }
    if(sum!=1)
    {
        ans=min(ans, check(sum));
    }
    if(ans==2000000000000000000)
    {
        cout<<-1;
    }
    else
    {
        cout<<ans;
    }
}
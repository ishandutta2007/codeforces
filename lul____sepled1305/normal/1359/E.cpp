/*Willem Reborn*/
#include<bits/stdc++.h>
using namespace std;
int n,k,i,j;
const int NUM = 5e5+10;
const int MOD = 998244353;
int quick_fac[NUM];
int quick_fac_inv[NUM];

int plusi(int a, int b)
{
    long long ans = 0LL+a+b;
    ans%=MOD;
    return (int) ans;
}

int multi(int a, int b)
{
    long long ans = 1LL*a*b;
    ans%=MOD;
    return (int) ans;
}

int quick_pow(int base, int pow)
{
    if(pow == 1)
        return base;
    else
    {
        int get = quick_pow(base, pow/2);
        if(get==0)
            cout<<base<<" "<<pow<<"\n";
        get = multi(get,get);
        if(pow%2==1)
            get = multi(get,base);
        return get;
    }
}

int quick_inv(int base)
{
    return quick_pow(base, MOD-2);
}

int main()
{
    cin>>n>>k;
    for(i=0;i<NUM;i++)
    {
        if(i==0)
        {
            quick_fac[0]=1;
            quick_fac_inv[0]=1;
        }
        else
        {
            quick_fac[i]=multi(quick_fac[i-1],i);
            quick_fac_inv[i]=quick_inv(quick_fac[i]);
            if(quick_fac_inv[i]==0)
            {
                cout<<quick_fac[i]<<" ";
                break;
            }
        }
    }
    i=1;
    int ans = 0;
    while(n/i>=k)
    {
        int cur = n/i-1;
        int here = multi(quick_fac[cur],quick_fac_inv[k-1]);
        here = multi(here,quick_fac_inv[cur-k+1]);
        ans = plusi(here,ans);
        i++;
    }
    cout<<ans;
    return 0;
}
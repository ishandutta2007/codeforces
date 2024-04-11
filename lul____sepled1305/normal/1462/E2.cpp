#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
vector<int> fac;

int sum(int a,int b)
{
    return (a+b)%MOD;
}

int mul(int a,int b)
{
    long long cur = (1LL*a*b)%MOD;
    return (int) cur;
}

int power(int base, int pow)
{
    if(pow == 0)
        return 1;
    if(pow == 1)
        return base;

    int get = power(base,pow/2);
    get = mul(get,get);
    if(pow % 2 == 1)
        get = mul(get,base);
    return get;
}

int inverse(int base)
{
    return power(base,MOD-2);
}

int binom(int n, int m)
{
    if(m == 0)
        return 1;
    if(m > n)
        return 0;
    else
    {
        int cur = mul(fac[n],inverse(fac[m]));
        return mul( cur , inverse(fac[n-m]) );
    }
}

void solve()
{
    int n,m,k,i;
    vector<int> v;
    cin>>n>>m>>k;
    for(i=0;i<n;i++)
    {
        int a;
        cin>>a;
        v.push_back(a);
    }
    sort(v.begin(),v.end());
    int pointer1=0,pointer2=0,su = 0;
    for(pointer1=0;pointer1<n;pointer1++)
    {
        while(pointer2<n && v[pointer2]<=v[pointer1]+k)
            pointer2++;
        pointer2--;
        su = sum(su, binom(pointer2-pointer1,m-1));
    }
    cout<<su<<endl;
}

int main()
{
    int i,cur = 1,t;
    for(i=0;i<3e5;i++)
    {
        fac.push_back(cur);
        cur = mul(cur,i+1);
    }
    cin>>t;
    while(t--)
        solve();
    return 0;
}
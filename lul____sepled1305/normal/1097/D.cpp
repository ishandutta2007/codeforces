#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
int k,ans=1,powe;
long long n,i;
int inverse[1050];

int plusi(int a,int b)
{
    long long cur = 0LL + a + b;
    cur%=MOD;
    return (int) cur;
}

int multi(int a,int b)
{
    long long cur = 1LL * a * b;
    cur%=MOD;
    return (int) cur;
}

int power(int base, int pow)
{
    if(pow == 0)
        return 1;
    else if(pow==1)
        return base;
    else
    {
        int get = power(base,pow/2);
        get = 0LL + multi(get,get);
        if(pow%2==1)
            get = multi(get,base);
        return get;
    }
}

int inv(int base)
{
    return power(base, MOD-2);
}

int calculate(int base, int pow, int round)
{
    int dp[pow+1][round+1];
    int i,j,k;
    int ans = 0;
    for(i=0;i<=pow;i++)
        for(j=0;j<=round;j++)
            dp[i][j] = 0;
    dp[pow][0] = 1;
    for(i=1;i<=round;i++)
    {
        for(j=0;j<=pow;j++)
        {
            int quick = inverse[j+1];
            for(k=0;k<=j;k++)
            {
                dp[k][i]=plusi(dp[k][i],multi(dp[j][i-1],quick));
            }
        }
    }
    for(i=0;i<=pow;i++)
    {
        int mul = power(base,i);
        ans=plusi(ans,multi(dp[i][round],mul));
    }
    return ans;
}

int main()
{
    cin>>n>>k;
    for(i=0;i<1000;i++)
    {
        inverse[i] = inv(i);
    }
    int sqr = (int) sqrt(n);
    i=2;
    while(n!=1)
    {
        if(n%i==0)
        {
            int here=0;
            while(n%i==0)
            {
                here++;
                n/=i;
            }
            int cal;
            if(i>MOD)
            {
                long long cur = i%MOD;
                cal = (int) cur;
            }
            else
                cal = i;
            ans=multi(ans,calculate(cal,here,k));
        }
        i++;
        if(i>sqr)
            i=n;
    }
    cout<<ans;
    return 0;
}
/*
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#pragma GCC optimize ("unroll-loops")
*/
#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42,mod=1e9+7;

int n,inp[nmax],outp[nmax];

int dp[64][7];//position, sub

int w=1;

int mem=0;

void solve()
{
        long long n;

        scanf("%lld",&n);

    //system("pause");

    long long fast=0;

    if(n==1)fast=1;
    else if(n==2)fast=2;
    else if(n==3)fast=2;
    else
    {

        while(n%4!=3)
        {
            if(n%2==0)fast=(fast+n/4+1)%mod;
            n--;
        }

        long long i=n/4+1;

        //cout<<"i= "<<i<<endl;

        i=i%mod;

        fast=(fast+i*(i+1))%mod;
    }

    printf("%lld\n",fast);

    //assert(fast==outp);
    //printf("%i\n",outp);
}

int main()
{
    int t;

    scanf("%i",&t);

    while(t)
    {
        solve();

        t--;
    }


    return 0;
}
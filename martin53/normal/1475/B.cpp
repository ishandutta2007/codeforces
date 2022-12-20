#include<bits/stdc++.h>
using namespace std;

int solve()
{
    int n;
    cin>>n;

    while(n>=0)
    {
        if(n%2020==0)return 1;
        n=n-2021;
    }

    return 0;
}

int main()
{
    int t;
    cin>>t;

    while(t)
    {
        t--;

        if(solve())cout<<"YES\n";
        else cout<<"NO\n";
    }

    return 0;
}
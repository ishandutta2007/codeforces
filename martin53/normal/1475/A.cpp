#include<bits/stdc++.h>
using namespace std;

bool solve()
{
    long long n;
    cin>>n;

    return n&(n-1);
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
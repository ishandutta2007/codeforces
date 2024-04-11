#include<bits/stdc++.h>
using namespace std;

long long sum(long long n)
{
    long long ret=0;
    while(n)
    {
        ret+=n%10;
        n=n/10;
    }
    return ret;
}
bool ask(long long n)
{
    return __gcd(n,sum(n))!=1;
}
void solve()
{
    long long n;

    cin>>n;

    while(ask(n)==0)n++;

    cout<<n<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    int t;
    cin>>t;

    for(int p=1;p<=t;p++)
    {
        solve();
    }

    return 0;
}
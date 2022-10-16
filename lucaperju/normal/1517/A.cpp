#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    long long n,i,j,k,cnt,t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        if(n%2050)
        {
            cout<<"-1\n";
            continue;
        }
        n/=2050;
        int s=0;
        while(n)
        {
            s+=n%10;
            n/=10;
        }
        cout<<s<<'\n';
    }
    return 0;
}
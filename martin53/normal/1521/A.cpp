#include<bits/stdc++.h>
using namespace std;

void solve()
{
    long long a,b;

    cin>>a>>b;

    if(b==1)
    {
        cout<<"NO\n";
        return;
    }

    cout<<"YES\n";
    cout<<a<<" "<<a*b<<" "<<a*(b+1)<<endl;
}

int main()
{
    int t;
    cin>>t;

    while(t)
    {
        t--;
        solve();
    }

    return 0;
}
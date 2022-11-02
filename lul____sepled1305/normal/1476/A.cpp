#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n,k,i;
    cin>>n>>k;
    if(k <= n && n%k == 0)
    {
        cout<<1<<endl;
        return;
    }
    if(k < n)
        k+=n;
    if(k%n != 0)
        cout<<k/n+1<<endl;
    else
        cout<<k/n<<endl;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
        solve();
}
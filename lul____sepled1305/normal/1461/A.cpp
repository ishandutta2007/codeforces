/** Ithea best girl **/

#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        char c = 'a'+(i%3);
        cout<<c;
    }
    cout<<endl;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}
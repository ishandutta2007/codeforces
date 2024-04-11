#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int a[4];
    cin>>a[0]>>a[1]>>a[2]>>a[3];
    sort(a,a+4);
    cout<<a[0]*a[2]<<endl;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
        solve();
}
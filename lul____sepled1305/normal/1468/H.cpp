// Why didn't I do this problem during the contest TT

#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n,m,k,i;
    cin>>n>>k>>m;
    int b[m];
    for(i=0;i<m;i++)
        cin>>b[i];
    if((n-m)%(k-1) != 0)
    {
        cout<<"NO\n";
        return;
    }
    bool exist = false;
    for(i=0;i<m;i++)
    {
        if(b[i]-i-1 >= (k-1)/2 && n-(m-1-i)-b[i] >= (k-1)/2)
            exist = true;
    }
    if(exist)
        cout<<"YES\n";
    else
        cout<<"NO\n";
}

int main()
{
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}
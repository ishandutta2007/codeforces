#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n,i;
    string s;
    cin>>n>>s;
    int left[n+1],right[n+1];
    for(i=0;i<=n;i++)
        left[i] = -1, right[i] = -1;
    for(i=0;i<=n;i++)
    {
        if(i == 0 || s[i-1] == 'R')
        {
            left[i] = 0;
            continue;
        }
        else if(i == 1 || s[i-2] == 'L')
        {
            left[i] = 1;
            continue;
        }
        else
        {
            left[i] = left[i-2] + 2;
        }
    }
    for(i=n;i>=0;i--)
    {
        if(i == n || s[i] == 'L')
        {
            right[i] = 0;
            continue;
        }
        else if(i == n-1 || s[i+1] == 'R')
        {
            right[i] = 1;
            continue;
        }
        else
        {
            right[i] = right[i+2] + 2;
            continue;
        }
    }
    for(i=0;i<=n;i++)
        cout<<left[i]+right[i]+1<<' ';
    cout<<endl;
}

main()
{
    int t;
    cin>>t;
    while(t--)
        solve();
}
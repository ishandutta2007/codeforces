#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n,k,i,a, cur = 0,neck = 0;
    cin>>n>>k;
    vector<int> v;
    vector<int> sum;
    for(i=0;i<n;i++)
    {
        cin>>a;
        v.push_back(a);
        cur += a;
        sum.push_back(cur);
    }
    for(i=1;i<n;i++)
    {
        if((sum[i-1]*k)/100 < v[i])
            neck = max(neck,(v[i]*100+k-1)/k - sum[i-1]);
    }
    cout<<neck<<endl;
    //I hate this...
}

main()
{
    int t;
    cin>>t;
    while(t--)
        solve();
}
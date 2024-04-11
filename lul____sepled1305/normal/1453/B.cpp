#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n,i;
    cin>>n;
    vector<int> v;
    for(i=0;i<n;i++)
    {
        int a;
        cin>>a;
        v.push_back(a);
    }
    long long sum = 0;
    for(i=0;i<n-1;i++)
    {
        sum += abs(v[i]-v[i+1]);
    }
    int reduc = 0;
    for(i=1;i<n-1;i++)
    {
        int can = abs(v[i]-v[i+1]) + abs(v[i]-v[i-1]) - abs(v[i-1]-v[i+1]);
        reduc = max(reduc,can);
    }
    reduc = max(reduc, abs(v[1]-v[0]));
    reduc = max(reduc, abs(v[n-1]-v[n-2]));
    cout<<sum-reduc<<endl;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}
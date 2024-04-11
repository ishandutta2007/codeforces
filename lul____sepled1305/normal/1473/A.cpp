#include<bits/stdc++.h>
using namespace std;
 
void solve()
{
    vector<int> v;
    int n,d;
    bool pass = true;
    cin>>n>>d;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        v.push_back(a);
        pass = pass & (a <= d);
    }
    sort(v.begin(),v.end());
    if(v[0]+v[1] <= d || pass)
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
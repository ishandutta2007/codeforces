#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>a(n);
        for(int x=0;x<n;x++)
        cin>>a[x];
        sort(a.begin(),a.end());
        int ans=0;
        for(int x=1;x<n;x++)
        ans+=(a[x]-1)/(2*a[0]-1);
        cout<<ans<<endl;
    }
}
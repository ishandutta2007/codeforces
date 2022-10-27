#include<bits/stdc++.h>
using namespace std;
#define int long long
main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int x=1;x<=n;x++)
        if(x%2==1)cout<<(n+1)/2-(x-1)/2<<' ';
        else cout<<n-(x-1)/2<<' ';
        cout<<endl;
    }
}
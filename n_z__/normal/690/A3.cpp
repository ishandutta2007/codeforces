#include<bits/stdc++.h>
using namespace std;
main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,r,s=0;
        cin>>n>>r;
        for(int x=1,y;x<n;x++)
        cin>>y,s+=y;
        cout<<((r-s)%n+n)%n+1<<endl;
    }
}
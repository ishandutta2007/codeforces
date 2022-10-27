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
        string s;
        cin>>s;
        s=' '+s;
        int ans=0;
        for(int x=2;x<=n;x++)
        ans+=(s[x]!=s[x-1]);
        if(s[1]=='0')ans--;
        cout<<max(ans,0ll)<<endl;
    }
}
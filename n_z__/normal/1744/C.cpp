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
        char c;
        string s;
        cin>>n>>c>>s;
        if(c=='g'){cout<<0<<endl;continue;}
        s=s+s;
        s=' '+s;
        int ans=0,now=-1;
        for(int x=1;x<=2*n;x++)
        {
            if(now!=-1)now++;
            if(s[x]==c)now=max(now,0ll);
            if(s[x]=='g')ans=max(ans,now),now=-1;
        }
        cout<<ans<<endl;
    }
}
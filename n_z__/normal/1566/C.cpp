#include<bits/stdc++.h>
using namespace std;
#define int long long
main()
{
    int t;cin>>t;while(t--){
        int n;
        string s,t;
        cin>>n>>s>>t;
        int ans=0,lst=-1;
        for(int x=0;x<n;x++)
        if(s[x]!=t[x])lst=2,ans+=2;
        else if(s[x]=='1')if(lst==1)ans++,lst=-1;else lst=0;
        else if(lst==0)ans+=2,lst=-1;else ans++,lst=1;
		cout<<ans<<endl;
    }
}
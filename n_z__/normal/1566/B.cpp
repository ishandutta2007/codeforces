#include<bits/stdc++.h>
using namespace std;
#define int long long
main()
{
    int t;cin>>t;while(t--){
        string s;
        cin>>s;
        int ans=0;
        s="1"+s;
        for(int x=1;x<s.size();x++)
        if(s[x]!=s[x-1]&&s[x]=='0')ans++;
        cout<<min(ans,2ll)<<endl;
    }
}
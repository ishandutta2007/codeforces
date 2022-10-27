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
        int now=0;
        for(int x=1;x<=n;x++)
        if(s[x]=='Q')now++;
        else now=max(0ll,now-1);
        if(now==0)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}
#include<bits/stdc++.h>
using namespace std;
#define int long long
main()
{
    int t;cin>>t;while(t--){
        int a,b;
        cin>>a>>b;
        if(a==0&&b==0)cout<<0<<endl;
        else if(a==b)cout<<1<<endl;
        else if(a+b&1)cout<<-1<<endl;
        else cout<<2<<endl;
    }
}
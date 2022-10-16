#include<bits/stdc++.h>
using namespace std;
main(){
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int ans=0;
        cin>>ans;
        for(int x=2;x<=n;x++)
        {
            int y;
            cin>>y;
            ans&=y;
        }
        cout<<ans<<endl;
    }
}
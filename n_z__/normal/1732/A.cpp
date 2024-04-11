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
        int gc=0;
        for(int x=1;x<=n;x++){
            int y;
            cin>>y;
            gc=gcd(gc,y);
        }
        if(gc==1)cout<<0<<endl;
        else if(gcd(gc,n)==1)cout<<1<<endl;
        else if(gcd(gc,n-1)==1)cout<<2<<endl;
        else cout<<3<<endl;
    }
}
#include<iostream>
using namespace std;
main()
{
    int T;cin>>T;
    for(;T--;)
    {
        int a,b;cin>>a>>b;
        int ans;
        if(a<=b)
        {
            if(a*2<b)ans=b;
            else ans=a*2;
        }
        else
        {
            if(b*2<a)ans=a;
            else ans=b*2;
        }
        cout<<ans*ans<<endl;
    }
}
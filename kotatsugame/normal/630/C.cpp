#include<iostream>
using namespace std;
int N;
main()
{
    cin>>N;
    long long ans=0,t=1;
    for(;N--;)
    {
        ans+=t*=2;
    }
    cout<<ans<<endl;
}
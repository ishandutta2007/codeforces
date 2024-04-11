#include<iostream>
#include<map>
#include<algorithm>
using namespace std;
int N;
main()
{
    cin>>N;
    map<int,int>mp;
    int ans=0;
    for(int i=0;i<N;i++)
    {
        int A;
        cin>>A;
        ans=max(ans,++mp[A]);
    }
    cout<<ans<<endl;
}
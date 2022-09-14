#include<iostream>
using namespace std;
int N,M;
main()
{
    cin>>N>>M;
    if(M%N)cout<<-1<<endl;
    else
    {
        M/=N;
        int ans=0;
        while(M%2==0)M/=2,ans++;
        while(M%3==0)M/=3,ans++;
        cout<<(M==1?ans:-1)<<endl;
    }
}
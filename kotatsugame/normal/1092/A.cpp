#include<iostream>
using namespace std;
int T,N,K;
main()
{
    cin>>T;
    for(;T--;)
    {
        cin>>N>>K;
        string ans="";
        for(int i=0;i<K;i++)
        {
            int t=N/K;
            if(i<N%K)t++;
            for(int j=0;j<t;j++)ans+=i+'a';
        }
        cout<<ans<<endl;
    }
}
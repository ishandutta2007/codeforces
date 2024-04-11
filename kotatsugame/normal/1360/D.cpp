#include<iostream>
using namespace std;
int T,N,K;
main()
{
    cin>>T;
    for(;T--;)
    {
        cin>>N>>K;
        int ans=N;
        for(int i=1;i*i<=N;i++)if(N%i==0)
        {
            if(K>=i)
            {
                if(ans>N/i)ans=N/i;
            }
            if(K>=N/i)
            {
                if(ans>i)ans=i;
            }
        }
        cout<<ans<<endl;
    }
}
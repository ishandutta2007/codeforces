#include<iostream>
using namespace std;
int T;
long long N;
main()
{
    cin>>T;
    for(;T--;)
    {
        cin>>N;
        int ans=0;
        while(N>1)
        {
            ans++;
            if(N%2==0)N/=2;
            else if(N%3==0)N=N/3*2;
            else if(N%5==0)N=N/5*4;
            else
            {
                ans=-1;
                break;
            }
        }
        cout<<ans<<endl;
    }
}
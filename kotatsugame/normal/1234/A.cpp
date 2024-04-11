#include<iostream>
using namespace std;
int T;
main()
{
    cin>>T;
    for(;T--;)
    {
        int N;cin>>N;
        int sum=0;
        for(int i=0;i<N;i++)
        {
            int A;cin>>A;sum+=A;
        }
        cout<<(sum+N-1)/N<<endl;
    }
}
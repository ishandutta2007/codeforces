#include<iostream>
using namespace std;
int T,N;
main()
{
    cin>>T;
    for(;T--;)
    {
        cin>>N;
        for(int i=0;i<N;i++)cout<<(i+1)%N+1<<(i+1==N?"\n":" ");
    }
}
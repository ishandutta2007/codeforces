#include<iostream>
using namespace std;
int T,N,X;
main()
{
    cin>>T;
    for(;T--;)
    {
        cin>>N>>X;
        if(N<=2)puts("1");
        else
        {
            printf("%d\n",(N-2+X-1)/X+1);
        }
    }
}
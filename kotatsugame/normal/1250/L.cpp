#include<iostream>
#include<algorithm>
using namespace std;
int T,N,A[100];
main()
{
    cin>>T;
    for(;T--;)
    {
        cin>>N;
        for(int i=0;i<N;i++)cin>>A[i];
        bool fn=false;
        sort(A,A+N);
        for(int i=1;i<N;i++)if(A[i-1]+1==A[i])fn=true;
        puts(fn?"2":"1");
    }
}
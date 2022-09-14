#include<iostream>
using namespace std;
int T,N;
int A[200];
main()
{
    cin>>T;
    for(;T--;)
    {
        cin>>N;
        for(int i=0;i<N;i++)cin>>A[i];
        if(N==1)
        {
            puts("YES");
            continue;
        }
        int id=0;
        while(A[id]!=1)id++;
        bool ok=true;
        if(A[(id+N-1)%N]==2)
        {
            for(int j=0;j<N;j++)if(A[(id+N-j)%N]!=j+1)ok=false;
        }
        else if(A[(id+1)%N]==2)
        {
            for(int j=0;j<N;j++)if(A[(id+j)%N]!=j+1)ok=false;
        }
        else ok=false;
        puts(ok?"YES":"NO");
    }
}
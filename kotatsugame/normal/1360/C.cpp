#include<iostream>
#include<algorithm>
using namespace std;
int T,N,A[50];
main()
{
    cin>>T;
    for(;T--;)
    {
        cin>>N;
        int a=0,b=0;
        for(int i=0;i<N;i++)
        {
            cin>>A[i];
            if(A[i]%2)b++;
            else a++;
        }
        sort(A,A+N);
        bool fn=false;
        for(int i=1;i<N;i++)if(A[i]==A[i-1]+1)fn=true;
        cout<<(a%2==0&&b%2==0||fn?"YES":"NO")<<endl;
    }
}
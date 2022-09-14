#include<iostream>
using namespace std;
int N;
main()
{
    cin>>N;
    int A=0;
    for(int i=0;i<N;i++)
    {
        int a;cin>>a;A+=a%2;
    }
    if(A>N-A)A=N-A;
    cout<<A<<endl;
}
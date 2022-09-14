#include<iostream>
using namespace std;
int N;
main()
{
    cin>>N;
    for(;N--;)
    {
        long long A,B,C;
        cin>>A>>B>>C;
        A+=B+C;
        cout<<A/2<<endl;
    }
}
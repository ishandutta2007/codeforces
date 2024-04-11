#include<iostream>
using namespace std;
int N;
main()
{
    cin>>N;
    cout<<(N%4&&(N+1)%4?1:0)<<endl;
}
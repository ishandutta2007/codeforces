#include<iostream>
using namespace std;
int N;
main()
{
    cin>>N;
    cout<<N<<endl;
    for(int i=1;i<=N;i++)cout<<1<<(i==N?"\n":" ");
}
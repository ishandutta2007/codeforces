#include <iostream>
using namespace std;
main()
{
    int n;
    cin>>n;
    char c[n];
    for(int i=0;i<n;i+=4)
    {
        c[i]='a';
    }
    for(int i=1;i<n;i+=4)
    {
        c[i]='b';
    }
    for(int i=2;i<n;i+=4)
    {
        c[i]='c';
    }
    for(int i=3;i<n;i+=4)
    {
        c[i]='d';
    }
    for(int i=0;i<n;i++)
    {
        cout<<c[i];
    }
}
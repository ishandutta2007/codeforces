#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int a,b;
int main()
{
    cin>>a>>b;
    if(abs(a-b)<=1 && !(a==0 && b==0)) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}
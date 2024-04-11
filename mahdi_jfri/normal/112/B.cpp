#include <iostream>
using namespace std;
int main()
{
    int n,x,y;
    cin>>n>>x>>y;
    int a=n/2;
    if((x==a && y==a) || (x==a && y==a+1) || ((x==a+1)&&(y==a)) || ((x==a+1)&&(y==a+1)))
        {cout<<"NO";
        return 0;}
    cout<<"YES";
}
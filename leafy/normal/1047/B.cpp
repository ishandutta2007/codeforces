#include <iostream>
#include <cstdio>
using namespace std;
int n,x,y;
int main()
{
    cin>>n;
    int mx=0;
    for(int i=1;i<=n;i++)
        cin>>x>>y,mx=max(mx,x+y);
    cout<<mx;
    return 0;
}
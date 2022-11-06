#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n,min1,max1,min2,max2,min3,max3,a;
    cin>>n>>min1>>max1>>min2>>max2>>min3>>max3;
    a=min(max1,n-min2-min3);
    cout<<a<<' ';
    n-=a;
    a=min(max2,n-min3);
    cout<<a<<' '<<n-a;
    return 0;
}
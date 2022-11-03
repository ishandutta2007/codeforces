#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    long long n;
    long long x,mint=1,maxt=1;
    cin>>n;
    int max1=0,min1;
    cin>>x;
    long long y;
    cin>>y;
    if(x>y)
        {max1=x; min1=y;}
    else if(x!=y)
        {max1=y; min1=x;}
    else
    {
        max1=x; min1=y;
        mint++;
        maxt++;
    }
    for(int i=2;i<n;i++)
    {
        cin>>x;
        if(x>max1)
            {
                max1=x;
                maxt=1;
            }
        else if(x==max1)
            maxt++;
        if(x<min1)
            {
                min1=x;
                mint=1;
            }
        else if(x==min1)
            mint++;
    }
    cout<<max1-min1;
    if(max1-min1==0)
        cout<<" "<<(n*(n-1))/2;
    else
        cout<<" "<<maxt*mint;
}
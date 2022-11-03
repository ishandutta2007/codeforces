#include <iostream>
using namespace std;
int main()
{
    int min1,max1,n,a,t=0;
    cin>>n;
    cin>>min1;
    max1=min1;
    n--;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        if(a>max1)
            {
                t++;
                max1 = a;
            }
        if(a<min1)
            {
                t++;
                min1 = a;
            }
    }
    cout<<t;
}
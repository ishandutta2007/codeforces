#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int a[105],b,c;
    cin>>b;
    for(int i=0;i<b;i++)
        cin>>a[i];
    for(int i=0;i<b;i++)
    {
        for(int j=i+1;j<b;j++)
        {
            c=a[i]+a[j];
            for(int z=0;z<b;z++)
            {
                if(a[z]==c)
                    {cout<<z+1<<" "<<i+1<<" "<<j+1;
                    return 0;}
            }
        }
    }
    cout<<"-1";
}
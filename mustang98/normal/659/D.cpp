#include <iostream>
#include <vector>
#include <cmath>

#define first x;

using namespace std;

int main()
{
    int n;
    int x[10000];
    int y[10000];
    cin>>n;
    for (int i=0;i<=n;i++) cin>>x[i]>>y[i];
    int ans=0;
    int pos=1;

    //cout<<pos;
    for (int i=2;i<=n;i++)
    {
        int p=-1;
        //horiz
        if (y[i]==y[i-1])
        {
            if (x[i]>x[i-1])
            {
                if (y[i-1]>y[i-2]) p =1;
                else p=0;
            }
            else
            {
                if (y[i-1]>y[i-2]) p =0;
                else p=1;
            }
        }
        //ver
        if (x[i]==x[i-1])
        {
            if (y[i]>y[i-1])
            {
                if (x[i-1]>x[i-2]) p =0;
                else p=1;
            }
            else
            {
                if (x[i-1]>x[i-2]) p =1;
                else p=0;
            }
        }
        if (p!=pos) ans++;
    }
    cout<<ans;
    return 0;
}
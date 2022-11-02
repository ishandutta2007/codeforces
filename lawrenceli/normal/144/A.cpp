#include <iostream>
using namespace std;

int main()
{
    int n, a[100];
    cin >> n;
    for (int i=0; i<n; i++) cin >> a[i];
    int minI, minV=100, maxI, maxV=0;
    for (int i=0; i<n; i++)
    {
        if (a[i]<=minV)
        {
            minI=i;
            minV=a[i];
        }
    }
    for (int i=n-1; i>=0; i--)
    {
        if (a[i]>=maxV)
        {
            maxI=i;
            maxV=a[i];
        }
    }
    int best=maxI+n-1-minI;
    if (maxI>minI) best--;
    cout << best << endl;
}
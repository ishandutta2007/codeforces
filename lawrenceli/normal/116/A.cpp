#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n, a[1000], b[1000], num=0, maxCap=0;
    cin >> n;
    for (int i=0; i<n; i++)
    {
        cin >> a[i] >> b[i];
    }
    for (int i=0; i<n; i++)
    {
        num-=a[i];
        num+=b[i];
        maxCap=max(maxCap, num);
    }
    cout << maxCap << endl;
}
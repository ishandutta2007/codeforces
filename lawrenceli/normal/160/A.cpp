#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n, a[100], num=0, req=0, cur=0;
    cin >> n;
    for (int i=0; i<n; i++)
    {
        cin >> a[i];
        req+=a[i];
    }
    sort(a, a+n);
    req=req/2+1;
    for (int i=n-1; i>=0; i--)
    {
        num++;
        req-=a[i];
        if (req<=0)
        {
            cout << num << endl;
            return 0;
        }
    }
}
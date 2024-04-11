#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n, a[50], i;
    for (cin>>n, i = 0; i < n; i++) cin>>a[i];
    sort(a,a+n);
    unique(a,a+n);
    for (i = 0; i < n - 2; i++) if ((a[i+1] == a[i] + 1)&&(a[i+2] == a[i] + 2)) {cout<<"YES"; return 0;}
    cout<<"NO";
    return 0;
}
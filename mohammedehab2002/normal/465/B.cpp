#include <iostream>
#include <string.h>
using namespace std;
int main()
{
    int n,i,ans=0,l;
    cin >> n;
    int arr[n];
    for (i=0;i<n;i++)
    {
        cin >> arr[i];
        if (arr[i])
        l=i;
    }
    for (i=0;i<n;i++)
    {
        if (arr[i]==1)
        ans++;
        if (i!=n-1 && arr[i]==1 && arr[i+1]==0 && i!=l)
        ans++;
    }
    cout << ans;
}
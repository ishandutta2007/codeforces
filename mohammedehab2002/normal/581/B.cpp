#include <iostream>
#include <string.h>
using namespace std;
int main()
{
    int n,i,pos;
    cin >> n;
    int arr[n],ans[n];
    memset(ans,0,sizeof(ans));
    for (i=0;i<n;i++)
    cin >> arr[i];
    pos=n-1;
    for (i=n-2;i>=0;i--)
    {
        if (arr[pos]<arr[i])
        pos=i;
        else
        ans[i]=arr[pos]-arr[i]+1;
    }
    for (i=0;i<n;i++)
    cout << ans[i] << ' ';
}
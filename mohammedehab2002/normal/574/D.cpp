#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n,i;
    cin >> n;
    int arr[n+2];
    for (i=1;i<=n;i++)
    cin >> arr[i];
    arr[0]=arr[n+1]=0;
    for (i=1;i<=n;i++)
    arr[i]=min(arr[i],min(arr[i-1]+1,arr[i+1]+1));
    for (i=n;i>0;i--)
    arr[i]=min(arr[i],min(arr[i-1]+1,arr[i+1]+1));
    cout << *max_element(arr,arr+n+2);
}
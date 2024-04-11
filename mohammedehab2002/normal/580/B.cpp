#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    long long n,d,i,maxi=0,ans=0,res=0;
    cin >> n >> d;
    pair <long long,long long> arr[n];
    for (i=0;i<n;i++)
    cin >> arr[i].first >> arr[i].second;
    sort(arr,arr+n);
    for (i=0;i<n;i++)
    {
        if (arr[i].first-d>=arr[ans].first)
        {
            maxi=max(res,maxi);
            res-=arr[ans].second;
            ans++;
            i--;
        }
        else
        res+=arr[i].second;
    }
    cout << max(maxi,res);
}
#include<bits/stdc++.h>
using namespace std;
void solve()
{
    long long int n;cin>>n;
    long long int arr[n];
    for(long long int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    long long int ans=0;
    long long int min=arr[n-1];
    for(long long int i=n-2;i>=0;i--)
    {
        if(arr[i]<=min)
        {
            ans++;
            min=arr[i];
        }
    }
    cout<<n-ans-1<<"\n";
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int num;
    cin>>num;
    for(long long int i=0;i<num;i++)
    {
       	solve();
    }   
}
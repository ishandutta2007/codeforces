#include<bits/stdc++.h>
using namespace std;
int t,n,i,j,maxi;
int arr[100];

int main()
{
    cin>>t;
    for(i=0;i<t;i++)
    {
        maxi=0;
        cin>>n;
        for(j=0;j<n;j++)
        {
            cin>>arr[j];
            arr[j]=-arr[j];
        }
        sort(arr,arr+n);
        for(j=0;j<n;j++)
        {
            cout<<-arr[j]<<" ";
        }
        cout<<"\n";
    }
}
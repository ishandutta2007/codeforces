#include<bits/stdc++.h>
using namespace std;
void solve()
{
    long long int n;cin>>n;
    long long int arr[n];
    for(long long int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    long long int a=0;
    long long int b=0;
    long long int i=0;
    while(i<n/2){
        a+=arr[i];
        i++;
    }
    while(i<n){
        b+=arr[i];
        i++;
    }
    cout<<a*a+b*b<<"\n";
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int num =1;
    //cin>>num;
    for(long long int i=0;i<num;i++)
    {
       	solve();
    }   
}
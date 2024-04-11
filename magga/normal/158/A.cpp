#include<bits/stdc++.h>
using namespace std;
void solve()
{
    long long int n,k;cin>>n>>k;
    long long int arr[n];
    for(long long int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    long long int p = arr[n-k];
    long long int ans = 0;
    for(long long int i = 0; i<n; i++){
        if(arr[i]>0 && arr[i]>=p){
            ans++;
        }
    }
    cout<<ans<<"\n";
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int num=1;
    //cin>>num;
    for(long long int i=0;i<num;i++)
    {
       	solve();
    }
}
#include<bits/stdc++.h>
using namespace std;
void solve()
{   
    long long int n,m;cin>>n>>m;
    pair<long long int,long long int> arr[n];
    long long int ans = 0;
    for(long long int i=0;i<n;i++){
        cin>>arr[i].first;
        ans+=2*arr[i].first;
        arr[i].second = i+1;
    }
    if(m<n || n==2){
        cout<<-1<<"\n";
        return;
    }
    sort(arr,arr+n);
    ans+=(m-n)*(arr[0].first+arr[1].first);
    cout<<ans<<"\n";
    for(long long int i=0;i<n-1;i++){
        cout<<i+1<<" "<<i+2<<"\n";
    }
    cout<<1<<" "<<n<<"\n";
    for(long long int i=0;i<m-n;i++){
        cout<<arr[0].second<<" "<<arr[1].second<<"\n";
    }
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
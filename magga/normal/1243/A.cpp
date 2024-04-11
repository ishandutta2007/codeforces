#include<bits/stdc++.h>
using namespace std;
map<char,char>m;
void solve(){
    long long int n;cin>>n;
    long long int arr[n];
    for(long long int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n, greater<int>());
    long long int last = 1;
    long long int max = arr[0];
    for(long long int i=1;i<n;i++){
        max = arr[i];
        if(max<i+1){
            cout<<i<<"\n";
            return;
        }
    }
    cout<<n<<"\n";
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
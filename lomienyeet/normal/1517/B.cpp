#include <bits/stdc++.h>
using namespace std;
#define int long long
void eat(){
    int n,m;
    cin>>n>>m;
    int arr[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)cin>>arr[i][j];
        sort(arr[i],arr[i]+m);
    }
    for(int i=m;i>0;i--){
        int z=0;
        for(int j=0;j<n;j++){
            if(arr[j][0]<arr[z][0])z=j;
        }
        rotate(arr[z],arr[z]+1,arr[z]+i);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)cout<<arr[i][j]<<" ";
        cout<<"\n";
    }
}
signed main(){
    int t=1;
    cin>>t;
    while(t--)eat();
}
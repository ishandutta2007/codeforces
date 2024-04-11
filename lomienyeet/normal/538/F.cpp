#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ff first
#define ss second
signed main(){
    int n;
    cin>>n;
    int arr[n]={},ans[n]={};
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(!i)continue;
        for(int j=1;j<n;j++){
            int a=(i-1)/j,b;
            if(!a)b=n-1;
            else b=(i-1)/a;
            if(arr[i]<arr[a]){
                ans[j]++;
                if(b+1<n)ans[b+1]--;
            }
            j=b;
        }
    }
    int x=0;
    for(int i=1;i<n;i++){
        x+=ans[i];
        cout<<x<<" ";
    }
}
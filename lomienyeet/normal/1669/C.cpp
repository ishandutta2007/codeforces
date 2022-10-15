// i am just doing this to lower my TLE bot virtual solve speed

#include <bits/stdc++.h>
using namespace std;
#define int long long
void eat(){
    int n;
    cin>>n;
    int arr[n+1];
    for(int i=1;i<=n;i++)cin>>arr[i];
    int a=0,b=0;
    bool aaa=1;
    for(int i=1;i<=n;i++){
        if(i&1){
            if(i==1)a=arr[i]%2;
            else if(arr[i]%2!=a)aaa=0;
        }
        else{
            if(i==2)b=arr[i]%2;
            else if(arr[i]%2!=b)aaa=0;
        }
    }
    cout<<(aaa?"YES\n":"NO\n");
}
signed main(){
    int t=1;
    cin>>t;
    while(t--)eat();
}
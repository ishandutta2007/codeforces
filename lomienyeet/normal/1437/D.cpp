#include <bits/stdc++.h>
using namespace std;
#define int long long
void eat(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    int dep=1,cur=1,s=1;
    for(int i=2;i<n;i++){
        if(arr[i-1]>arr[i])cur--;
        if(!cur){
            cur=s;
            s=0;
            dep++;
        }
        s++;
    }
    cout<<dep<<"\n";
}
signed main(){
    int t;
    cin>>t;
    while(t--)eat();
}
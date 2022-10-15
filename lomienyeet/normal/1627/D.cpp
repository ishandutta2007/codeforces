// 19 mins
// def cant play d0
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mxN=1e6+5;
signed main(){
    int n;
    cin>>n;
    int arr[n+1],freq[mxN]={};
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        freq[arr[i]]++;
    }
    int ans=0;
    for(int i=1;i<=1000000;i++){
        if(!freq[i]){
            int x=0;
            for(int j=i,k=1;j<=1000000;j+=i,++k){
                if(freq[j])x=gcd(x,k);
            }
            if(x==1)ans++;
        }
    }
    cout<<ans<<"\n";
}
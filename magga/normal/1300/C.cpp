#include<bits/stdc++.h>
using namespace std;
long long int cach[50];
void pre(){
    cach[0]=1;
    for(long long int i=1;i<50;i++){
        cach[i]=2*cach[i-1];
    }
}
long long int sto[64]{0};
long long int op(long long int d){
    string s = std::bitset< 63 >( d ).to_string();
    for(long long int i=0;i<63;i++){
        if(s[i]=='1'){
            sto[62-i]--;
        }
    }
    long long int ret = 0 ;
    for(long long int i=0;i<63;i++){
        if(sto[i]>=1){
            ret+=cach[i];
        }
    }
    for(long long int i=0;i<63;i++){
        if(s[i]=='1'){
            sto[62-i]++;
        }
    }
    return ret;
}
void solve(){
    long long int n;cin>>n;
    long long int arr[n];
    long long int k = 0;
    for(long long int i=0;i<n;i++){
        cin>>arr[i];
        string s = std::bitset<63>(arr[i]).to_string();
        for(long long int i=0;i<63;i++){
            if(s[i]=='1'){
                sto[62-i]++;
            }
        }
        k=k|arr[i];
    }
    long long int ans = 0 , d , index = 0;
    for(long long int i=0;i<n;i++){
        d = k-op(arr[i]);
        if(d>ans){
            ans=d;
            index = i;
        }
    }
    cout<<arr[index]<<" ";
    for(long long int i=0;i<n;i++){
        if(i!=index){
           cout<<arr[i]<<" ";
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    long long int num = 1;
    //cin>>num;
    for(long long int i=0;i<num;i++){
       	solve();
    }   
}
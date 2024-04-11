#include<bits/stdc++.h>
using namespace std;
void pre(){}
long long int n;
long long int f[27]{0};
long long int arr[100001];
long long int opt(int a,int b){
    int start = 0;int end = n-1;
    int u = f[a];
    int ret = u;
    for(int i=1;i<=f[b]/2;i++){
        while(arr[start]!=b){
            if(arr[start]==a){
                u--;
            }
            start++;
        }
        start++;
        while(arr[end]!=b){
            if(arr[end]==a){
                u--;
            }
            end--;
        }
        end--;
        //cout<<i<<" "<<u<<"\n";
        ret=max(ret,2*i+u);
    }
    return ret;
}
void solve(){
    cin>>n;
    for(int i=0;i<27;i++) f[i]=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        f[arr[i]]++;
    }
    long long int ans = 0;
    for(int i=1;i<=26;i++){
        for(int j=i+1;j<=26;j++){
            ans=max(ans,opt(i,j));
            ans=max(ans,opt(j,i));
        }
    }
    //cout<<opt(10,1)<<"\n";
    cout<<ans<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    long long int num = 1;
    cin>>num;
    for(long long int i=0;i<num;i++){
       	solve();
    }   
}
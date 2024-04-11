#include<bits/stdc++.h>
using namespace std;
void solve(){
    long long int n,m;cin>>n>>m;
    if(m==1){
        cout<<(n*(n+1))/2<<"\n";
        return;
    }
    long long int dat[m][n+1];
    long long int arr[m][n];
    for(long long int i=0;i<n;i++){
        cin>>arr[0][i];
    }
    for(long long int j = 1 ;j < m ; j++ ){
        for(long long int i = 0; i<n ;i++){
            cin>>arr[j][i];
            dat[j][arr[j][i]]=i;
        }
    }
    long long int ans = 0 ;
    long long int j=0;
    while(j<n){
        long long int temp[m];
        for(long long int i=1;i<m;i++){
            temp[i]=dat[i][arr[0][j]];
            //cout<<temp[i]<<" ";
        }
        long long int ret =0;
        bool flag = true;
        while(flag){
            ret++;
            j++;
            for(long long int i = 1 ; i < m ; i++ ){
                if(temp[i] != n-1 && arr[i][temp[i]+1] == arr[0][j]){
                    temp[i]++;
                }else{
                    flag=false;
                    break;
                } 
            }
        }
        ans+=(ret*(ret+1))/2;
    }
    cout<<ans<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int num = 1;
    //cin>>num;
    for(long long int i=0;i<num;i++){
       	solve();
    }   
}
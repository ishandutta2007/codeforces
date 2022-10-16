#include<bits/stdc++.h>
using namespace std;
void pre(){}
void solve(){
    long long int n;cin>>n;
    vector<long long int> arr[n+1];
    for(int i=1;i<=n;i++){
        for(int j=2;i*j<=n;j++){
            arr[i].push_back(i*j);
        }
    }
    long long int ans[n+1];
    long long int i = n;
    bool ar[n+1];
    for(long long int i=0;i<=n;i++) ar[i]=1; 
    for(int j = n;j>=1;j--){
        int uu = 0;
        for(auto k:arr[j]){
            if(ar[k]==1){
                uu++;
                ar[k]=0;
            }
        }
        for(int oo=0;oo<uu;oo++){
            ans[i]=j;
            i--;
        }
    }
    for(int i=2;i<=n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<"\n";
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
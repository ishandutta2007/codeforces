#include<bits/stdc++.h>
using namespace std;
void pre(){}
void solve(){
    long long int n,k;cin>>n>>k;
    string s;cin>>s;
    vector<long long int>arr[2*n];
    int val = 0;
    for(long long int i=0;i<2*n;i++){
        int count = 0;
        for(long long int j=1;j<n;j++){
            if(s[j]=='L' && s[j-1]=='R'){
                arr[i].push_back(j-1);
                count++;
            }
        }
        if(count==0){
            val=i;
            break;
        }
        for(auto k:arr[i]){
            s[k]='L';
            s[k+1]='R';
        }
    }
    
    long long int sum = 0;
    for(int i=0;i<val;i++){
        sum+=arr[i].size();
    }
    if(k<val || k>sum){
        cout<<-1<<"\n";
        return;
    }
    vector<int>ans[k];
    long long int oo = k;
    long long int curr = 0 ;
    for(int i=0;i<val;i++){
        for(long long int j:arr[i]){
            if(sum==k){
                ans[curr].push_back(j);
                curr++;
                sum--;
                k--;
            }else{
                ans[curr].push_back(j);
                sum--;
            }
        }
        if(ans[curr].size()>0){
            curr++;
            k--;
        }
    }
    for(long long int i=0;i<oo;i++){
        cout<<ans[i].size()<<" ";
        for(auto j:ans[i]){
            cout<<j+1<<" ";
        }
        cout<<"\n";
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
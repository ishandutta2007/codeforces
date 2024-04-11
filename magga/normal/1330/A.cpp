#include<bits/stdc++.h>
using namespace std;
void pre(){}
void solve(){
    long long int n,x,d;cin>>n>>x;
    int arr[301];
    for(int i=1;i<301;i++){
        arr[i]=1;
    }
    for(int i=0;i<n;i++){
        cin>>d;
        arr[d]=0;
    }
    int i = 0;
    int j = 1;
    for(;j<301;j++){
        i+=arr[j];
        if(i==x){
            break;
        }
    }
    int p = 1;
    while(arr[p+j]==0){
        p++;
        continue;
    }
    cout<<j+p-1<<"\n";
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
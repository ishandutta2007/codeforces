#include<bits/stdc++.h>
using namespace std;
void pre(){}
void solve(){
    long long int n;cin>>n;
    long long int arr[n][2];
    for(long long int i=0;i<n;i++){
        cin>>arr[i][0];
    }
    for(long long int i=0;i<n;i++){
        cin>>arr[i][1];
    }
    long long int a=0,b=0,c=0,d=0;
    for(long long int i=0;i<n;i++){
        if(arr[i][1]==arr[i][0]==1){
            a++;
        }
        if(arr[i][1]==1 && arr[i][0]==0){
            b++;
        }
        if(arr[i][0]==1 && arr[i][1]==0){
            c++;
        }
    }
    b++;
    if(c==0){
        cout<<-1<<"\n";
        return;
    }
    long long int aa=0,ba=ceil((b*1.0)/c);
    cout<<max(aa,ba)<<"\n";
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
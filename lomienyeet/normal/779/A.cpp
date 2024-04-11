#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[412]={0},sum=0;
    for(int i=0,t;i<2*n;i++){
        cin>>t;
        arr[t]+=(i<n?1:-1);
    }
    for(int i=1;i<=5;i++){
        int fuck=arr[i];
        if(fuck&1){
            cout<<"-1\n";
            return 0;
        }
        sum+=max(fuck,0);
    }
    cout<<(sum>>1)<<"\n";
}
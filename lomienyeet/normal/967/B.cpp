#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,x,y;
    cin>>n>>x>>y;
    int arr[n],s=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        s+=arr[i];
    }
    sort(arr+1,arr+n);
    int ptr=n-1;
    while(ptr>0){
        if((arr[0]*x)/s>=y)break;
        s-=arr[ptr--];
    }
    cout<<n-ptr-1<<"\n";
}
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,k,counter=0;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    for(int i=n-1;i>=0;i--){
        if(a[i]>=1 and a[i]>=a[n-k]){
            counter++;
        }
    }
    cout<<counter<<"\n";
    return 0;
}
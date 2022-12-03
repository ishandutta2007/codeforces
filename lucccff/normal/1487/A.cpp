#include <bits/stdc++.h>
using namespace std;

int main(){
    int i,j,k,l,m,n,t;
    int a[100];
    cin>>t;
    for(i=0;i<t;i++){
        cin>>n;
        k=1000;
        for(j=0;j<n;j++) {
            cin>>a[j];
            if (a[j]<k) k=a[j];
        }
        l=0;
        for(j=0;j<n;j++){
            if (a[j]==k) l++;
        }
        cout<<n-l<<endl;
    }
    return 0;
}
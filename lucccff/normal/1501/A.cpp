#include <bits/stdc++.h>
using namespace std;

int main(){
    int i,j,k,l,n,t;
    int a[100],b[100],m[100];
    cin>>t;
    for(i=0;i<t;i++){
        cin>>n;
        for(j=0;j<n;j++){
            cin>>a[j]>>b[j];
        }
        for(j=0;j<n;j++){
            cin>>m[j];
        }
        
        k=a[0];
        for(j=0;j<n-1;j++){
            k=k+m[j];
            if (k+(int)((b[j]-a[j]+1)/2)<b[j]) k=b[j];
            else k=k+(int)((b[j]-a[j]+1)/2);
            k+=a[j+1]-b[j];
        }
        cout<<k+m[n-1]<<endl;
    }
    return 0;
}
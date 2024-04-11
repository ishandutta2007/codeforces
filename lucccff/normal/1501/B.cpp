#include <bits/stdc++.h>
using namespace std;

int main(){
    int i,j,k,l,m,n,t;
    int a[200000];
    cin>>t;
    for(i=0;i<t;i++){
        cin>>n;
        for(j=0;j<n;j++) cin>>a[j];
        for(j=n-1;j>=0;j--) {
            k=a[j];
            while ((j>=0)&&(k!=0)){
                a[j]=1;
                j--;
                if (k-1<a[j]) k=a[j];
                else k--;
            }
        }
        for(j=0;j<n;j++) cout<<a[j]<<' ';
        cout<<endl;
    }
    return 0;
}
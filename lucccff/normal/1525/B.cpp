#include <bits/stdc++.h>
using namespace std;

int main(){
    int i,j,k,l,m,n,t;
    int a[100];
    cin>>t;
    for(i=0;i<t;i++) {
        cin>>n;
        for(j=0;j<n;j++) {
            cin>>a[j];
        }
        l=0;
        for(j=0;j<n;j++) {
            if (a[j]!=j+1) {
                l=1;
                break;
            }
        }
        if (a[0]!=1&&a[n-1]!=n) l++;
        if (a[0]==n&&a[n-1]==1) l++;
        cout<<l<<endl;
    }
    return 0;
}
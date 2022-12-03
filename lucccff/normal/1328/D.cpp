#include <bits/stdc++.h>
using namespace std;

int main(){
    long long i,j,k,l,m,n,t;
    int a[200010],c[200010];
    cin>>t;
    for(i=0;i<t;i++) {
        cin>>n;
        for(j=0;j<n;j++) {
            cin>>a[j];
        }
        a[n]=a[0];
        k=0;
        for(j=0;j<n;j++) {
            if (a[j]!=a[j+1]) k++;
        }
        if (k==0) {
            cout<<1<<endl;
            for(j=0;j<n;j++) {
                cout<<1<<' ';
            }
            cout<<endl;
        }
        else if ((k==n)&&(n&1)) {
            cout<<3<<endl;
            for(j=0;j<n-1;j++) {
                cout<<(j&1)+1<<' ';
            }
            cout<<3<<endl;
        }
        else if (n&1) {
            cout<<2<<endl;
            for(j=0;j<n;j++) {
                cout<<(j&1)+1<<' ';
                if (a[j]==a[j+1]) break;
            }
            for(;j<n-1;j++) {
                cout<<(j&1)+1<<' ';
            }
            cout<<endl;
        }
        else {
            cout<<2<<endl;
            for(j=0;j<n;j++) {
                cout<<(j&1)+1<<' ';
            }
            cout<<endl;
        }
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main(){
    long long i,j,k,l,m,n,t;
    int a[300],b[300];
    cin>>n;
    getchar();
    k=0;
    for(i=0;i<n;i++) {
        if (getchar()=='W') {
            a[i]=0;
        }
        else {
            a[i]=1;
        }
        b[i]=a[i];
        k+=a[i];
    }
    m=0;
    if (n%2==1) {
        if (k%2==0) {
            for(i=0;i<n-1;i++) {
                if (a[i]==1) {
                    m++;
                    a[i]=1-a[i];
                    a[i+1]=1-a[i+1];
                }
            }
            cout<<m<<endl;
            for(i=0;i<n-1;i++) {
                if (b[i]==1) {
                    cout<<i+1<<' ';
                    b[i]=1-b[i];
                    b[i+1]=1-b[i+1];
                }
            }
        }
        else {
            for(i=0;i<n-1;i++) {
                if (a[i]==0) {
                    m++;
                    a[i]=1-a[i];
                    a[i+1]=1-a[i+1];
                }
            }
            cout<<m<<endl;
            for(i=0;i<n-1;i++) {
                if (b[i]==0) {
                    cout<<i+1<<' ';
                    b[i]=1-b[i];
                    b[i+1]=1-b[i+1];
                }
            }
        }
    }
    else {
        if (k%2==0) {
            for(i=0;i<n-1;i++) {
                if (a[i]==1) {
                    m++;
                    a[i]=1-a[i];
                    a[i+1]=1-a[i+1];
                }
            }
            cout<<m<<endl;
            for(i=0;i<n-1;i++) {
                if (b[i]==1) {
                    cout<<i+1<<' ';
                    b[i]=1-b[i];
                    b[i+1]=1-b[i+1];
                }
            }
        }
        else {
            cout<<-1;
        }
    }
    return 0;
}
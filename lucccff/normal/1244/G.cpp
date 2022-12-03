#include <bits/stdc++.h>
using namespace std;

int main(){
    long long i,j,k,l,m,n,s;
    int c[1000010],a[1000010],b[1000010];
    cin>>k>>m;
    if (m<k*(k+1)/2) {
        cout<<-1;
        return 0;
    }
    if (m>=(k/2)*(2*k-k/2+1)+(k&1)*(k+1)/2) {
        cout<<(k/2)*(2*k-k/2+1)+(k&1)*(k+1)/2<<endl;
        for(i=0;i<k;i++) {
            cout<<i+1<<' ';
        }
        cout<<endl;
        for(i=0;i<k;i++) {
            cout<<k-i<<' ';
        }
        return 0;
    }
    n=k*(k+1)/2;
    if (m==n) {
        cout<<m<<endl;
        for(i=0;i<k;i++) {
            cout<<i+1<<' ';
        }
        cout<<endl;
        for(i=0;i<k;i++) {
            cout<<i+1<<' ';
        }
        cout<<endl;
        return 0;
    }
    for(i=0;i<k/2;i++) {
        if (n<m) {
            n+=k-2*i-1;
        }
        else {
            break;
        }
    }
    j=i-1;
    n-=k-2*j-1;
    for(i=0;i<j;i++) {
        a[i]=k-i;
        a[k-i-1]=i+1;
    }
    s=m-n;
    a[j]=j+s+1;
    a[j+s]=j+1;
    for(i=j+1;i<k-j;i++) {
        if (i!=j+s) {
            a[i]=i+1;
        }
    }
    cout<<m<<endl;
    for(i=0;i<k;i++) {
        cout<<i+1<<' ';
    }
    cout<<endl;
    for(i=0;i<k;i++) {
        cout<<a[i]<<' ';
    }
    cout<<endl;
    return 0;
}
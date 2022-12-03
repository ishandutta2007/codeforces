#include <bits/stdc++.h>
using namespace std;

int main() {
    int i,j,k,l,m,n;
    int a[100];
    cin>>n;
    k=0;
    for(i=0;i<n;i++) {
        cin>>a[i];
        if (a[i]>k) k=a[i];
    }
    l=a[0];
    for(i=1;i<n;i++) {
        l=__gcd(l,a[i]);
    }
    k=k/l;
    if ((k-n)%2==1) {
        cout<<"Alice";
    }
    else {
        cout<<"Bob";
    }
}
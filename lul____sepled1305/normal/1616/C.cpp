#include<bits/stdc++.h>
using namespace std;

int test(double a[], double st, double r, int n) {
    int ct = 0;
    for(int i=0;i<n;i++) {
        //cout<<"NODe: "<<i<<' '<<a[i]<<' '<<st<<' '<<i*r<<' '<<abs(a[i] - st + i*r)<<endl;
        if(abs(a[i] - st - i*r) < 0.0001)
            ct++;
    }
    //cout<<ct<<endl;
    return ct;
}

int main() {
    int T; cin>>T;
    while(T--) {
        int n; cin>>n;
        double a[n];
        for(int i=0;i<n;i++) cin>>a[i];
        int maxi = 1;
        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                double shift = (a[j]-a[i])/(j-i);
                maxi = max(maxi, test(a, a[i] - i*shift, shift, n));
            }
        }
        cout<<n-maxi<<endl;
    }
    return 0;
}
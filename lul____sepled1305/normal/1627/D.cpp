#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
bool a[N];

int gcd(int a, int b) {
    if(a < b) swap(a,b);
    if(b == 0) return a;
    return gcd(b, a%b);
}

int main() {
    int n; cin>>n;
    for(int i=0;i<n;i++) {
        int l; cin>>l;
        a[l] = true;
    }
    int ct = 0;
    for(int i=N-1;i>=1;i--) {
        if(a[i]) continue;
        int cur = 0;
        for(int j=2;j*i<N;j++) {
            if(a[i*j]) cur = gcd(cur,i*j);\
        }
        if(cur == i) {
            ct++; a[i] = true;
        }
    }
    cout<<ct;
    return 0;
}
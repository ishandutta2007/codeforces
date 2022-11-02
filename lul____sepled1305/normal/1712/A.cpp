#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii = pair<int,int>


int main() {
    int T; cin>>T;
    while(T--) {
        int n,k; cin>>n>>k;
        int ct = 0;
        for(int i=0;i<n;i++) {
            int a; cin>>a;
            ct += (a > k && i < k);
        }
        cout<<ct<<endl;
    }
    return 0;
}
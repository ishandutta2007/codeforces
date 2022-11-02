//
// Created by Nitit Jongsawatsataporn on 16/3/2022 AD.
//

#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5+10;
int ct[N];

int main() {
    int n,m; cin>>n>>m;
    int a[n][m];
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>a[i][j];
    //Compress to $y$ axis
    map<int,ll> sm;

    ll ans = 0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            ans += 1LL*ct[a[i][j]]*i - sm[a[i][j]];
            sm[a[i][j]] += i;
            ct[a[i][j]]++;
        }
    }
    //cout<<ans<<endl;
    //Compress to $x$ axis
    for(int i=0;i<N;i++) ct[i] = 0;
    sm.clear();
    for(int j=0;j<m;j++) {
        for(int i=0;i<n;i++) {
            ans += 1LL*ct[a[i][j]]*j - sm[a[i][j]];
            sm[a[i][j]] += j;
            ct[a[i][j]]++;
        }
    }
    cout<<ans;
    return 0;
}
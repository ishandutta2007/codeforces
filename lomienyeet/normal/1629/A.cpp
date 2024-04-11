#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n,k;
    cin>>n>>k;
    pair<int,int> p[n];
    for(int i=0;i<n;i++)cin>>p[i].first;
    for(int i=0;i<n;i++)cin>>p[i].second;
    sort(p,p+n);
    for(int i=0;i<n;i++){
        if(k>=p[i].first)k+=p[i].second;
    }
    cout<<k<<"\n";
}
int main(){
    int t;
    cin>>t;
    while(t--)solve();
}
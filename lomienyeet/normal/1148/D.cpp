#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n+1],b[n+1];
    vector<int> aa,bb;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
        if(a[i]<b[i])aa.push_back(i);
        else bb.push_back(i);
    }
    sort(aa.begin(),aa.end(),[&](int u,int v){return a[u]>a[v];});
    sort(bb.begin(),bb.end(),[&](int u,int v){return a[u]<a[v];});
    if(aa.size()<bb.size())swap(aa,bb);
    cout<<aa.size()<<"\n";
    for(auto i:aa)cout<<i<<" ";
}
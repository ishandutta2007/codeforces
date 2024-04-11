#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,inline,unroll-loops")
using namespace std;
#define int long long
void eat(){
    int n,m,s=0;
    cin>>n>>m;
    priority_queue<int> pq;
    while(m--){
        int x;
        cin>>x;
        s+=x;
        pq.push(x);
    }
    if(s<n){
        cout<<"-1\n";
        return;
    }
    else if(s==n){
        cout<<"0\n";
        return;
    }
    int ans=0;
    while(n){
        auto x=pq.top();
        pq.pop();
        if(n>=x){
            n-=x;
            s-=x;
        }
        else if(n>s-x){
            ans++;
            pq.push(x/2);
            pq.push(x/2);
        }
        else s-=x;
    }
    cout<<ans<<"\n";
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)eat();
}
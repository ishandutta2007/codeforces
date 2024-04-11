// never mind no need segtree at all lol

#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mxN=1e5;
int arr[mxN],weeee[mxN],a[mxN],b[mxN];
int eat(int l,int r){
    vector<int> v;
    for(int i=l+1;i<=r;i++)v.push_back(weeee[i]);
    stack<int> s;
    for(int i=0;i<v.size();i++){
        while(s.size()&&v[i]>v[s.top()])s.pop();
        if(s.empty())a[i]=-1;
        else a[i]=s.top();
        s.push(i);
    }
    while(s.size())s.pop();
    for(int i=v.size()-1;i>=0;i--){
        while(s.size()&&v[i]>=v[s.top()])s.pop();
        if(s.empty())b[i]=v.size();
        else b[i]=s.top();
        s.push(i);
    }
    int ans=0;
    for(int i=0;i<v.size();i++)ans+=v[i]*(b[i]-i)*(i-a[i]);
    return ans;
}
signed main(){
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++)cin>>arr[i];
    for(int i=2;i<=n;i++)weeee[i]=abs(arr[i]-arr[i-1]);
    while(q--){
        int l,r;
        cin>>l>>r;
        cout<<eat(l,r)<<"\n";
    }
}
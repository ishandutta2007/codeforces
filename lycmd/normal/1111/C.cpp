#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,a,b,x;
vector<int>p;
multiset<int>s;
int calc(int l,int r){
    return upper_bound(p.begin(),p.end(),r)-
        lower_bound(p.begin(),p.end(),l);
}
int solve(int l,int r){
    int mid=(l+r)>>1,s=calc(l,r);
    if(!s)return a;
    if(l==r)return b*s;
    return min(b*(r-l+1)*s,solve(l,mid)+solve(mid+1,r));
}
signed main(){
    ios::sync_with_stdio(0);
    for(cin>>n>>k>>a>>b;k--;)
        cin>>x,s.insert(x);
    for(int x:s)p.push_back(x);
    cout<<solve(1,1ll<<n)<<"\n";
}
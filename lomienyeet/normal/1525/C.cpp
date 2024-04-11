#include <bits/stdc++.h>
using namespace std;
#define int long long
void eat(){
    // there is a lot of stupid fucking implementation
    // but at least it is copy and paste-able i hope?
    int n,m;
    cin>>n>>m;
    int arr[n],ans[n];
    map<int,int> mp;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        ans[i]=-1;
        mp[arr[i]]=i;
    }
    vector<int> v,o1,o2;
    for(int i=0;i<n;i++){
        char c;
        cin>>c;
        if(c=='R')v.push_back(arr[i]);
        else{
            if(arr[i]&1)o1.push_back(arr[i]);
            else o2.push_back(arr[i]);
        }
    }
    sort(v.begin(),v.end());
    sort(o1.begin(),o1.end());
    sort(o2.begin(),o2.end());
    stack<int> a,b;
    queue<int> aa,bb;
    int lb=o1.size()-1,rb=o2.size()-1;
    for(int i=v.size()-1;i>=0;i--){
        while(lb>=0&&o1[lb]>v[i])a.push(o1[lb--]);
        while(rb>=0&&o2[rb]>v[i])b.push(o2[rb--]);
        if(v[i]&1){
            if(a.size()){
                ans[mp[v[i]]]=ans[mp[a.top()]]=(a.top()-v[i])>>1;
                a.pop();
            }
            else aa.push(v[i]);
        }
        else{
            if(b.size()){
                ans[mp[v[i]]]=ans[mp[b.top()]]=(b.top()-v[i])>>1;
                b.pop();
            }
            else bb.push(v[i]);
        }
    }
    while(lb>=0)a.push(o1[lb--]);
    while(rb>=0)b.push(o2[rb--]);
    while(aa.size()>1){
        auto x=aa.front();
        aa.pop();
        auto y=aa.front();
        aa.pop();
        ans[mp[x]]=ans[mp[y]]=m-x+((x-y)>>1);
    }
    while(bb.size()>1){
        auto x=bb.front();
        bb.pop();
        auto y=bb.front();
        bb.pop();
        ans[mp[x]]=ans[mp[y]]=m-x+((x-y)>>1);
    }
    while(a.size()>1){
        auto x=a.top();
        a.pop();
        auto y=a.top();
        a.pop();
        ans[mp[x]]=ans[mp[y]]=(x+y)>>1;
    }
    while(b.size()>1){
        auto x=b.top();
        b.pop();
        auto y=b.top();
        b.pop();
        ans[mp[x]]=ans[mp[y]]=(x+y)>>1;
    }
    if(a.size()&&aa.size()){
        auto x=a.top(),y=aa.front(),xx=x,yy=y,z=min(m-y,x),zz=z;
        x-=z;
        y+=z;
        z=max(m-y,x);
        if(x-z>=0)x-=z;
        else x+=z;
        if(y+z<=m)y+=z;
        else y-=z;
        zz+=z;
        ans[mp[xx]]=ans[mp[yy]]=zz+(abs(x-y)>>1);
    }
    if(b.size()&&bb.size()){
        auto x=b.top(),y=bb.front(),xx=x,yy=y,z=min(m-y,x),zz=z;
        x-=z;
        y+=z;
        z=max(m-y,x);
        if(x-z>=0)x-=z;
        else x+=z;
        if(y+z<=m)y+=z;
        else y-=z;
        zz+=z;
        ans[mp[xx]]=ans[mp[yy]]=zz+(abs(x-y)>>1);
    }
    for(int i=0;i<n;i++)cout<<ans[i]<<" ";
    cout<<"\n";
}
signed main(){
    int t;
    cin>>t;
    while(t--)eat();
}
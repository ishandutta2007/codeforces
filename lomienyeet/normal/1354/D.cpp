#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mxN=1e6+5;
int n,q,bit[mxN];
void upd(int x,int v){
    for(;x<mxN;x+=x&-x)bit[x]+=v;
}
int qry(int x){
    int ans=0;
    for(;x;x-=x&-x)ans+=bit[x];
    return ans;
}
int eat(int x){
    int l=1,r=n,res=1;
    while(l<=r){
        int mid=(l+r)>>1;
        if(qry(mid)>=x){
            r=mid-1;
            res=mid;
        }
        else l=mid+1;
    }
    return res;
}
signed main(){
    // if this passed i will be pissed
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>q;
    for(int i=0,x;i<n;i++){
        cin>>x;
        upd(x,1);
    }
    while(q--){
        int x;
        cin>>x;
        if(x>0)upd(x,1);
        else upd(eat(-x),-1);
    }
    if(!qry(n))cout<<"0\n";
    else cout<<eat(1)<<"\n";
}
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mxN=2e5+5;
int n,arr[mxN],ans[mxN],bit[mxN]={};
void upd(int x,int y){
    for(;x<=n;x+=x&-x)bit[x]+=y;
}
int qry(int x){
    int s=0;
    for(;x;x-=x&-x)s+=bit[x];
    return s;
}
signed main(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>arr[i];
    for(int i=1;i<=n;i++)upd(i,i);
    for(int i=n;i;i--){
        int l=1,r=n;
        while(l<r){
            int m=(l+r+1)>>1;
            if(qry(m-1)<=arr[i])l=m;
            else r=m-1;
        }
        upd(l,-l);
        ans[i]=l;
    }
    for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
}
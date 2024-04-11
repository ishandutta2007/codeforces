#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mxN=5e5+5;
int arr[mxN],a[mxN],b[mxN],segtree[mxN<<2];
void build(int idx,int l,int r){
    if(l==r){
        segtree[idx]=(arr[l]?b[l]-a[l]+1:0);
        return;
    }
    int mid=(l+r)>>1;
    build(idx<<1,l,mid);
    build(idx<<1|1,mid+1,r);
    segtree[idx]=max(segtree[idx<<1],segtree[idx<<1|1]);
}
int qry(int idx,int l,int r,int x,int y){
    if(l>y||r<x||l>r)return -1e18;
    if(x<=l&&r<=y)return segtree[idx];
    int mid=(l+r)>>1;
    return max(qry(idx<<1,l,mid,x,y),qry(idx<<1|1,mid+1,r,x,y));
}
signed main(){
    int n,cnt=0,ans=0;string s;
    cin>>n>>s;
    s="_"+s;
    for(int i=1;i<=n;i++){
        if(i==1||s[i]!=s[i-1]){
            arr[++cnt]=s[i]-'0';
            a[cnt]=b[cnt]=i;
        }
        else b[cnt]=i;
    }
    build(1,1,cnt);
    for(int i=1;i<=cnt;i++){
        if(arr[i]){
            for(int j=1;j<=b[i]-a[i]+1;j++){
                int l=min(i-1,1ll),r=i-1;
                while(l<r){
                    int mid=(l+r+1)>>1;
                    if(qry(1,1,cnt,mid,i-1)>j)l=mid;
                    else r=mid-1;
                }
                int lb=((l<i&&arr[l]&&b[l]-a[l]+1>j)?a[i]-b[l]-1+j:a[i]-1);
                l=i+1,r=max(i+1,cnt);
                while(l<r){
                    int mid=(l+r)>>1;
                    if(qry(1,1,cnt,i+1,mid)>=j)r=mid;
                    else l=mid+1;
                }
                int rb=((arr[l]&&b[l]-a[l]+1>=j)?a[l]-b[i]+j-2:n-b[i]);
                ans+=j*(lb+rb);
                if(j==b[i]-a[i]+1)ans+=j*lb*rb;
            }
            for(int j=1;j<=b[i]-a[i]+1;j++)ans+=(b[i]-a[i]-j+2)*j;
        }
    }
    cout<<ans<<"\n";
}
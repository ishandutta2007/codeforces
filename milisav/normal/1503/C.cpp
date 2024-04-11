#include<bits/stdc++.h>
#define maxn 500000
using namespace std;
long long n;
pair<long long,long long> a[maxn];
pair<long long,long long> b[maxn];
long long dp[maxn];
long long seg[4*maxn];
long long minv[4*maxn];
long long minval(long long id,long long l,long long r,long long x,long long y) {
    if(x<=l && r<=y) return minv[id];
    if(y<l || r<x) return 1e18;
    long long m=(l+r)/2;
    return min(minval(id*2+1,l,m,x,y),minval(id*2+2,m+1,r,x,y));
}
long long queryval(long long id,long long l,long long r,long long x,long long y) {
    if(x<=l && r<=y) return seg[id];
    if(y<l || r<x) return 1e18;
    long long m=(l+r)/2;
    return min(queryval(id*2+1,l,m,x,y),queryval(id*2+2,m+1,r,x,y));
}
void update(long long id,long long l,long long r,long long i,long long a,long long b) {
    minv[id]=min(minv[id],a);
    seg[id]=min(seg[id],b);
    if(l==r) {
        return;
    }
    long long m=(l+r)/2;
    if(i<=m) update(id*2+1,l,m,i,a,b);
    else update(id*2+2,m+1,r,i,a,b);
}
void clear_seg(long long id,long long l,long long r) {
    seg[id]=minv[id]=1e18;
    if(l==r) return;
    long long m=(l+r)/2;
    clear_seg(id*2+1,l,m);
    clear_seg(id*2+2,m+1,r);
}
long long m=0;
long long solve() {
    sort(b,b+m);
    clear_seg(0,0,m-1);
    dp[m-1]=0;
    update(0,0,m-1,m-1,dp[m-1],dp[m-1]+b[m-1].first);
    for(long long i=m-2;i>=0;i--) {
        dp[i]=1e10;
        if(b[i].first+b[i].second>=b[m-1].first) {
            dp[i]=0;
            update(0,0,m-1,i,dp[i],dp[i]+b[i].first);
            continue;
        }
        long long l=i,r=m-1;
        while(l<r) {
            long long t=(l+r+1)/2;
            if(b[i].first+b[i].second>=b[t].first) {
                l=t;
            }
            else {
                r=t-1;
            }
        }
        dp[i]=min(minval(0,0,m-1,i,l),queryval(0,0,m-1,l+1,m-1)-b[i].first-b[i].second);
        update(0,0,m-1,i,dp[i],dp[i]+b[i].first);
    }
    return dp[0];
}
int main() {
    scanf("%lld",&n);
    long long sum=0;
    for(long long i=0;i<n;i++) {
        scanf("%lld %lld",&a[i].first,&a[i].second);
        sum+=a[i].second;
    }
    long long ans1=sum;
    for(long long i=0;i<n;i++) {
        if(a[i]>=a[0]) {
            b[m++]=a[i];
        }
    }
    ans1+=solve();
    m=0;
    for(long long i=0;i<n;i++) {
        if(a[i]<=a[0]) {
            b[m++]=a[i];
        }
    }
    ans1+=solve();
    long long ans2=sum;
    m=0;
    for(long long i=1;i<n;i++) {
        b[m++]=a[i];
    }
    bool sm=true;
    for(int i=0;i<m;i++) {
        if(b[i].first<a[0].first) {
            sm=false;
            break;
        }
    }
    if(sm) {
        b[m++]=a[0];
    }
    ans2+=solve();
    printf("%lld",min(ans1,ans2));
    return 0;
}
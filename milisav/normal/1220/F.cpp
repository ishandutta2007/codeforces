#include<bits/stdc++.h>
#define maxn 300000
using namespace std;
int n;
int a[maxn];
int b[maxn];
int sparse[maxn][20];
void shift_left(int t) {
    for(int i=0;i<n;i++) b[i]=a[(i+t)%n];
}
void construct_sparse() {
    for(int i=0;i<n;i++) sparse[i][0]=i;
    for(int j=1;(1<<j)<=n;j++) {
        for(int i=0;i+(1<<j)<=n;i++) {
            if(b[sparse[i+(1<<(j-1))][j-1]]<b[sparse[i][j-1]]) sparse[i][j] = sparse[i+(1<<(j-1))][j-1];
            else sparse[i][j]=sparse[i][j-1];
        }
    }
}
int find_min(int l,int r) {
    int pmin=l;
    int i=0;
    r++;
    while(l<r) {
        if((r-l)&(1<<i)) {
            if(b[pmin]>b[sparse[l][i]]) pmin=sparse[l][i];
            l+=(1<<i);
        }
        i++;
    }
    return pmin;
}
int find_depth(int l,int r) {
    if(r<l) return 0;
    if(r==l) return 1;
    int m=find_min(l,r);
    return 1+max(find_depth(l,m-1),find_depth(m+1,r));
}
int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    int t=0;
    for(int i=0;i<n;i++) {
        if(a[i]==1) {
            t=i;
            break;
        }
    }
    int l=t-(n-1)+n;
    int r=t+n;
    shift_left(0);
    construct_sparse();
    pair<int,int> ans = {find_depth(0,n-1),0};
    while(l<r) {
        int m=(l+r)>>1;
        shift_left(m);
        construct_sparse();
        int depth_left = find_depth(0,t-(m-n)-1);
        int depth_right = find_depth(t-(m-n)+1,n-1);
        int depth = max(depth_left,depth_right)+1;
        ans = min(ans,{depth,m-n});
        if(depth_left < depth_right) r=m;
        else l=m+1;
    }
    int m=l;
    shift_left(m);
    construct_sparse();
    int depth_left = find_depth(0,t-(m-n)-1);
    int depth_right = find_depth(t-(m-n)+1,n-1);
    int depth = max(depth_left,depth_right)+1;
    ans = min(ans,{depth,m-n});
    printf("%d %d",ans.first,(ans.second+5*n)%n);
    return 0;
}
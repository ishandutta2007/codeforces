#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int n,p[maxn],a[maxn],ans;
void solve(int l,int r){
    if(r-l<=1)
    return;
    int mid=(l+r)>>1;
    solve(l,mid);solve(mid+1,r);
    unordered_map<int,int> m;
    int ma=0;
    for(int i=mid+1;i<=r;i++){
        ma=max(ma,a[i]);
        m[a[i]]=ma;
    }
    ma=0;
    for(int i=mid;i>=l;i--){
        ma=max(ma,a[i]);
        int need=ma-a[i];
        if(m.count(need)&&m[need]<=ma)
            ans++;
    }
    m.clear();
    ma=0;
    for(int i=mid;i>=l;i--){
        ma=max(ma,a[i]);
        m[a[i]]=ma;
    }
    ma=0;
    for(int i=mid+1;i<=r;i++){
        ma=max(ma,a[i]);
        int need=ma-a[i];
        if(m.count(need)&&m[need]<=ma)
            ans++;
    }
    return;
}

int main(){

    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    solve(1,n);
    printf("%d\n",ans);

}
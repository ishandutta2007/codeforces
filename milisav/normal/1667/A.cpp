#include<bits/stdc++.h>
#define maxn 6000
using namespace std;
int n;
long long a[maxn];
long long ans=0;
int main() {
    ans=1e18;
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n;i++) {
        long long cans=0;
        long long cur=0;
        for(int j=i-1;j>=0;j--) {
            long long o=cur/a[j]+1;
            cans=cans+o;
            cur=o*a[j];
        }
        cur=0;
        for(int j=i+1;j<n;j++) {
            long long o=cur/a[j]+1;
            cans=cans+o;
            cur=o*a[j];
        }
        ans=min(ans,cans);
    }
    printf("%lld",ans);
    return 0;
}
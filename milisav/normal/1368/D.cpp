#include<bits/stdc++.h>
#define maxn 200005
using namespace std;
int n;
int a[maxn];
int cnt[25];
int opt[maxn];
int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<20;j++) {
            if((a[i]&(1<<j)) == (1<<j)) cnt[j]++;
        }
    }
    for(int j=0;j<20;j++) {
        for(int i=0;i<cnt[j];i++) {
            opt[n-1-i]|=(1<<j);
        }
    }
    long long ans=0;
    for(int i=0;i<n;i++) {
        ans=ans+1ll*opt[i]*opt[i];
    }
    printf("%lld\n",ans);
    return 0;
}
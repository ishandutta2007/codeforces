#include<bits/stdc++.h>
#define maxn 1000
using namespace std;
int t;
int n;
int x[maxn];
int cnt[maxn];
int main() {
    scanf("%d",&t);
    while(t--) {
        for(int i=0;i<maxn;i++) cnt[i]=0;
        scanf("%d",&n);
        for(int i=0;i<n;i++) {
            scanf("%d",&x[i]);
        }
        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                cnt[x[j]-x[i]]++;
            }
        }
        int ans=0;
        for(int i=0;i<maxn;i++) {
            if(cnt[i]>0) ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
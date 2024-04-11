#include<bits/stdc++.h>
#define maxn 2000000
using namespace std;
int t;
int n,x;
int a[maxn];
int main() {
    scanf("%d",&t);
    while(t--) {
        scanf("%d %d",&n,&x);
        for(int i=0;i<n;i++) {
            scanf("%d",&a[i]);
        }
        int mn=a[0];
        int mx=a[0];
        int ans=0;
        for(int i=1;i<n;i++) {
            mn=min(mn,a[i]);
            mx=max(mx,a[i]);
            if(mx-mn>2*x) {
                ans++;
                mx=a[i];
                mn=a[i];
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
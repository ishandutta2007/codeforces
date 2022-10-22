#include<bits/stdc++.h>
#define maxn 200000
using namespace std;
int t;
int n,k;
int s[maxn];
int a[maxn];
int main() {
    scanf("%d",&t);
    while(t--) {
        scanf("%d %d",&n,&k);
        for(int i=n-k+1;i<=n;i++) {
            scanf("%d",&s[i]);
        }
        if(k==1) {
            printf("Yes\n");
        }
        else {
            for(int i=n-k+2;i<=n;i++) {
                a[i]=s[i]-s[i-1];
            }
            bool ok=true;
            for(int i=n-k+3;i<=n;i++) {
                if(a[i]<a[i-1]) ok=false;
            }
            if(ok && (1ll*a[n-k+2])*(n-k+1)>=s[n-k+1]) {
                printf("Yes\n");
            }
            else {
                printf("No\n");
            }
        }
    }
    return 0;
}
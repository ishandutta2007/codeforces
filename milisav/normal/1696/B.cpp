#include<bits/stdc++.h>
#define maxn 500000
using namespace std;
int t;
int n;
int a[maxn];
int main() {
    scanf("%d",&t);
    while(t--) {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) {
            scanf("%d",&a[i]);
        }
        a[0]=a[n+1]=0;
        int l=0,r=n+1;
        while(l<=n && a[l]==0) l++;
        while(r>=1 && a[r]==0) r--;
        if(l==n+1) {
            printf("0\n");
        }
        else {
            bool ok=true;
            for(int i=l;i<=r;i++) {
                if(a[i]==0) ok=false;
            }
            if(ok) printf("1\n");
            else printf("2\n");
        }
    }
    return 0;
}
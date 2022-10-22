#include<bits/stdc++.h>
#define maxn 2000000
using namespace std;
int t;
int n;
int a[maxn];
bool ex[maxn];
int main() {
    scanf("%d",&t);
    while(t--) {
        scanf("%d",&n);
        for(int i=0;i<n;i++) {
            scanf("%d",&a[i]);
            a[i]=abs(a[i]);
        }
        bool ok=false;
        for(int msk=0;msk<(1<<n);msk++) {
            int sm=0;
            for(int j=0;j<n;j++) {
                if(msk&(1<<j)) sm+=a[j];
            }
            if(ex[sm]) ok=true;
            ex[sm]=true;
        }
        if(ok) printf("YES\n");
        else printf("NO\n");
        for(int msk=0;msk<(1<<n);msk++) {
            int sm=0;
            for(int j=0;j<n;j++) {
                if(msk&(1<<j)) sm+=a[j];
            }
            ex[sm]=false;
        }
    }
    return 0;
}
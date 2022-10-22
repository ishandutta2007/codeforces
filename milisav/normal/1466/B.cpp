#include<bits/stdc++.h>
#define maxn 500000
using namespace std;
int t;
int n;
int x[maxn];
int main() {
    scanf("%d",&t);
    while(t--) {
        scanf("%d",&n);
        for(int i=0;i<n;i++) {
            scanf("%d",&x[i]);
        }
        int ans=1;
        bool ec=false;
        for(int i=1;i<n;i++) {
            if(x[i]>x[i-1]) {
                if(x[i]-x[i-1]>1) {
                    ans+=ec;
                    ec=false;
                }
                ans++;
            }
            else {
                ec=true;
            }
        }
        ans+=ec;
        printf("%d\n",ans);
    }
    return 0;
}
#include<bits/stdc++.h>
#define maxn 2000
using namespace std;
int t;
int n,k;
int x[maxn];
int y[maxn];
int main() {
    scanf("%d",&t);
    while(t--) {
        scanf("%d %d",&n,&k);
        for(int i=0;i<n;i++) {
            scanf("%d %d",&x[i],&y[i]);
        }
        bool ok=false;
        for(int i=0;i<n && !ok;i++) {
            ok=true;
            for(int j=0;j<n && ok;j++) {
                if(abs(x[j]-x[i])+abs(y[i]-y[j])>k) ok=false;
            }
        }
        if(ok) printf("1\n");
        else printf("-1\n");
    }
    return 0;
}
#include<bits/stdc++.h>
#define maxn 500000
using namespace std;
int t;
int n;
int a[maxn];
int c[4];
int main() {
    scanf("%d",&t);
    while(t--) {
        scanf("%d",&n);
        c[0]=c[1]=c[2]=0;
        for(int i=0;i<n;i++) {
            scanf("%d",&a[i]);
            if(a[i]<=2) c[a[i]]++;
        }
        if(c[1]>0) {
            sort(a,a+n);
            bool ok=true;
            for(int i=0;i<n-1;i++) {
                if(a[i+1]==a[i]+1) ok=false;
            }
            if(ok) printf("YES\n");
            else printf("NO\n");
        }
        else {
            printf("YES\n");
        }
    }
    return 0;
}
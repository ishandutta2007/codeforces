#include<bits/stdc++.h>
#define maxn 500000
using namespace std;
int t;
int n;
int a[maxn];
int b[maxn];
int d[maxn];
int main() {
    scanf("%d",&t);
    while(t--) {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) {
            scanf("%d",&a[i]);
        }
        for(int i=n;i>=1;i--) {
            for(int j=1;j<=i;j++) {
                if(a[j]==i) {
                    d[i]=j;
                }
            }
            if(d[i]==i) d[i]=0;
            for(int j=1;j<=i;j++) {
                b[j]=a[(j-1+d[i])%i+1];
            }
            for(int j=1;j<=i;j++) {
                a[j]=b[j];
            }
        }
        for(int i=1;i<=n;i++) printf("%d ",d[i]);
        printf("\n");
    }
    return 0;
}
#include<bits/stdc++.h>
#define maxn 500000
using namespace std;
int d,n,t;
int a[maxn];
int main() {
    scanf("%d",&t);
    while(t--) {
        scanf("%d",&n);
        for(int i=0;i<n;i++) scanf("%d",&a[i]);
        d=0;
        bool pos=true;
        for(int i=n-2;i>=0;i--) {
            a[i]-=d;
            if(a[i]<0) {
                pos=false;
                break;
            }
            if(a[i]>a[i+1]) {
                d+=(a[i]-a[i+1]);
                a[i]=a[i+1];
            }
        }
        if(pos) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
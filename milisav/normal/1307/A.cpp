#include<bits/stdc++.h>
using namespace std;
int t,n,d;
int a[5000];
int main() {
    scanf("%d",&t);
    while(t--) {
        scanf("%d %d",&n,&d);
        for(int i=0;i<n;i++) {
            scanf("%d",&a[i]);
        }
        while(d>0) {
            for(int i=1;i<n;i++) {
                if(a[i]>0) {
                    a[i-1]++;
                    a[i]--;
                    break;
                }
            }
            d--;
        }
        printf("%d\n",a[0]);
    }
    return 0;
}
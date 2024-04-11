#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    scanf("%d",&t);
    while(t--) {
        int n;
        scanf("%d",&n);
        if(n<=3) printf("-1");
        else {
            if(n%2==0) {
                for(int i=2;i<=n;i+=2) printf("%d ",i);
                printf("%d %d ",n-3,n-1);
                for(int i=n-5;i>=1;i-=2) printf("%d ",i);
            }
            else {
                for(int i=1;i<=n;i+=2) printf("%d ",i);
                printf("%d %d ",n-3,n-1);
                for(int i=n-5;i>=2;i-=2) printf("%d ",i);
            }
        }
        printf("\n");
    }
    return 0;
}
#include<bits/stdc++.h>
long long p1,p2;
long long q1,q2;
int main() {
    int t;
    scanf("%d",&t);
    while(t--) {
        int n;
        scanf("%d",&n);
        p1=p2=0;
        for(int i=0;i<n;i++) {
            int c;
            scanf("%d",&c);
            if(c%2==0) p1++;
            else p2++;
        }
        int m;
        scanf("%d",&m);
        q1=q2=0;
        for(int i=0;i<m;i++) {
            int c;
            scanf("%d",&c);
            if(c%2==0) q1++;
            else q2++;
        }
        printf("%lld\n",p1*q1+p2*q2);
    }
    return 0;
}
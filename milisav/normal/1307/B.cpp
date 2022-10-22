#include<bits/stdc++.h>
using namespace std;
int t,n,x;
int a[500000];
int main() {
    scanf("%d",&t);
    while(t--) {
        scanf("%d %d",&n,&x);
        bool oj=false;
        int m=-1;
        for(int i=0;i<n;i++) {
            scanf("%d",&a[i]);
            m=max(m,a[i]);
            if(a[i]==x) oj=true;
        }
        if(oj) {
            printf("1\n");
        }
        else {
            if(x<=2*m) {
                printf("2\n");
            }
            else {
                if(x%m==0) printf("%d\n",x/m);
                else printf("%d\n",x/m+1);
            }
        }
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int n,m;
int main() {
    scanf("%d %d",&n,&m);
    if(m%2==0) {
        int c1,c2;
        for(int j=1;j<=m/2;j++) {
            c1=j;
            c2=m-j+1;
            for(int i=1;i<=n;i++) {
                printf("%d %d\n",i,c1);
                printf("%d %d\n",n-i+1,c2);
            }
        }
        return 0;
    }
    if(m%2==1) {
        int c1,c2;
        for(int j=1;j<=m/2;j++) {
            c1=j;
            c2=m-j+1;
            for(int i=1;i<=n;i++) {
                printf("%d %d\n",i,c1);
                printf("%d %d\n",n-i+1,c2);
            }
        }
        int c=m/2+1;
        for(int i=1;n-i+1>=i;i++) {
            printf("%d %d\n",i,c);
            if(i!=n-i+1) printf("%d %d\n",n-i+1,c);
        }
        return 0;
    }
    return 0;
}
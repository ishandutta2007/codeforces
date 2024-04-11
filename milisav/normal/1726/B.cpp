#include<bits/stdc++.h>
#define maxn 150000
using namespace std;
int t;
int n,m;
int main() {
    scanf("%d",&t);
    while(t--) {
        scanf("%d %d",&n,&m);
        if((m%2!=0 && n%2==0) || m<n) printf("No\n");
        else {
            printf("Yes\n");
            if(n%2!=0) {
                for(int i=1;i<=n-1;i++) printf("1 ");
                printf("%d\n",m-(n-1));
            }
            else {
                for(int i=1;i<=n-2;i++) printf("1 ");
                printf("%d %d\n",(m-(n-2))/2,(m-(n-2))/2);
            }
        }
    }
    return 0;
}
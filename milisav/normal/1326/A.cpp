#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    scanf("%d",&t);
    while(t--) {
        int n;
        scanf("%d",&n);
        if(n==1) {
            printf("-1\n");
        }
        else {
            if((n-1)%3==0) {
                printf("4");
                n--;
            }
            for(int i=0;i<n-1;i++) printf("2");
            printf("3\n");
        }
    }
    return 0;
}
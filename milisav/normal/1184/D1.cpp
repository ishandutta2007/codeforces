#include<bits/stdc++.h>
using namespace std;
int main() {
    int n,k,m,t;
    scanf("%d %d %d %d",&n,&k,&m,&t);
    int o,i;
    while(t--) {
        scanf("%d %d",&o,&i);
        if(o==1) {
            n++;
            if(i<=k) k++;
        }
        else {
            if(k<=i) {
                n=i;
            }
            else {
                n=n-i;
                k=k-i;
            }
        }
        printf("%d %d\n",n,k);
    }
    return 0;
}
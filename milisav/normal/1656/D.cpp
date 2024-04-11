#include<bits/stdc++.h>
using namespace std;
int t;
long long n;
int main() {
    scanf("%d",&t);
    while(t--) {
        scanf("%lld",&n);
        long long nn=n;
        long long on=n;
        while(on%2==0) on=on/2;
        if(on==1) {
            printf("-1\n");
            continue;
        }
        else printf("%lld\n",min(on,2*n/on));
    }
    return 0;
}
#include<bits/stdc++.h>
typedef long long lld;
using namespace std;
int t;
int a,b;
int main() {
    scanf("%d",&t);
    while(t--) {
        scanf("%d %d",&a,&b);
        lld r=0,k=9;
        while(k<=b) {
            r++;
            k=k*10+9;
        }
        lld ans=a*r;
        printf("%lld\n",ans);
    }
    return 0;
}
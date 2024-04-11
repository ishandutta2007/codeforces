#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    scanf("%d",&t);
    while(t--) {
        int a,b,p,q;
        scanf("%d %d %d %d",&a,&b,&p,&q);
        if(a==p || b==q) printf("%d\n",abs(a-p)+abs(b-q));
        else printf("%d\n",abs(a-p)+abs(b-q)+2);
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int main() {
    int n,d;
    int t;
    scanf("%d",&t);
    while(t--) {
        scanf("%d %d",&n,&d);
        int x=sqrt(d);
        bool pos=false;
        for(int i=-2;i<=2;i++) {
            if(x+i>=0) {
                int tot=x+i+d/(x+i+1);
                if(d%(x+i+1)!=0) tot++;
                if(tot<=n) pos=true;
            }
        }
        if(pos) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
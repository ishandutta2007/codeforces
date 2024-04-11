#include<bits/stdc++.h>
using namespace std;
int main() {
    int n,d;
    scanf("%d %d",&n,&d);
    int m;
    scanf("%d",&m);
    while(m--) {
        int x,y;
        scanf("%d %d",&x,&y);
        if(d<=x+y && x+y<=2*n-d && -d<=x-y && x-y<=d) printf("yes\n");
        else printf("no\n");
    }
    return 0;
}
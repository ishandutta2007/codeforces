#include<bits/stdc++.h>
using namespace std;
int t;
char s[200000];
char c[2];
int main() {
    scanf("%d",&t);
    while(t--) {
        int a,l,r;
        scanf("%d %d %d",&l,&r,&a);
        int mv=r/a+r%a;
        int p=(r/a)*a-1;
        if(p>=l) mv=max(mv,p/a+p%a);
        printf("%d\n",mv);
    }
    return 0;
}
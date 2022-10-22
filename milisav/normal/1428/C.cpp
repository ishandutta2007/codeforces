#include<bits/stdc++.h>
#define maxn 400000
using namespace std;
int t;
int n;
char s[maxn];
int main() {
    scanf("%d",&t);
    while(t--) {
        scanf("%s",s);
        n=strlen(s);
        int ca=0;
        int cb=0;
        for(int i=0;i<n;i++) {
            if(s[i]=='A') ca++;
            else {
                if(ca>0) ca--;
                else {
                    if(cb>0) cb--;
                    else cb++;
                }
            }
        }
        printf("%d\n",ca+cb);
    }
    return 0;
}
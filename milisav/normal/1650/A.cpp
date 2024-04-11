#include<bits/stdc++.h>
using namespace std;
int t;
char s[200000];
char c[2];
int main() {
    scanf("%d",&t);
    while(t--) {
        scanf("%s",s);
        scanf("%s",c);
        int n=strlen(s);
        bool ok=false;
        for(int i=0;i<n;i++) {
            if(s[i]==c[0] && i%2==0) ok=true;
        }
        if(ok) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
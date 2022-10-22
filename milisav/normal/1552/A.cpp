#include<bits/stdc++.h>
using namespace std;
int n;
int t;
char s[100];
char g[100];
int main() {
    scanf("%d",&t);
    while(t--) {
        scanf("%d",&n);
        scanf("%s",s);
        for(int i=0;i<n;i++) g[i]=s[i];
        sort(s,s+n);
        int k=n;
        for(int i=0;i<n;i++) if(g[i]==s[i]) k--;
        printf("%d\n",k);
    }
    return 0;
}
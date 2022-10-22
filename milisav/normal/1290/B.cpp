#include<bits/stdc++.h>
using namespace std;
char s[400000];
int q;
int cnt[400000][30];
int main() {
    scanf("%s",s);
    int n=strlen(s);
    for(int i=0;i<n;i++) {
        cnt[i+1][s[i]-'a']++;
        for(int j=0;j<26;j++) cnt[i+2][j]=cnt[i+1][j];
    }
    scanf("%d",&q);
    while(q--) {
        int l,r;
        scanf("%d %d",&l,&r);
        if(r==l) {
            printf("Yes\n");
            continue;
        }
        if(s[l-1]!=s[r-1]) {
            printf("Yes\n");
            continue;
        }
        int t=0;
        for(int i=0;i<26;i++) {
            if(cnt[r][i]-cnt[l-1][i]>0) t++;
        }
        if(t>=3) {
            printf("Yes\n");
            continue;
        }
        printf("No\n");
    }
    return 0;
}
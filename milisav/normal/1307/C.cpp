#include<bits/stdc++.h>
using namespace std;
long long ct[30];
long long pct[30][30];
char s[200000];
int main() {
    scanf("%s",s);
    int n=strlen(s);
    for(int i=0;i<n;i++) {
        for(int j=0;j<26;j++) {
            pct[j][s[i]-'a']+=ct[j];
        }
        ct[s[i]-'a']++;
    }
    long long t=0;
    for(int i=0;i<26;i++) {
        for(int j=0;j<26;j++) {
            t=max(t,pct[i][j]);
        }
        t=max(t,ct[i]);
    }
    printf("%lld",t);
    return 0;
}
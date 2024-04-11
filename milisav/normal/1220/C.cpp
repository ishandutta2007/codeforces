#include<bits/stdc++.h>
#define maxn 1000000
using namespace std;
char s[maxn];
int n;
int main() {
    scanf("%s",s);
    char sm='z';
    n = strlen(s);
    for(int i=0;i<n;i++) {
        if(sm<s[i]) printf("Ann\n");
        else printf("Mike\n");
        sm=min(sm,s[i]);
    }
    return 0;
}
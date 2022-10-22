#include<bits/stdc++.h>
#define maxn 2000000
using namespace std;
int n;
char s[maxn];
int pz[maxn];
int main() {
    scanf("%d",&n);
    scanf("%s",s+1);
    for(int i=1;i<=n;i++) {
        if(s[i]=='(') pz[i]=pz[i-1]+1;
        else pz[i]=pz[i-1]-1;
    }
    if(pz[n]!=0) {
        printf("-1");
        return 0;
    }
    int c=0;
    for(int i=1;i<=n;i++) {
        if(pz[i]<0 || (pz[i-1]<0 && pz[i]==0)) c++;
    }
    printf("%d",c);
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
char s[100][100];
char t[100][100];
int n,m;
int main() {
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++) scanf("%s",s[i]);
    for(int j=0;j<m;j++) scanf("%s",t[j]);
    int q;
    scanf("%d",&q);
    while(q>0) {
        int y;
        scanf("%d",&y);
        y--;
        printf("%s%s\n",s[y%n],t[y%m]);
        q--;
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int t;
char s[1000][1000];
char d[1000][1000];
int r,c,k;
int n;
int main () {
    scanf("%d",&t);
    while(t--) {
        scanf("%d %d %d",&r,&c,&k);
        int n=0;
        for(int i=0;i<r;i++) {
            scanf("%s",s[i]);
            for(int j=0;j<c;j++) {
                if(s[i][j]=='R') n++;
            }
        }
        int g=0;
        int h=n/k;
        if(g<n%k) h++;
        for(int i=0;i<r;i++) {
            if(i%2==0) {
                for(int j=0;j<c;j++) {
                    if(s[i][j]=='R') h--;
                    if(h<0) {
                        g++;
                        h=n/k-1;
                        if(g<n%k) h++;
                    }
                    d[i][j]='a'+g;
                    if(g>=26) d[i][j]='A'+g-26;
                    if(g>=52) d[i][j]='0'+g-52;
                    printf("%c",d[i][j]);
                }
                printf("\n");
            }
            else {
                for(int j=c-1;j>=0;j--) {
                    if(s[i][j]=='R') h--;
                    if(h<0) {
                        g++;
                        h=n/k-1;
                        if(g<n%k) h++;
                    }
                    d[i][j]='a'+g;
                    if(g>=26) d[i][j]='A'+g-26;
                    if(g>=52) d[i][j]='0'+g-52;
                }
                for(int j=0;j<c;j++) printf("%c",d[i][j]);
                printf("\n");
            }
        }
    }
    return 0;
}
#include<bits/stdc++.h>
#define maxn 200000
using namespace std;
int t;
int n;
char s[maxn];
int ch[2][2];
int nch[2][2];
int main() {
    scanf("%d",&t);
    while(t--) {
        scanf("%s",s+2);
        s[0]='.';
        s[1]='!';
        n=strlen(s);
        ch[0][0]=0;
        ch[0][1]=ch[1][0]=ch[1][1]=n+10;
        for(int i=2;i<n;i++) {
            for(int j=0;j<2;j++) {
                for(int k=0;k<2;k++) {
                    nch[j][k]=n+5;
                    for(int x=0;x<2;x++) {
                        if((s[i]!=s[i-1] || k+j>0) && (s[i]!=s[i-2] || k+x>0)) {
                            nch[j][k]=min(nch[j][k],k+ch[x][j]);
                        }
                    }
                }
            }
            for(int j=0;j<2;j++) {
                for(int k=0;k<2;k++) {
                    ch[j][k]=nch[j][k];
                }
            }
        }
        printf("%d\n",min(min(ch[0][0],ch[0][1]),min(ch[1][0],ch[1][1])));
    }
    return 0;
}
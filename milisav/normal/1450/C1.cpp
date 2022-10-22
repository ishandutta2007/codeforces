#include<bits/stdc++.h>
#define maxn 5000
using namespace std;
int x[3];
int o[3];
int t;
int n;
char s[maxn][maxn];
int main() {
    scanf("%d",&t);
    while(t--) {
        scanf("%d",&n);
        int tcnt=0;
        int ccnt=0;
        for(int i=0;i<n;i++) {
            scanf("%s",s[i]);
        }
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(s[i][j]=='X') {
                    tcnt++;
                    x[(i+j)%3]++;
                }
                if(s[i][j]=='O') {
                    tcnt++;
                    o[(i+j)%3]++;
                }
            }
        }
        int optx=0,opto=2;
        if(x[1]+o[0]<x[optx]+o[opto]) {
            optx=1;
            opto=0;
        }
        if(x[2]+o[1]<x[optx]+o[opto]) {
            optx=2;
            opto=1;
        }
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(s[i][j]=='X') {
                    if(optx==(i+j)%3) {
                        ccnt++;
                        s[i][j]='O';
                    }
                }
                if(s[i][j]=='O') {
                    if(opto==(i+j)%3) {
                        ccnt++;
                        s[i][j]='X';
                    }
                }
            }
        }
        //cout<<ccnt<<" "<<tcnt<<endl;
        //printf("\n\n");
        for(int i=0;i<n;i++) {
            printf("%s\n",s[i]);
        }
        //printf("\n\n");
        x[0]=x[1]=x[2]=0;
        o[0]=o[1]=o[2]=0;
    }
    return 0;
}
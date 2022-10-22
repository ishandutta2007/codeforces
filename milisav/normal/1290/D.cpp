#include<bits/stdc++.h>
#define maxn 4096
using namespace std;
int n,k;
vector<int> blocks[maxn];
bool sm[maxn];
int main() {
    scanf("%d %d",&n,&k);
    int t=k;
    int r=n/t;
    for(int i=0;i<r;i++) {
        for(int j=1;j<=t;j++) {
            blocks[i].push_back(j+i*t);
        }
    }
    for(int i=0;i<r;i++) {
        int d=0;
        printf("R\n");
        fflush(stdout);
        for(int w=0;w<r;w++) {
            int p=(i+d+r)%r;
            for(int j=0;j<t;j++) {
                if(!sm[blocks[p][j]]) {
                    printf("? %d\n",blocks[p][j]);
                    fflush(stdout);
                    char g[2];
                    scanf("%s",g);
                    if(g[0]=='Y') sm[blocks[p][j]]=true;
                }
            }
            if(d>=0) d++;
            d=-d;
        }
    }
    int d=0;
    for(int i=1;i<=n;i++) if(!sm[i]) d++;
    printf("! %d\n",d);
    fflush(stdout);
    return 0;
}
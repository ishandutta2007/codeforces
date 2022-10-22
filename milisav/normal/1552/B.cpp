#include<bits/stdc++.h>
#define maxn 100000
using namespace std;
int t;
int n;
int r[maxn][10];
int main() {
    scanf("%d",&t);
    while(t--) {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) for(int j=1;j<=5;j++) scanf("%d",&r[i][j]);
        int bst=1;
        for(int i=2;i<=n;i++) {
            int cnt=0;
            for(int j=1;j<=5;j++) if(r[bst][j]<r[i][j]) cnt++;
            if(cnt<3) bst=i;
        }
        for(int i=1;i<=n && bst!=-1;i++) {
            if(i==bst) continue;
            int cnt=0;
            for(int j=1;j<=5;j++) if(r[bst][j]<r[i][j]) cnt++;
            if(cnt<3) bst=-1;
        }
        printf("%d\n",bst);
    }
    return 0;
}
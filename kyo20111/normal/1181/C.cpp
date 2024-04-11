#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,r[1010][1010],c[1010][1010],ans;
char mp[1010][1010];
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%s",mp[i]+1);

    for(int i=1;i<=n;i++){
        r[i][1]=1;
        for(int j=2;j<=m;j++){
            if(mp[i][j] == mp[i][j-1]) r[i][j]=r[i][j-1];
            else r[i][j]=j;
        }
    }

    for(int i=1;i<=m;i++){
        c[1][i]=1;
        for(int j=2;j<=n;j++){
            if(mp[j][i] == mp[j-1][i]) c[j][i]=c[j-1][i];
            else c[j][i]=j;
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int len = i - c[i][j] + 1;

            int nxt = i - len;
            if(nxt < 1 || nxt - c[nxt][j] + 1 != len) continue;

            nxt = nxt - len;
            if(nxt < 1 || nxt - c[nxt][j] + 1 < len) continue;

            int mn=1e9;
            for(int k=nxt-len+1;k<=i;k++) mn = min(mn, j-r[k][j]+1);
            ans += mn;
        }
    }

    printf("%d",ans);
}
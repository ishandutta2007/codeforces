#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int n,m,ct[maxn][5],a[maxn];
char s[maxn];
int ans;

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%s",s+1);
        for(int j=1;j<=m;j++){
            ct[j][s[j]-'A']++;
        }
    }
    for(int i=1;i<=m;i++){
        scanf("%d",&a[i]);
        int ma=0;
        for(int j=0;j<5;j++)
            ma=max(ma,ct[i][j]);
        ans+=(ma*a[i]);
    }
    printf("%d\n",ans);

}
/*
    Good Luck
        -Lysithea
*/
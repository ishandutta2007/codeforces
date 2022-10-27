#include<bits/stdc++.h>
using namespace std;
const int maxn = 3e5+10,mod = 1e9+7;
int b[1010][1010],n,m,r[1010],c[1010];
bool ban[1010][1010];
int nr[1010],cr[1010];

int main(){
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        scanf("%d",&r[i]);
        for(int j=1;j<=r[i];j++){
            b[i][j] = 1;
        }
        ban[i][r[i] + 1] =true;
    }
    for(int i=1;i<=m;i++){
        scanf("%d",&c[i]);
        for(int j=1;j<=c[i];j++){
            b[j][i] = 1;
        }
        ban[c[i] + 1][i] = true;
    }
    bool ok = true;
    for(int i=1;i<=n;i++){
        int j = 1 ;
        while(j <= m && b[i][j] == 1) j ++ ;
        j--;
        ok &= (r[i] == j);
    }
    for(int i=1;i<=m;i++){
        int j = 1;
        while(j <= n && b[j][i] == 1) j ++ ;
        j --;
        ok &= (c[i] == j);
    }
    int free = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(ban[i][j]){
                if(b[i][j] == 1)
                    ok = false;
            }
            else{
                if(b[i][j] == 0)
                free ++ ;
            }
        }
    }
    if(!ok)return !printf("0");
    int ans = 1;
    for(int i=1;i<=free;i++){
        ans = (ans * 2) %mod;
    }
    printf("%d\n",ans);
}
/*
    Good Luck
        -Lucina
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
const int MAXN = 100;
int len[MAXN+10], a[MAXN+10];
bool vis[MAXN+10];
char s[MAXN+10][110], ans[110];
int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i=1;i<=n;i++){
        scanf("%s", s[i]+1);
        len[i] = strlen(s[i]+1);
    }
    for(int i=1;i<=m;i++)
        scanf("%d", &a[i]);
    vis[a[1]] = true;
    for(int j=2;j<=m;j++){
        if(len[a[j]] != len[a[1]]){
            printf("No\n");
            return 0;
        }
        vis[a[j]] = true;
    }
    int ans_len = len[a[1]];
    for(int j=1;j<=ans_len;j++){
        bool fit = true;
        for(int i=2;i<=m;i++){
            if(s[a[i]][j] != s[a[1]][j]){
                fit = false;
                break;
            }
        }
        if(fit)
            ans[j] = s[a[1]][j];
        else ans[j] = '?';
    }
    for(int i=1;i<=n;i++){
        if(vis[i])
            continue;
        if(len[i] != ans_len)
            continue;
        bool fit = true;
        for(int j=1;j<=ans_len;j++){
            if(ans[j] == '?')
                continue;
            if(ans[j] != s[i][j]){
                fit = false;
                break;
            }
        }
        if(fit){
            printf("No\n");
            return 0;
        }
    }
    ans[ans_len+1] = '\0';
    printf("Yes\n%s\n", ans+1);

    return 0;
}
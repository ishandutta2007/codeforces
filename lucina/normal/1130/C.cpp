#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int a[55][55],r[3],c[3],n,b[55][55];
char s[2000];
vector<pair<int,int>> q[maxn];
void dfs(int i,int j,int x){
    b[i][j]=x;
    if(a[i][j+1]==1&&!b[i][j+1]){
        dfs(i,j+1,x);
    }
    if(a[i+1][j]==1&&!b[i+1][j]){
        dfs(i+1,j,x);
    }
    if(a[i-1][j]==1&!b[i-1][j]){
        dfs(i-1,j,x);
    }
    if(a[i][j-1]==1&&!b[i][j-1]){
        dfs(i,j-1,x);
    }
    return;
}

int main(){
    scanf("%d",&n);
    scanf("%d%d",&r[1],&c[1]);
    scanf("%d%d",&r[2],&c[2]);
    for(int i=1;i<=n;i++){
        scanf("%s",s+1);
        for(int j=1;s[j]!='\0';j++){
            a[i][j]=abs(1-s[j]+'0');
        }
    }
    int id=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(a[i][j]&&!b[i][j]){
                dfs(i,j,id);
                id++;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(b[i][j]){
                q[b[i][j]].push_back({i,j});
            }
        }
    }
    if(b[r[1]][c[1]]==b[r[2]][c[2]]){
        printf("0");
        return 0;
    }
    int ans=2e9;

    for(auto i:q[b[r[1]][c[1]]]){
        for(auto j:q[b[r[2]][c[2]]])
            ans=min(ans,(i.first-j.first)*(i.first-j.first)+(i.second-j.second)*(i.second-j.second));
    }
    printf("%d\n",ans);
}
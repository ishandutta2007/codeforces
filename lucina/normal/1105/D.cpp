#include<bits/stdc++.h>
using namespace std;
int n,m,p,b[1005][1005],s[11],d[1005][1005],u,v,ans[11];
queue<pair<int,int>> q[10];
char f[2000];
int main(){
    scanf("%d%d%d",&n,&m,&p);
    for(int i=1;i<=p;i++)
    scanf("%d",&s[i]);
    for(int i=1;i<=n;i++){
        scanf("%s",f);
        for(int j=0;j<m;j++){
            if(f[j]=='#')
                b[i][j+1]=20;
            else if(f[j]<='9'&&f[j]>='1'){
                q[f[j]-'0'].push({i,j+1});
                b[i][j+1]=f[j]-'0';
            }
        }
    }
    int pt=0;
    int x,y;
    bool ch=true;
    while(ch){
        pt++;
        ch=false;
        for(int i=1;i<=p;i++){
            while(!q[i].empty()){
                ch=true;
                x=q[i].front().first;
                y=q[i].front().second;
                if(d[x][y]>=s[i]*pt){
                    break;
                }
                q[i].pop();
                if(b[x-1][y]==0){
                    if(x>1&&y>=1&&x<=n&&y<=m){
                    b[x-1][y]=i;
                    d[x-1][y]=d[x][y]+1;
                    q[i].push({x-1,y});
                    }
                }
                if(b[x+1][y]==0){
                    if(x>=1&&y>=1&&x<=n-1&&y<=m){
                    b[x+1][y]=i;
                    d[x+1][y]=d[x][y]+1;
                    q[i].push({x+1,y});
                    }
                }if(b[x][y+1]==0){
                    if(x>=1&&y>=1&&x<=n&&y<=m-1){
                    b[x][y+1]=i;
                    d[x][y+1]=d[x][y]+1;
                    q[i].push({x,y+1});
                    }
                }if(b[x][y-1]==0){
                    if(x>=1&&y>1&&x<=n&&y<=m){
                    b[x][y-1]=i;
                    d[x][y-1]=d[x][y]+1;
                    q[i].push({x,y-1});
                    }
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(b[i][j]>=1&&b[i][j]<=p){
                ans[b[i][j]]++;
            }
        }
    }
    for(int i=1;i<=p;i++){
        printf("%d ",ans[i]);
    }
    return 0;
}
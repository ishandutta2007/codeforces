#include<bits/stdc++.h>
using namespace std;
int x1,y1,x2,y2,x3,y3,f[2000][2000],a,b,c,d;
pair<int,int> ff[4];
int main(){
    scanf("%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3);
    ff[1]={x1,y1};
    ff[2]={x2,y2};
    ff[3]={x3,y3};
    sort(ff+1,ff+4);
  //  printf("%d %d\n%d %d\n%d%d\n",ff[3].first,ff[3].second);
    for(int i=ff[1].first;i<=ff[2].first;i++){
        f[i][ff[1].second]=1;
    }
    for(int i=ff[3].first;i>ff[2].first;i--){
        f[i][ff[3].second]=1;
    }
    for(int i=max(max(y1,y2),y3);i>=min(min(y1,y2),y3);i--){
        f[ff[2].first][i]=1;
    }
    int ans=0;
    for(int i=0;i<=1005;i++){
        for(int j=0;j<=1005;j++){
            ans+=(f[i][j]);
        }
    }
    //printf("%d %d\n",x2,y2);
    printf("%d\n",ans);
    for(int i=0;i<=1005;i++){
        for(int j=0;j<=1005;j++){
            if(f[i][j]){
                printf("%d %d\n",i,j);
            }
        }
    }
}
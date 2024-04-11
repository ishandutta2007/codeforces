#include<stdio.h>
#include<math.h>
int n,m,lx,ly,count;
char s[1000][1000];

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%s",s[i]);
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<m;j++){
            if(s[i][j]=='B'){
                lx+=i,ly+=(j+1);
             count++;
             }
            }
    }
    printf("%d %d\n",lx/count,ly/count);
}
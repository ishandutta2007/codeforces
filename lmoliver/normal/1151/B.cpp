#include<bits/stdc++.h>
using namespace std;

const int N=555;
int a[N][N];
int ans[N]={0};

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&a[i][j]);
        }
    }
    for(int k=0;k<=10;k++){
        int res=0;
        int fe=0;
        int fe1=0;
        for(int i=1;i<=n;i++){
            int c[2]={0};
            for(int j=1;j<=m;j++){
                c[(a[i][j]>>k)&1]=j;
            }
            if(c[0]&&c[1]){
                fe=i;
                fe1=c[1];
            }
            if(c[0]){
                ans[i]=c[0];
                res^=0;
            }else{
                ans[i]=c[1];
                res^=1;
            }
        }
        if(res==0&&fe){
            ans[fe]=fe1;
            res^=1;
        }
        if(res){
            puts("TAK");
            for(int i=1;i<=n;i++){
                printf("%d ",ans[i]);
            }
            return 0;
        }
    }
    puts("NIE");
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+10;
int n,m,x,s;
bool a[52][maxn];

int main(){
    scanf("%d%d",&m,&n);
    for(int i=1;i<=m;i++){
        scanf("%d",&s);
        while(s--){
        scanf("%d",&x);
        a[i][x]=true;
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=i+1;j<=m;j++){
            bool ok=false;
            for(int k=1;k<=n;k++){
                ok|=(a[i][k]&a[j][k]);
            }
            if(!ok){
                printf("impossible\n");
                return 0;
            }
        }
    }
    printf("possible\n");
}
#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10,LOG=20;
int n,q,a[maxn],b[maxn][22],last[22],x,y;
int main(){
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=0;i<=LOG;i++)
        last[i]=n+1,b[n+1][i]=n+1;
    for(int i=n;i>=1;i--){
        for(int j=0;j<=LOG;j++){
            b[i][j]=n+1;
        }
        //b[i][j] is the smallest index such that has j-th bit
        //and reachable from i
        //b[i][j]
        for(int j=LOG;j>=0;j--){
            if(a[i]&(1<<j)){
                b[i][j]=i;
            for(int k=0;k<=LOG;k++){
                b[i][k]=min(b[i][k],b[last[j]][k]);
            }
            last[j]=i;
            }
        }
    }
    while(q--){
        scanf("%d%d",&x,&y);
        bool ch=false;
        for(int i=0;i<=LOG;i++){
            if(a[y]&(1<<i)){
                ch|=(b[x][i]<=y);
            }
        }
        printf(ch?"Shi\n":"Fou\n");
    }
}
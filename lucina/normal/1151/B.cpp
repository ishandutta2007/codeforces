#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int a[1000][1000],n,m;
int b[1000][1000];

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&a[i][j]);
        }
    }
    int ct=1;
    while(ct){
        ct=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                b[i][j]=a[i][j]%2;
                a[i][j]>>=1;
                ct+=a[i][j];
            }
        }
        vector<int> keep1,keep0,tmp1,tmp0;
        for(int i=1;i<=n;i++){
                tmp1=keep1;tmp0=keep0;
            if(i==1){
                for(int j=1;j<=m;j++){
                    if(b[i][j]==0&&keep0.empty())
                        keep0.push_back(j);
                    if(b[i][j]==1&&keep1.empty())
                    keep1.push_back(j);
                }
                continue;
            }
            for(int j=1;j<=m;j++){
                if(b[i][j]==1){
                    if(tmp1.size()==i-1&&keep0.size()!=i){
                        keep0=tmp1;
                        keep0.push_back(j);
                    }
                    if(tmp0.size()==i-1&&keep1.size()!=i){
                        keep1=tmp0;
                        keep1.push_back(j);
                    }
                }
                else{
                    if(tmp1.size()==i-1&&keep1.size()!=i){
                        keep1.push_back(j);
                    }
                     if(tmp0.size()==i-1&&keep0.size()!=i){
                        keep0.push_back(j);
                    }
                }
            }
        }
        if(keep1.size()==n){
            puts("TAK");
            for(int i:keep1){
                printf("%d ",i);
            }
            return 0;
        }
    }
    printf("NIE");
}
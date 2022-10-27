#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int a[55][55],b[55][55];
int n,m;
vector<pair<int,int>> ans;
 //
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&a[i][j]);
        }
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(a[i][j]==1&&a[i+1][j]==1&&a[i][j+1]==1&&a[i+1][j+1]==1){
                b[i][j]=1,b[i+1][j]=1,b[i][j+1]=1,b[i+1][j+1]=1;
                ans.push_back({i,j});
            }
        }
    }
    bool ok=true;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        ok&=(a[i][j]==b[i][j]);
    if(!ok)return !printf("-1");
    printf("%d\n",(int)ans.size());
    for(auto i:ans){
        printf("%d %d\n",i.first,i.second);
    }
}
/*
    Good Luck
        -Lucina
*/
#include<bits/stdc++.h>
using namespace std;
int a[510][510],b[510][510],n,m;
vector<int> c[1010],d[1010];

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&a[i][j]);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&b[i][j]);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            c[i+j].push_back({a[i][j]});
            d[i+j].push_back({b[i][j]});
        }
    }
    for(int i=1;i<=n+m;i++){
        sort(c[i].begin(),c[i].end());
        sort(d[i].begin(),d[i].end());
        if(c[i]!=d[i]){
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
}
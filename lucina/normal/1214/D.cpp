#include<bits/stdc++.h>
using namespace std;
int n,m;

int main(){
    scanf("%d%d",&n,&m);
    vector<int> cnt(n+m+5);
    vector<vector<bool>> d1,d2,d;
    d.resize(n+2);
    d1.resize(n+2);
    d2.resize(n+2);
    char s[m+5];
    for(int i=1;i<=n;i++){
        scanf("%s",s+1);
   //     cout<<s+1<<'\n';
        d[i].resize(m+2);
        d1[i].resize(m+2,0);
        d2[i].resize(m+2,0);
        for(int j=1;j<=m;j++){
            d[i][j]=(s[j]=='.'?1:0);
        }
    }
    d1[1][1] = true;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(i>1 && d[i][j] && d1[i-1][j] )
                d1[i][j] = true;
            if(j>1 && d[i][j] && d1[i][j-1])
                d1[i][j] = true;
        }
    }
    d2[n][m] = true;
    for(int i=n;i>=1 ;i--){
        for(int j=m;j>=1;j--){
            if(i+1<=n && d[i][j] && d2[i+1][j])
                d2[i][j] = true;
            if(j+1<=m && d[i][j] && d2[i][j+1]){
                d2[i][j] = true;
            }
        }
    }
    if(!d2[1][1])return !printf("0");
    d1[1][1]=false;
    d1[n][m]=false;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(d1[i][j] && d2[i][j]){
                cnt[i+j]++;
            }
        }
    }
    for(int i=2;i<=n+m;i++){
        if(cnt[i]==1){
            return !printf("1");
        }
    }
    printf("2");
}
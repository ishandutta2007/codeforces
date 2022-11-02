#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[1000000];
bool dp[2][1000];
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        a[i]%=m;
    }

    dp[0][0]=true;
    for(int i=0;i<n;i++){
        bool update=false;
        for(int j=0;j<m;j++){
            if(!dp[i&1][j])continue;
            if((j+a[i])%m==0){
                cout<<"YES"<<endl;
                return 0;
            }
            if(!dp[(i+1)&1][(j+a[i])%m])update=true;
            dp[(i+1)&1][(j+a[i])%m]=true;
            dp[(i+1)&1][j]=true;
        }
        if(!update)break;
    }
    cout<<"NO"<<endl;
    return 0;
}
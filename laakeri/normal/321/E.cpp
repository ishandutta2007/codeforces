#include <iostream>

using namespace std;

int ma[4001][4001];

int dp[801][4001];

int cost(int a, int b){
    a--;
    b--;
    int r=ma[b][b];
    if (a>0){
        r-=ma[a-1][b];
        r-=ma[b][a-1];
        r+=ma[a-1][a-1];
    }
    return r/2;
}

void cdp(int i, int opl, int opr, int l, int r){
    if (r<l) return;
    int m=(l+r)/2;
    int mi=1e9;
    int o=0;
    for (int ii=opl;ii<=min(m-1, opr);ii++){
        //cout<<m-ii+1<<" "<<m<<" "<<cost(m-ii+1, m)<<" "<<dp[i-1][m-ii]+cost(m-ii+1, m)<<endl;
        if (dp[i-1][ii]+cost(ii+1, m)<mi){
            mi=dp[i-1][ii]+cost(ii+1, m);
            o=ii;
        }
    }
    dp[i][m]=mi;
    //cout<<i<<" "<<m<<" "<<opl<<" "<<opr<<" "<<o<<" "<<mi<<endl;
    if (l<r){
        cdp(i, opl, o, l, m-1);
        cdp(i, o, opr, m+1, r);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin>>n>>k;
    for (int i=0;i<n;i++){
        for (int ii=0;ii<n;ii++){
            cin>>ma[i][ii];
            if (ii>0) ma[i][ii]+=ma[i][ii-1];
            if (i>0) ma[i][ii]+=ma[i-1][ii];
            if (i>0&&ii>0) ma[i][ii]-=ma[i-1][ii-1];
        }
    }
    for (int i=1;i<=n;i++){
        dp[1][i]=cost(1, i);
    }
    for (int i=2;i<=k;i++){
        cdp(i, i-1, n-1, i, n);
    }
    cout<<dp[k][n]<<endl;
}
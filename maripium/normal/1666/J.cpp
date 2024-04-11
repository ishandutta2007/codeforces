#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef unsigned long long ll;
typedef pair<int,int> pii;
typedef tuple<int,int,int> ti3;
const ll INF= 1LL<<60;
const int MAXN = 209;

ll a[MAXN][MAXN];
ll rs[MAXN][MAXN];
ll dp[MAXN][MAXN];
int bt[MAXN][MAXN];
int p[MAXN];

void trace(int s,int e, int lp){
    int m = bt[s][e];
    p[m]=lp;
    if(s==e)return;
    if(s<=m-1)trace(s,m-1,m);
    if(m+1<=e)trace(m+1,e,m);
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n;cin >> n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> a[i][j];
            rs[i][j]=rs[i][j-1]+rs[i-1][j]-rs[i-1][j-1]+a[i][j];
        }
    }
    for(int s=1;s<=n;s++){
        dp[s][s]=rs[s][n]-rs[s-1][n];//unit cost to all
        bt[s][s]=s;
    }
    for(int l=1;l<n;l++){//dp range length
        for(int s=1;s+l<=n;s++){
            int e = s+l;
            dp[s][e]=INF;
            for(int m=s;m<=e;m++){
                //ll ndp = dp[s][m-1]*(e-m+1) + dp[m+1][e]*(m-s+1)+rs[m][n]-(rs[m][e]-rs[m][s-1]);
                ll ndp = dp[s][m-1] + dp[m+1][e] + (rs[e][n]-rs[s-1][n]) - (rs[e][e]-rs[e][s-1]-rs[s-1][e]+rs[s-1][s-1]);
                if(ndp<dp[s][e]){
                    dp[s][e]=ndp;
                    bt[s][e]=m;
                }
            }
        }
    }
    //cout << dp[1][n] << endl;
    trace(1,n,0);
    for(int i=1;i<=n;i++){
        cout << p[i] << " \n"[i==n];
    }
}
#include<bits/stdc++.h>
using namespace std;
int const inf = 1e9 + 7;
int n, dp[2][201][201][401], m;
void update(int &x, int y){
    if(x > y) x = y;
}
/// minimal length of string that contain 1...i of a, 1.. j of b and has final balance = k
string a, b;
int rec(int st, int i, int j, int k){
    if(dp[st][i][j][k] != -1) return dp[st][i][j][k];
    dp[st][i][j][k] = inf;
    int &res = dp[st][i][j][k];
    if(st == 0){
        if(k > 0){
        res = min(res, rec(0, i - (a[i] == '('), j - (b[j] == '('), k - 1) + 1);
        res = min(res, rec(1, i - (a[i] == '('), j - (b[j] == '('), k - 1) + 1);
        }
    }
    else{
        if(k < (n + m)){
        res = min(res, rec(0, i - (a[i] == ')'), j - (b[j] == ')'), k + 1) + 1);
        res = min(res, rec(1, i - (a[i] == ')'), j - (b[j] == ')'), k + 1) + 1);
        }
    }
    return res;
}
int ans ;
string res;
void restoreans(int st, int i , int j, int k){
    if(ans == 0) return;
    if(st == 0){
        if(k > 0){
        int toA = i - (a[i] == '('), toB = j - (b[j] == '('), nk = k - 1;
        for(int nw_st = 0 ; nw_st < 2 ; nw_st ++)
        if(dp[st][i][j][k] == dp[nw_st][toA][toB][nk] + 1){
            res += '(';
            ans --;
            return restoreans(nw_st, toA, toB, nk);
        }
        }
    }
    else{
        if(k < (n + m)){
            int toA = i - (a[i] == ')'), toB = j - (b[j] == ')'), nk = k + 1;
        for(int nw_st = 0  ; nw_st < 2 ; nw_st ++)
            if(dp[st][i][j][k] == dp[nw_st][toA][toB][nk] + 1){
                res += ')';
                ans --;
                return restoreans(nw_st, toA, toB, nk);
            }
        }
    }

}

int main(){
    cin.tie(0) -> sync_with_stdio(false);
    cin >> a >> b;
    n = a.size();
    m = b.size();
    a  = '#' + a + '#';
    b = '#' + b + '#';
    for(int v = 0 ; v < 2 ; ++ v)
    for(int i = 0 ; i<= n; i ++)
        for(int j = 0 ;j <= m ;j ++)
        for(int k = 0 ;k <= n + m ; k ++)
        dp[v][i][j][k] = -1;
    /**
    n is zero
    */
    dp[0][0][0][0] = 0;
    dp[1][0][0][0] = inf;
    rec(1, n, m, 0);
    //cout << dp[0][n][m][0] << ' ' << dp[1][n][m][0];
    ans = dp[1][n][m][0];
    restoreans(1, n, m, 0);
    reverse(res.begin(), res.end());
    cout << res << '\n';
}
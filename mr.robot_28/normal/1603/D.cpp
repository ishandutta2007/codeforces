#include<bits/stdc++.h>
#define X first
#define Y second
#define sz(a) (int)a.size()
#define ll long long

using namespace std;

const int N = 1e5 + 100;
const int T = 350;
const int mod = 998244353;
int root[N];
int fi[N];
ll a[N], s1[N][T], s2[N][T];
void precalc(){
    for(int i = 1; i < N; i++)
    {
        fi[i] = i;
    }
    for(int i = 2; i < N; i++){
        if(fi[i] == i){
            for(int j = i; j < N; j += i){
                fi[j] -= fi[j] / i;
            }
        }
    }
    for(int i = 1; i < N; i++){
        a[i] = a[i - 1] + fi[i];
    }
}
void precalc_s(){
    for(int i = 1; i < N; i++){
        root[i] = 0;
        for(int j = 1; j * j <= i; j++){
            s1[i][j] = s1[i][j - 1] + a[j] * (i / j - i / (j + 1));
            root[i] = j;
        }
        s2[i][i / (root[i] + 1) + 1] = s1[i][root[i]];
        for(int j = i / (root[i] + 1); j >= 1; j--){
            s2[i][j] = s2[i][j + 1] + a[i / j];
        }
    }
}
ll dp[N][17];
ll c(int l, int r){
    if(l > r){
        return 1e12;
    }
    ll ans = 0;
    if(r / l <= root[r]){
        return s1[r][r / l] - a[r / l] * (l - 1 - r / ((r / l) + 1));
    }
    else{
        return s2[r][l];
    }
    return ans;
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    precalc();
    precalc_s();
    dp[0][0] = 0;
    for(int i = 1; i < N; i++){
        dp[i][0] = 1e12;
    }
   // cout << "A\n";
    for(int k = 1; (1 << k) < N; k++){
        dp[0][k] = 0;
        //cout << k << "\n";
        vector <pair <int, int> > v;
        v.push_back({0, 0});
        for(int x = 1; x < N; x++){
            int j = (--lower_bound(v.begin(), v.end(), make_pair(x + 1, 0))) -> second;
            dp[x][k] = dp[j][k - 1] + c(j + 1, x);
            for(int i = sz(v) - 1; i >= 0; i--){
                int y = v[i].X;
                int oldj = v[i].Y;
                if(y > x && dp[x][k - 1] + c(x + 1, y) < dp[oldj][k - 1] + c(oldj + 1, y)){
                    v.pop_back();
                }
                else{
                    int l = y + 1, r = N;
                    while(r > l){
                        int midd = (r + l) / 2;
                        if(dp[x][k - 1] + c(x + 1, midd) < dp[oldj][k - 1] + c(oldj + 1, midd)){
                            r = midd;
                        }
                        else{
                            l = midd + 1;
                        }
                    }
                    if(r != N){
                        v.push_back({r, x});
                    }
                    break;
                }
            }
            if(sz(v) == 0){
                v.push_back(make_pair(0, x));
            }
        }
    }
    int q;
    cin >> q;
    while(q--){
        int n, k;
        cin >> n >> k;
        if(k >= 20 || (1 << k) - 1 >= n){
            cout << n << "\n";
        }
        else{
            cout << dp[n][k] << "\n";
        }
    }
    return 0;
}
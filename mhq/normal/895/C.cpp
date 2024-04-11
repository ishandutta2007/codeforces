#include <bits/stdc++.h>
using namespace std;
int n;
int dp[(1 << 19) + 1];
const int MOD = (int)1e9 + 7;
int ans;
int a[72];
int b[72];
vector < int > pr;
bool used[75];
bool used1[(1 << 19) + 10];
int add(int a, int b){
    int s = a + b;
    if (s >= MOD) s -= MOD;
    return s;
}
int mult(int a, int b) {
    return (1LL * a * b) % MOD;
}
int pw(int a, int b) {
    if (b == 0) return 1;
    if (b & 1) {
        return mult(a, pw(mult(a, a), b / 2));
    }
    else return pw(mult(a, a), b / 2);
}
int main() {
    ios_base::sync_with_stdio(false);
    dp[0] = 1;
    for (int i = 2; i <= 70; i++) {
        if (!used[i]) {
            pr.push_back(i);
            for (int j = 2; j * i <= 70; j++) {
                used[i * j] = true;
            }
        }
    }
    for (int i = 1; i <= 70; i++) {
        int t = i;
        for (int j = 0; j < pr.size(); j++) {
            int tp = 0;
            while (t % pr[j] == 0) {
                t = t / pr[j];
                tp++;
            }
            if(tp % 2 == 1) a[i] |= (1 << j);
        }
    }
    int q;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> q;
        b[q]++;
    }
    //cout << pw(2, 3) << " " << pw(2, 4);
    //cout << a[1] << " ";
    //cout << b[2];
    for (int i = 1; i <= 70; i++) {
        if (b[i] == 0) continue;
        int p = pw(2, b[i] - 1);
        for (int j = 0; j < (1 << 19); j++) {
            if (used1[j] == true) continue;
            //cout << i << " ";
            int t1 = dp[j];
            int t2 = dp[j ^ a[i]];
            if (a[i] == 0) {
                dp[j] = mult(t1, pw(2, b[i]));
                continue;
            }
            dp[j] = mult(add(t1, t2), p);
            dp[j ^ a[i]] = dp[j];
            used1[j] = true;
            used1[j ^ a[i]] = true;
        }
        for (int j = 0; j < (1 << 19); j++) used1[j] = false;
    }
    cout << dp[0] - 1;
    return 0;
}
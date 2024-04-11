#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define mp make_pair
#define F first
#define S second

const int INF = 1000 * 1000 * 1000;
const int N = 77;

int dp[N][N][N][2];
int n;
string s;

int mabs(int a) {
    return a > 0 ? a : -a;
}

int code(char c) {
    if (c == 'V')
        return 0;
    if (c == 'K')
        return 1;
    return 2;
}

int cost(int cv, int ck, int cx, int cur) {
    int pos = 0;
    int cnt = (cur == 0) * cv + (cur == 1) * ck + (cur == 2) * cx + 1; 
    while (pos < n && cnt) {
        if (code(s[pos]) == cur)
            cnt--;
        pos++;
    }
    if (cnt)
        return INF;
    pos--;
    int rv = 0;
    int rk = 0;
    int rx = 0;
    for (int i = 0; i < pos; i++)
        if (s[i] == 'V')
            rv++;
        else if (s[i] == 'K')
            rk++;
        else
            rx++;
    return mabs(rv - cv) + mabs(rk - ck) + mabs(rx - cx); 
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> n >> s;
    for (int cv = 0; cv <= n; cv++)
        for (int ck = 0; ck <= n; ck++)
            for (int cx = 0; cx <= n; cx++)
                dp[cv][ck][cx][0] = dp[cv][ck][cx][1] = INF;
    dp[0][0][0][0] = 0;
    for (int cv = 0; cv <= n; cv++)
        for (int ck = 0; ck <= n; ck++)
            for (int cx = 0; cx <= n; cx++) 
                for (int last_v = 0; last_v < 2; last_v++) 
                    for (int cur = 0; cur < 3; cur++) {
                        if (last_v && cur == 1)
                            continue;
                        if (cv + ck + cx >= n)
                            continue;
                        int nv = cv + (cur == 0);
                        int nk = ck + (cur == 1);
                        int nx = cx + (cur == 2);
                        int new_v = cur == 0;
                        dp[nv][nk][nx][new_v] = min(dp[nv][nk][nx][new_v],
                                dp[cv][ck][cx][last_v] + cost(cv, ck, cx, cur));
                    }
    int cv = 0;
    int ck = 0;
    int cx = 0;
    for (int i = 0; i < n; i++) {
        cv += (s[i] == 'V');
        ck += (s[i] == 'K');
        cx += (s[i] != 'V' && s[i] != 'K');
    }
    cout << min(dp[cv][ck][cx][0], dp[cv][ck][cx][1]) / 2  << endl;
}
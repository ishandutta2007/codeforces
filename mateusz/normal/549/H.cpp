#include <bits/stdc++.h>

using namespace std;
const int N = 55;
char look[4] = {'f', 'a', 'c', 'e'};
char board[N][N];
int n, m;
pair<long double, long double> det(long double a, long double b, long double c, long double d, long double e) {
    long double mini = 1e9;
    long double maxi = -1e9;
    for(int i = 0; i < 16; i++) {
        long double ap = a;
        long double bp = b;
        long double cp = c;
        long double dp = d;
        if((i & 1) == 1)
            ap += e;
        else ap -= e;
        if((i & 2) == 2)
            bp += e;
        else bp -= e;
        if((i & 4) == 4)
            cp += e;
        else cp -= e;
        if((i & 8) == 8)
            dp += e;
        else dp -= e;
        long double de = ap * dp - bp * cp;
        mini = min(mini, de);
        maxi = max(maxi, de);
    }
    return make_pair(mini, maxi);
}
int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    long long poc = 0;
    long long kon = 1e18;
    long double ans = 1e10;
    while(poc <= kon) {
        long long sr = (poc + kon) / 2;
        long double err = sr / 1e9;
        pair<long double, long double> ded = det(a, b, c, d, err);
        if(ded.first <= 0 && ded.second >= 0) {
            kon = sr - 1;
            ans = err;
        } else {
            poc = sr + 1;
        }
    }
    cout << fixed << setprecision(9) << ans << "\n";
    return 0;
}
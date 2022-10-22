#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define sz(a) int((a).size())
#define vi vector<int>
typedef long long ll;
typedef double db;
const int N = 1e6 + 10;
int n, c;
int sum[N];
void solveone() {
    cin >> n >> c;
    for(int i = 0; i <= c; i++) sum[i] = 0;
    for(int i = 1, x; i <= n; i++) {
        cin >> x;
        sum[x]++;
    }
    for(int i = 1; i <= c; i++) sum[i] += sum[i - 1];
    for(int i = 1; i <= c; i++) {
        if(sum[i] != sum[i - 1]) continue;
        for(int j = 1; j <= c / i; j++) {
            if(sum[j] - sum[j - 1] > 0 && sum[min(c, j * (i + 1) - 1)] - sum[j * i - 1] > 0) {
                cout << "No" << endl;
                return;
            }
        }
    }
    cout << "Yes" << endl;
    return;
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    for(cin >> t; t--; solveone());
    return 0;
}
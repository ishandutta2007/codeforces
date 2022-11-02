#include <bits/stdc++.h>

using namespace std;

int n, k, p[6], ans, num;

void dfs(int c) {
    if (c == k) {
        int cnt = 0;
        for (int i=0; i<n; i++)
            for (int j=i+1; j<n; j++)
                if (p[i] > p[j])
                    cnt++;
        ans += cnt, num++;
    } else {
        for (int i=0; i<n; i++)
            for (int j=i; j<n; j++) {
                reverse(p+i, p+j+1);
                dfs(c+1);
                reverse(p+i, p+j+1);
            }
    }
}

int main() {
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n >> k;
    for (int i=0; i<n; i++) cin >> p[i];
    dfs(0);

    cout << fixed << setprecision(10) << double(ans)/num << '\n';
}
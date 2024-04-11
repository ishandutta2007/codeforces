#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 4005;

long long n, v[maxn], d[maxn], p[maxn];
bool u[maxn];

int ans[maxn], cnt;

int main() {
    ios_base::sync_with_stdio(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> v[i] >> d[i] >> p[i];

    for (int i = 0; i < n; i++)
        if (!u[i]) {
            ans[cnt++] = i+1;
            int red = v[i];
            for (int j = i+1; j < n; j++)
                if (!u[j]) {
                    p[j] -= red;
                    red = max(0, red - 1);
                }
            
            while (1) {
                bool b = 0;
                for (int j = i+1; j < n; j++)
                    if (p[j] < 0 && !u[j]) {
                        u[j] = 1;
                        for (int k = j+1; k < n; k++)
                            p[k] -= d[j];
                        b = 1;
                        break;
                    }

                if (!b) break;
            }
        }

    cout << cnt << '\n';
    for (int i = 0; i < cnt; i++)
        cout << ans[i] << ' ';
    cout << '\n';
}
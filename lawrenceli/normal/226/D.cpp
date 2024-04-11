#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <ios>

using namespace std;

const int maxn = 105;

int n, m, a[maxn][maxn];
int sumr[maxn], sumc[maxn];
bool ar[maxn], ac[maxn];

int main() {
    ios_base::sync_with_stdio(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) sumr[i] += a[i][j];
    }
    
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) sumc[j] += a[i][j];
    }

    while (1) {
        bool b = 0;
        for (int i = 0; i < n; i++)
            if (sumr[i] < 0) {
                b = 1;
                ar[i] ^= 1;
                for (int j = 0; j < m; j++)
                    sumc[j] -= 2 * a[i][j], a[i][j] = -a[i][j];
                sumr[i] *= -1;
            }

        for (int j = 0; j < m; j++)
            if (sumc[j] < 0) {
                b = 1;
                ac[j] ^= 1;
                for (int i = 0; i < n; i++)
                    sumr[i] -= 2 * a[i][j], a[i][j] = -a[i][j];
                sumc[j] *= -1;
            }

        if (!b) break;
    }

    vector<int> vr, vc;
    for (int i = 0; i < n; i++)
        if (ar[i])
            vr.push_back(i);

    for (int i = 0; i < m; i++)
        if (ac[i])
            vc.push_back(i);

    cout << vr.size() << ' ';
    for (int i : vr) cout << i + 1 << ' ';
    cout << '\n';
    
    cout << vc.size() << ' ';
    for (int i : vc) cout << i + 1 << ' ';
    cout << '\n';
}
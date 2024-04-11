#include <bits/stdc++.h>
using namespace std;

const int MAXN = 55;

int n, m;
char mat[MAXN][MAXN];
int freq[200];

int main() {
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n >> m;
    for (int i=0; i<n; i++) cin >> mat[i];
    int ans = 0;
    for (int i=0; i+2<=n; i++)
        for (int j=0; j+2<=m; j++) {
            memset(freq, 0, sizeof(freq));
            freq[mat[i][j]]++;
            freq[mat[i+1][j]]++;
            freq[mat[i][j+1]]++;
            freq[mat[i+1][j+1]]++;
            if (freq['f'] && freq['a'] && freq['c'] && freq['e']) ans++;
        }
    cout << ans;
}
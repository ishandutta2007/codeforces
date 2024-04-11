#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1005;
const int Maxd = 5;

int n, m;
string s[Maxn];
int freq[Maxd];
int res;

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        cin >> s[i];
    for (int i = 0; i < m; i++) {
        fill(freq, freq + Maxd, 0);
        for (int j = 0; j < n; j++)
            freq[s[j][i] - 'A']++;
        int mx = 0;
        for (int j = 0; j < Maxd; j++)
            mx = max(mx, freq[j]);
        int mult; scanf("%d", &mult);
        res += mx * mult;
    }
    cout << res << endl;
    return 0;
}
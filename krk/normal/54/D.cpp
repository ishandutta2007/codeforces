#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const int Maxn = 103;
const int Maxk = 26;

int n, k;
string s, inf;
int pos[Maxn][Maxn], p[Maxn][Maxn], wth[Maxn][Maxn];

int getNxt(const string &s)
{
    vector <int> Z(s.length(), 0);
    int l = 0, r = 0;
    for (int i = 1; i < s.length(); i++) {
        if (i <= r) Z[i] = min(Z[i - l], r - i);
        while (i + Z[i] < s.length() && s[Z[i]] == s[i + Z[i]]) Z[i]++;
        if (Z[i]) { l = i; r = i + Z[i] - 1; } 
    }
    for (int i = 0; i < s.length(); i++)
        if (i + Z[i] == s.length()) return Z[i];
    return 0;
}

void Print(int i, int j)
{
     if (!i) return;
     Print(i - 1, p[i][j]); cout << char(wth[i][j] + 'a');
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cin >> n >> k;
    cin >> s >> inf;
    pos[0][0] = true;
    for (int i = 0; i < n; i++) {
        int l, r;
        if (s.length() > i) { l = 0; r = s.length(); }
        else if (inf[i - s.length()] == '1') l = r = s.length();
        else { l = 0; r = s.length() - 1; }
        for (int j = l; j <= r; j++) if (pos[i][j])
            for (int l = 0; l < k; l++) {
                int nxt = getNxt(s + "#" + s.substr(0, j) + char(l + 'a'));
                pos[i + 1][nxt] = true; p[i + 1][nxt] = j; wth[i + 1][nxt] = l;
            }
    }
    int l, r;
    if (inf[n - s.length()] == '1') l = r = s.length();
    else { l = 0; r = s.length() - 1; }
    while (l <= r && !pos[n][l]) l++;
    if (l > r) cout << "No solution\n";
    else { Print(n, l); cout << endl; }
    return 0;
}
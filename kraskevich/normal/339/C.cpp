#include <bits/stdc++.h>

using namespace std;

const int ADD = 20;
vector<bool> have(11, 0);
bool can[1111][51][11];
pair<short, short> par[1111][51][11];
int res[1111][51][11];
string s;
int m;

void rec(int i, int d, int l)
{
    if (i == 0)
        return;
    rec(i - 1, par[i][d][l].first, par[i][d][l].second);
    cout << res[i][d][l] << " ";
}

int main()
{
    ios_base::sync_with_stdio(0);
    #if defined DEBUG
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif

    cin >> s;
    cin >> m;
    for (int i = 0; i < 10; i++)
        if (s[i] == '1')
            have[i + 1] = 1;
    for (int i = 0; i <= m; i++)
        for (int j = 0; j <= 50; j++)
            for (int l = 0; l <= 10; l++)
                can[i][j][l] = false;
    can[0][ADD][0] = 1;
    for (int i = 0; i < m; i++)
        for (int d = 0; d <= 50; d++)
            for (int l = 0; l <= 10; l++)
                for (int c = 0; c <= 10; c++)
                {
                    if (!have[c] || l == c)
                        continue;
                    if (!can[i][d][l])
                        continue;
                    int dd = d - ADD;
                    int nd = c - dd;
                    if (nd <= 0)
                        continue;
                    nd += ADD;
                    if (nd < 0 || nd > 50)
                        continue;
                    //cerr << i + 1 << " " << nd - ADD << " " << endl;
                    can[i + 1][nd][c] = true;
                    par[i + 1][nd][c] = pair<short, short>(d, l);
                    res[i + 1][nd][c] = c;
                }
    for (int d = 0; d <= 50; d++)
        for (int l = 0; l <= 10; l++)
            if (can[m][d][l])
            {
                cout << "YES" << endl;
                rec(m, d, l);
                return 0;
            }
    cout << "NO";

    return 0;
}
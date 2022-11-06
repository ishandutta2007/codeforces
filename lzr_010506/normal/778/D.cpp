#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); i ++)
typedef long long LL;
typedef pair<int, int> PII;

int n, m;
char s[50][55], t[50][55];
char z[50][55];
vector<PII> a, b;

void solve(char (&s)[50][55], vector<PII> &v) 
{
    while (true) 
    {
        bool done = true;
        forn(i, n - 1) forn(j, m - 1)
            if (s[i][j] == 'U' && s[i][j + 1] == 'U' && s[i + 1][j] == 'D' && s[i + 1][j + 1] == 'D') 
            {
                v.pb(mp(i, j));
                s[i][j] = 'L';
                s[i][j + 1] = 'R';
                s[i + 1][j] = 'L';
                s[i + 1][j + 1] = 'R';
                done = false;
            }
        forn(i, n - 1) forn(j, m - 2)
            if (s[i][j] == 'U' && s[i + 1][j] == 'D' && s[i][j + 1] == 'L' && s[i][j + 2] == 'R' && s[i + 1][j + 1] == 'L' && s[i + 1][j + 2] == 'R') 
            {
                v.pb(mp(i, j + 1));
                v.pb(mp(i, j));
                s[i][j] = 'L';
                s[i + 1][j] = 'L';
                s[i][j + 1] = 'R';
                s[i + 1][j + 1] = 'R';
                s[i][j + 2] = 'U';
                s[i + 1][j + 2] = 'D';
                done = false;
            }
        if (done) break;
    }
}

void inv(char (&s)[50][55]) 
{
    forn(i, n) forn(j, m) 
        z[j][i] = s[i][j];
    
    forn(i, m) forn(j, n) 
    {
        if (z[i][j] == 'U') z[i][j] = 'L';
        else if (z[i][j] == 'D') z[i][j] = 'R';
        else if (z[i][j] == 'L') z[i][j] = 'U';
        else z[i][j] = 'D';
    }
    forn(i, m) forn(j, n)
        s[i][j] = z[i][j];
}

int main() 
{
    scanf("%d%d", &n, &m);
    forn(i, n) scanf("%s", s[i]);
    forn(i, n) scanf("%s", t[i]);
    bool flag = false;
    if (m % 2 == 1) 
    {
        flag = true;
        inv(s);
        inv(t);
        swap(n, m);
    }
    solve(s, a);
    solve(t, b);
    reverse(b.begin(), b.end());
    if (flag) 
    {
        for (PII &x : a) swap(x.X, x.Y);
        for (PII &x : b) swap(x.X, x.Y);
    }
    printf("%d\n", int(a.size()) + int(b.size()));
    for (PII x : a) printf("%d %d\n", x.X + 1, x.Y + 1);
    for (PII x : b) printf("%d %d\n", x.X + 1, x.Y + 1);
    return 0;
}
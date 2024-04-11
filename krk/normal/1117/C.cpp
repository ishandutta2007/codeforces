#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll X1, Y1;
ll X2, Y2;
ll deltX, deltY;
int n;
string s;

void Update(ll &X, ll &Y, char ch)
{
    if (ch == 'L') X--;
    else if (ch == 'R') X++;
    else if (ch == 'U') Y++;
    else Y--;
}

int Get(ll curX, ll curY, ll tk)
{
    if (abs(curX - X2) + abs(curY - Y2) <= tk) return 0;
    for (int i = 0; i < n; i++) {
        Update(curX, curY, s[i]);
        tk++;
        if (abs(curX - X2) + abs(curY - Y2) <= tk) return i + 1;
    }
    return -1;
}

int main()
{
    scanf("%I64d %I64d", &X1, &Y1);
    scanf("%I64d %I64d", &X2, &Y2);
    X2 -= X1; Y2 -= Y1;
    cin >> n;
    cin >> s;
    for (int i = 0; i < n; i++)
        Update(deltX, deltY, s[i]);
    ll lef = 0, rig = 2000000000;
    while (lef <= rig) {
        ll mid = lef + rig >> 1ll;
        if (Get(mid * deltX, mid * deltY, mid * ll(n)) != -1)
            rig = mid - 1;
        else lef = mid + 1;
    }
    ll tk = rig + 1;
    if (tk >= 2000000000) { printf("-1\n"); return 0; }
    cout << tk * ll(n) + Get(tk * deltX, tk * deltY, tk * ll(n)) << endl;
    return 0;
}
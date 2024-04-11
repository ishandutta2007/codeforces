#include <bits/stdc++.h>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rep0(i, x) for(int i = 0; i < x; i ++)
#define mp make_pair
#define X first
#define Y second
#define pii pair<int, int>
using namespace std;
int a[50][50];
int main() 
{
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--) 
    {
        int n;
        cin >> n;
        map<int, int> LL, RR;
        map<pii, int> PP;
        int L, R, C;
        cin >> L >> R >> C;
        cout << C << endl;
        LL[L] = C;
        RR[R] = C;
        PP[mp(L, R)] = C;
        n --;
        rep(i, 1, n)
        {
            int l, r, c;
            cin >> l >> r >> c;
            if (l == L) LL[L] = min(LL[L], c);
            if (l < L) L = l, LL[L] = c;
            if (r == R) RR[R] = min(RR[R], c);
            if (r > R) R = r, RR[R] = c;
            pii p(l, r);
            int ans = 2e9 + 10;
            if (l == L && r == R && (PP.find(p) == PP.end() || PP[p] > c)) PP[p] = c;
            if (PP.find(mp(L, R)) != PP.end()) ans = PP[mp(L, R)];
            ans = min(ans, LL[L] + RR[R]);
            cout << ans << "\n";
        }
    }
}
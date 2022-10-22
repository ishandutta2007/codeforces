#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 200005;
const string lets = "AWDS";
const int Maxd = 4;
const int dy[Maxd] = {0, -1, 0, 1};
const int dx[Maxd] = {-1, 0, 1, 0};

int t;
string s;
int mnx[Maxn], mny[Maxn], mxx[Maxn], mxy[Maxn];

ll Area(ll mnx, ll mny, ll mxx, ll mxy) { return (mxx - mnx + 1ll) * (mxy - mny + 1ll); }

int main()
{
    scanf("%d", &t);
    while (t--) {
        cin >> s;
        mnx[s.length()] = mny[s.length()] = mxx[s.length()] = mxy[s.length()] = 0;
        for (int i = int(s.length()) - 1; i >= 0; i--) {
            int ind = lets.find(s[i]);
            mnx[i] = min(0, mnx[i + 1] + dx[ind]);
            mxx[i] = max(0, mxx[i + 1] + dx[ind]);
            mny[i] = min(0, mny[i + 1] + dy[ind]);
            mxy[i] = max(0, mxy[i + 1] + dy[ind]);
        }
        ll res = Area(mnx[0], mny[0], mxx[0], mxy[0]);
        ll curx = 0, cury = 0;
        ll X1, X2; X1 = X2 = curx;
        ll Y1, Y2; Y1 = Y2 = cury;
        for (int i = 0; i < s.length(); i++) {
            int ind = lets.find(s[i]);
            curx += dx[ind], cury += dy[ind];
            X1 = min(X1, curx); X2 = max(X2, curx);
            Y1 = min(Y1, cury); Y2 = max(Y2, cury);
            for (int j = 0; j < Maxd; j++) {
                ll gX1 = min(X1, curx + dx[j] + mnx[i + 1]);
                ll gX2 = max(X2, curx + dx[j] + mxx[i + 1]);
                ll gY1 = min(Y1, cury + dy[j] + mny[i + 1]);
                ll gY2 = max(Y2, cury + dy[j] + mxy[i + 1]);
                res = min(res, Area(gX1, gY1, gX2, gY2));
            }
        }
        printf("%I64d\n", res);
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <ld, int> ldi;

const int Maxn = 3005;

int n;
int X[Maxn], Y[Maxn];
vector <ldi> seq;
ll res;

ll Cross(int a, int b, int c)
{
    int ax = X[b] - X[a], ay = Y[b] - Y[a];
    int bx = X[c] - X[a], by = Y[c] - Y[a];
    return ll(ax) * by - ll(ay) * bx;
}

ll C3(ll n)
{
    if (n < 3) return 0;
    return n * (n - 1) * (n - 2) / 6;
}

ll C4(ll n)
{
    if (n < 4) return 0;
    return n * (n - 1) * (n - 2) * (n - 3) / 24;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d %d", &X[i], &Y[i]);
    for (int i = 0; i < n; i++) {
        seq.clear();
        for (int j = 0; j < n; j++) if (i != j)
            seq.push_back(ldi(atan2(ld(Y[j] - Y[i]), ld(X[j] - X[i])), j));
        sort(seq.begin(), seq.end());
        ll sub = 0;
        int nxt = 0;
        for (int j = 0; j < seq.size(); j++) {
            nxt = max(nxt, j);
            while (nxt - j < seq.size() &&
                   Cross(i, seq[j].second, seq[nxt % int(seq.size())].second) >= 0)
                    nxt++;
            sub += C3(nxt - j - 1);
        }
        res += C4(seq.size()) - sub;
    }
    cout << res << endl;
    return 0;
}
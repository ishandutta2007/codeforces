#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, ll> ill;

const int Maxn = 300005;

int n, q;
char str[Maxn];
int a[Maxn];
vector <ill> S;
int qt[Maxn], ql[Maxn], qr[Maxn];
vector <int> quer[Maxn];
ll res[Maxn];

int main()
{
    scanf("%d %d", &n, &q);
    scanf("%s", str + 1);
    for (int i = 1; i <= n; i++)
        a[i] = a[i - 1] + (str[i] == '('? 1: -1);
    for (int i = 0; i < q; i++) {
        scanf("%d %d %d", &qt[i], &ql[i], &qr[i]);
        ql[i]--;
        quer[qr[i]].push_back(i);
    }
    S.push_back(ill(0, 0ll));
    for (int i = 1; i <= n; i++) {
        ll add = 0;
        while (!S.empty() && a[S.back().first] > a[i]) {
            int nd = a[S.back().first];
            int cnt = 0;
            while (!S.empty() && a[S.back().first] == nd) {
                cnt++;
                add += S.back().second;
                S.pop_back();
                if (!S.empty()) add -= S.back().second;
            }
            add += ll(cnt) * (cnt - 1) / 2;
        }
        if (S.empty()) S.push_back(ill(i, add));
        else {
            add += S.back().second;
            S.push_back(ill(i, add));
        }
        for (int j = 0; j < quer[i].size(); j++) {
            int qind = quer[i][j];
            int ind = lower_bound(S.begin(), S.end(), ill(ql[qind], 0ll)) - S.begin();
            res[qind] = S.back().second - S[ind].second;
            int cnt = S.size() - ind;
            res[qind] += ll(cnt) * (cnt - 1) / 2ll;
        }
    }
    for (int i = 0; i < q; i++)
        printf("%I64d\n", res[i]);
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <ll, int> lli;

const int Maxn = 100005;

int n;
ll s[Maxn];
vector <ll> seq;
int q;
lli quer[Maxn];
ll res[Maxn];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%I64d", &s[i]);
    sort(s, s + n);
    for (int i = 0; i + 1 < n; i++)
        seq.push_back(s[i + 1] - s[i]);
    sort(seq.begin(), seq.end());
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        ll l, r; scanf("%I64d %I64d", &l, &r);
        quer[i] = lli(r - l + 1, i);
    }
    sort(quer, quer + q);
    ll lst = 0;
    ll cur = 0;
    int pw = n;
    int pnt = 0;
    for (int i = 0; i < q; i++) {
        ll val = quer[i].first;
        int ind = quer[i].second;
        while (pnt < seq.size() && seq[pnt] < val) {
            cur += ll(pw) * (seq[pnt] - lst);
            lst = seq[pnt]; pw--;
            pnt++;
        }
        cur += ll(pw) * (val - lst);
        lst = val;
        res[ind] = cur;
    }
    for (int i = 0; i < q; i++)
        printf("%I64d%c", res[i], i + 1 < q? ' ': '\n');
    return 0;
}
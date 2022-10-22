#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int Maxn = 1000005;

int n, k, m;
map <int, ll> A, B;
ll cnt;
ll sum;
vector <ii> add[Maxn], rem[Maxn];
ll res;

void Fix()
{
    while (cnt > k) {
        map <int, ll>::iterator it = A.end(); it--;
        ll tk = min(cnt - k, it->second);
        cnt -= tk; sum -= ll(tk) * it->first;
        B[it->first] += tk;
        if (tk == it->second) A.erase(it);
        else it->second -= tk;
    }
    while (cnt < k && !B.empty()) {
        map <int, ll>::iterator it = B.begin();
        ll tk = min(k - cnt, it->second);
        cnt += tk; sum += ll(tk) * it->first;
        A[it->first] += tk;
        if (tk == it->second) B.erase(it);
        else it->second -= tk;
    }
}

void Rem(int x, ll val)
{
    map <int, ll>::iterator it = B.find(x);
    if (it != B.end()) {
        ll tk = min(val, it->second); val -= it->second;
        if (tk == it->second) B.erase(it);
        else it->second -= tk;
    }
    if (val > 0) {
        map <int, ll>::iterator it = A.find(x);
        cnt -= val; sum -= ll(val) * x;
        if (it->second == val) A.erase(it);
        else it->second -= val;
    }
}

void Add(int x, ll val)
{
    map <int, ll>::iterator it = A.end();
    map <int, ll>::iterator it2 = B.begin();
    bool fir = true;
    if (it != A.begin()) {
        it--;
        fir = x <= it->first;
    } else if (it2 != B.end())
        fir = x < it2->first;
    if (fir) {
        cnt += val; sum += ll(val) * x;
        A[x] += val;
    } else B[x] += val;
}

int main()
{
    scanf("%d %d %d", &n, &k, &m);
    for (int i = 0; i < m; i++) {
        int l, r, c, p; scanf("%d %d %d %d", &l, &r, &c, &p);
        add[l].push_back(ii(p, c));
        rem[r + 1].push_back(ii(p, c));
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < add[i].size(); j++) {
            ii u = add[i][j];
            Add(u.first, u.second);
        }
        for (int j = 0; j < rem[i].size(); j++) {
            ii u = rem[i][j];
            Rem(u.first, u.second);
        }
        Fix();
        res += sum;
    }
    printf("%I64d\n", res);
    return 0;
}
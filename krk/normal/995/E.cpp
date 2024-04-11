#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

int u, v, p;
map <int, ii> M[2];
vector <int> res;

int toPower(int a, int pw)
{
    int res = 1;
    while (pw) {
        if (pw & 1) res = ll(res) * a % p;
        pw >>= 1; a = ll(a) * a % p;
    }
    return res;
}

int Inv(int x) { return toPower(x, p - 2); }

int getClose(int x, int usd, map <int, ii> &M)
{
    map <int, ii>::iterator it = M.lower_bound(x);
    if (it == M.end()) it = M.begin();
    if (usd + it->second.first + (p + it->first - x) % p <= 200)
        return it->first;
    if (it == M.begin()) it = M.end();
    it--;
    if (usd + it->second.first + (x - it->first + p) % p <= 200)
        return it->first;
    return -1;
}

void printBeg(int x, map <int, ii> &M)
{
    ii cur = M[x];
    if (cur.first == 0) return;
    printBeg(cur.second, M);
    if ((cur.second + 1) % p == x)
        res.push_back(1);
    else if ((cur.second - 1 + p) % p == x)
        res.push_back(2);
    else res.push_back(3);
}

void printEnd(int x, map <int, ii> M)
{
    ii cur = M[x];
    if (cur.first == 0) return;
    if ((x + 1) % p == cur.second)
        res.push_back(1);
    else if ((x - 1 + p) % p == cur.second)
        res.push_back(2);
    else res.push_back(3);
    printEnd(cur.second, M);
}

void Print(int a, int b, int f)
{
    if (f == 0) swap(a, b);
    printBeg(a, M[0]);
    int fir = (b - a + p) % p;
    int sec = (a - b + p) % p;
    if (fir <= sec)
        while (a != b) {
            res.push_back(1);
            a = (a + 1) % p;
        }
    else while (a != b) {
        res.push_back(2);
        a = (a - 1 + p) % p;
    }
    printEnd(b, M[1]);
    printf("%d\n", int(res.size()));
    for (int i = 0; i < res.size(); i++)
        printf("%d%c", res[i], i + 1 < res.size()? ' ': '\n');
}

int main()
{
    scanf("%d %d %d", &u, &v, &p);
    M[0][u] = ii(0, -1);
    int tmp;
    M[1][v] = ii(0, -1);
    if ((tmp = getClose(v, 0, M[0])) != -1) { Print(v, tmp, 0); return 0; }
    vector <ii> Q; Q.push_back(ii(0, u));
    Q.push_back(ii(1, v));
    for (int i = 0; i < Q.size(); i++) {
        ii v = Q[i];
        int d = M[v.first][v.second].first;
        ii u = ii(v.first, (v.second + 1) % p);
        if (M[u.first].find(u.second) == M[u.first].end()) {
            M[u.first][u.second] = ii(d + 1, v.second);
            Q.push_back(u);
            if ((tmp = getClose(u.second, d + 1, M[1 - u.first])) != -1) {
                Print(u.second, tmp, 1 - u.first); return 0;
            }
        }
        u = ii(v.first, (v.second - 1 + p) % p);
        if (M[u.first].find(u.second) == M[u.first].end()) {
            M[u.first][u.second] = ii(d + 1, v.second);
            Q.push_back(u);
            if ((tmp = getClose(u.second, d + 1, M[1 - u.first])) != -1) {
                Print(u.second, tmp, 1 - u.first); return 0;
            }
        }
        u = ii(v.first, Inv(v.second));
        if (M[u.first].find(u.second) == M[u.first].end()) {
            M[u.first][u.second] = ii(d + 1, v.second);
            Q.push_back(u);
            if ((tmp = getClose(u.second, d + 1, M[1 - u.first])) != -1) {
                Print(u.second, tmp, 1 - u.first); return 0;
            }
        }
    }
    return 0;
}
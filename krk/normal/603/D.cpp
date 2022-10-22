#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <ld, ld> ldld;
typedef pair <ldld, int> ldldi;
typedef pair <int, int> ii;

const ld pi = acos(-1.0l);
const ld eps = 1e-14l;
const int Maxn = 2005;

struct lin {
    int A, B, C;
};

int n;
lin L[Maxn];
ii vec[Maxn];
ldldi seq[Maxn];
int slen;
ll res;
map <ld, int> M;

ld Cross(const ldld &a, const ldld &b) { return a.first * b.first + a.second * b.second; }

ld Len(const ldld &a) { return sqrt(a.first * a.first + a.second * a.second); }

ld getAng(int ind, const ldld &C, const ldld &pnt)
{
    ldld A = ldld(pnt.first - C.first, pnt.second - C.second);
    ldld B = vec[ind];
    ld cr = acos(Cross(A, B) / Len(A) / Len(B));
    if (L[ind].A * pnt.first + L[ind].B * pnt.second > L[ind].C)
        cr = pi - cr;
    return cr;
}

ldld Intersect(const lin &l1, const lin &l2)
{
    ld det = l1.A * l2.B - l2.A * l1.B;
    return ldld((l2.B * l1.C - l1.B * l2.C) / det, (l1.A * l2.C - l2.A * l1.C) / det);
}

bool Less(const ldldi &a, const ldldi &b)
{
    if (fabs(a.first.first - b.first.first) >= eps) return a.first.first < b.first.first;
    return a.first.second < b.first.second;
}

void addMap(const ld &key)
{
    int res = 1;
    auto it = M.upper_bound(key - eps);
    while (it != M.end() && it->first < key + eps) {
        res += it->second;
        M.erase(it++);
    }
    M.insert(make_pair(key, res));
}

ld Fix(ld ang)
{
    while (ang + eps < 0) ang += pi;
    while (ang + eps >= pi) ang -= pi;
    return ang;
}

int getMap(ld key)
{
    key = Fix(pi - key);
    auto it = M.upper_bound(key - eps);
    int res = 0;
    if (it != M.end() && it->first < key + eps)
        res += it->second;
    return res;
}


int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &L[i].A, &L[i].B, &L[i].C);
        vec[i] = ii(-L[i].B, L[i].A);
        if (vec[i].first < 0 || vec[i].first == 0 && vec[i].second < 0)
            vec[i] = ii(-vec[i].first, -vec[i].second);
    }
    for (int i = 0; i < n; i++) if (L[i].C == 0) {
        bool found = false;
        for (int j = 0; j < n; j++) if (i != j && L[j].C == 0)
            found = true;
        if (found) res += n - 2;
    }
    for (int i = 0; i < n; i++) if (L[i].C != 0) {
        M.clear();
        slen = 0;
        for (int j = 0; j < n; j++) if (i != j)
            seq[slen++] = ldldi(Intersect(L[i], L[j]), j);
        sort(seq, seq + slen, Less);
        for (int j = 0; j < slen; j++) {
            auto C = seq[j].first;
            int ind2 = seq[j].second;
            ld a = getAng(i, C, ldld(C.first + vec[ind2].first, C.second + vec[ind2].second));
            ld b = getAng(i, C, ldld(0.0l, 0.0l));
            res += getMap(Fix(a - b));
            addMap(Fix(b - a));
        }
    }
    cout << res / 3ll << endl;
    return 0;
}
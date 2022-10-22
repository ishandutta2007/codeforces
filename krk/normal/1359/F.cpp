#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef pair <ld, ld> ldld;

const ld eps = 1e-9l;

struct pt {
    ld x, y;

    bool operator<(const pt& p) const
    {
        return x < p.x - eps || (abs(x - p.x) < eps && y < p.y - eps);
    }
};

struct line {
    ld a, b, c;

    line() {}
    line(pt p, pt q)
    {
        a = p.y - q.y;
        b = q.x - p.x;
        c = -a * p.x - b * p.y;
        norm();
    }

    void norm()
    {
        ld z = sqrt(a * a + b * b);
        if (abs(z) > eps)
            a /= z, b /= z, c /= z;
    }

    ld dist(pt p) const { return a * p.x + b * p.y + c; }
};

ld det(ld a, ld b, ld c, ld d)
{
    return a * d - b * c;
}

inline bool betw(ld l, ld r, ld x)
{
    return min(l, r) <= x + eps && x <= max(l, r) + eps;
}

inline bool intersect_1d(ld a, ld b, ld c, ld d)
{
    if (a > b)
        swap(a, b);
    if (c > d)
        swap(c, d);
    return max(a, c) <= min(b, d) + eps;
}

bool intersect(pt a, pt b, pt c, pt d, pt& left, pt& right)
{
    if (!intersect_1d(a.x, b.x, c.x, d.x) || !intersect_1d(a.y, b.y, c.y, d.y))
        return false;
    line m(a, b);
    line n(c, d);
    ld zn = det(m.a, m.b, n.a, n.b);
    if (abs(zn) < eps) {
        if (abs(m.dist(c)) > eps || abs(n.dist(a)) > eps)
            return false;
        if (b < a)
            swap(a, b);
        if (d < c)
            swap(c, d);
        left = max(a, c);
        right = min(b, d);
        return true;
    } else {
        left.x = right.x = -det(m.c, m.b, n.c, n.b) / zn;
        left.y = right.y = -det(m.a, m.c, n.a, n.c) / zn;
        return betw(a.x, b.x, left.x) && betw(a.y, b.y, left.y) &&
               betw(c.x, d.x, left.x) && betw(c.y, d.y, left.y);
    }
}

const int Maxn = 25005;

typedef pair <int, int> ii;

int n;
int X[Maxn], Y[Maxn], DX[Maxn], DY[Maxn], S[Maxn];
pt lef[Maxn], rig[Maxn];
vector <ii> seq;
vector <int> vert;

ld getY(int ind, ld x)
{
    return lef[ind].y + (rig[ind].y - lef[ind].y) / (rig[ind].x - lef[ind].x) * (x - lef[ind].x);
}

bool Intersect(int ain, int bin)
{
    pt tmp1, tmp2;
    return intersect(lef[ain], rig[ain], lef[bin], rig[bin], tmp1, tmp2);
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef struct item * pitem;
struct item {
    int prior, ind;
    pitem l, r;
    item(int ind = 0): prior(uniform_int_distribution<int>(0, 1000000000)(rng)), ind(ind), l(nullptr), r(nullptr) {}
};

void merge (pitem & t, pitem l, pitem r) {
    if (!l || !r)
        t = l ? l : r;
    else if (l->prior > r->prior)
        merge (l->r, l->r, r),  t = l;
    else
        merge (r->l, l, r->l),  t = r;
}

void split (pitem t, pitem & l, pitem & r, ld keyx, ld keyy) {
    if (!t)
        return void( l = r = 0 );
    ld cur_key = getY(t->ind, keyx);
    if (keyy <= cur_key)
        split (t->l, l, t->l, keyx, keyy),  r = t;
    else
        split (t->r, t->r, r, keyx, keyy),  l = t;
}

pitem getLeft(pitem t)
{
    if (t->l) return getLeft(t->l);
    return t; 
}

pitem getRight(pitem t)
{
    if (t->r) return getRight(t->r);
    return t;
}

bool sortSeq(const ii &a, const ii &b)
{
    pt p1 = a.second == 0? lef[a.first]: rig[a.first];
    pt p2 = b.second == 0? lef[b.first]: rig[b.first];
    if (fabs(p1.x - p2.x) > eps) return p1.x < p2.x;
    return a.second < b.second;
}

bool sortVert(const int &a, const int &b)
{
    return lef[a] < lef[b];
}

bool seqVert(const ii &a, const int &b)
{
    pt p = a.second == 0? lef[a.first]: rig[a.first];
    if (fabs(p.x - lef[b].x) > eps) return p.x < lef[b].x;
    return a.second == 0;
}

bool Solve(ld tim)
{
    seq.clear(); vert.clear();
    for (int i = 0; i < n; i++) {
        lef[i].x = X[i];
        lef[i].y = Y[i];
        ld dv = sqrt(ld(DX[i]) * DX[i] + ld(DY[i]) * DY[i]);
        rig[i].x = X[i] + tim * S[i] * DX[i] / dv;
        rig[i].y = Y[i] + tim * S[i] * DY[i] / dv;
        if (rig[i] < lef[i]) swap(lef[i], rig[i]);
        if (DX[i] == 0) vert.push_back(i);
        else {
            seq.push_back(ii(i, 0));
            seq.push_back(ii(i, 1));
        }
    }
    sort(seq.begin(), seq.end(), sortSeq);
    sort(vert.begin(), vert.end(), sortVert);
    pitem tr = nullptr;
    int i = 0, j = 0;
    int lst = -1;
    while (i < seq.size() || j < vert.size())
        if (i < seq.size() && (j >= vert.size() || seqVert(seq[i], vert[j]))) {
            ii a = seq[i];
            pt p = a.second == 0? lef[a.first]: rig[a.first];
            if (a.second == 0) {
                pitem lef, rig;
                split(tr, lef, rig, p.x, p.y);
                if (lef) {
                    pitem got = getRight(lef);
                    if (Intersect(got->ind, a.first)) return true;
                }
                if (rig) {
                    pitem got = getLeft(rig);
                    if (Intersect(got->ind, a.first)) return true;
                }
                merge(tr, lef, new item(a.first));
                merge(tr, tr, rig);
            } else {
                pitem lef, tmp, rig;
                split(tr, lef, tmp, p.x, p.y - eps);
                split(tmp, tmp, rig, p.x, p.y + eps);
                if (lef && rig) {
                    pitem got1 = getRight(lef);
                    pitem got2 = getLeft(rig);
                    if (Intersect(got1->ind, got2->ind)) return true;
                }
                merge(tr, lef, rig);
            }
            i++;
        } else {
            if (lst != -1)
                if (Intersect(lst, vert[j])) return true;
            lst = vert[j];
            pt p = lef[lst];
            pitem lef, rig;
            split(tr, lef, rig, p.x, p.y);
            if (lef) {
                pitem got = getRight(lef);
                if (Intersect(got->ind, lst)) return true;
            }
            if (rig) {
                pitem got = getLeft(rig);
                if (Intersect(got->ind, lst)) return true;
            }
            merge(tr, lef, rig);
            j++;
        }
    return false;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d %d %d %d %d", &X[i], &Y[i], &DX[i], &DY[i], &S[i]);
    ld lef = 0, rig = 10000000000;
    if (!Solve(rig)) { printf("No show :(\n"); return 0; }
    for (int i = 0; i < 150; i++) {
        ld mid = (lef + rig) / 2.0;
        if (Solve(mid)) rig = mid;
        else lef = mid;
    }
    cout << fixed << setprecision(15) << rig << endl;
    return 0;
}
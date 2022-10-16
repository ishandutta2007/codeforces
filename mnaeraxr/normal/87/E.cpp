/*
    Test:
        geometry/minkowski.cpp

    Link:
        http://codeforces.com/contest/87/problem/E
        http://codeforces.com/contest/87/submission/36864848
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

typedef complex<int64> point;
typedef vector<point> polygon;

polygon read(){
    int n; cin >> n;
    polygon p(n);
    for (int i = 0; i < n; ++i){
        int64 x, y;
        cin >> x >> y;
        p[i] = point(x, y);
    }
    return p;
}

void print(polygon p){
    for (auto pp : p)
        cout << pp << endl;
}

int64 cross(point a, point b){
    return imag(conj(a) * b);
}

namespace std
{
    bool operator<(point a, point b)
    {
        if (a.real() != b.real())
            return a.real() < b.real();
        return a.imag() < b.imag();
    }
}

polygon minkowski(polygon &A, polygon &B){
    int na = (int)A.size(), nb = (int)B.size();

    if (A.empty() || B.empty()) return polygon();

    rotate(A.begin(), min_element(A.begin(), A.end()), A.end());
    rotate(B.begin(), min_element(B.begin(), B.end()), B.end());

    int pa = 0, pb = 0;

    polygon M;

    while (pa < na && pb < nb){
        M.push_back(A[pa] + B[pb]);
        double x = cross(A[(pa + 1) % na] - A[pa],
                         B[(pb + 1) % nb] - B[pb]);
        if (x <= 0) pb++;
        if (0 <= x) pa++;
    }

    while (pa < na) M.push_back(A[pa++] + B[0]);
    while (pb < nb) M.push_back(B[pb++] + A[0]);

    return M;
}

struct convex_container{
    polygon pol;

    // Polygon MUST be in counter clockwise order
    convex_container(polygon p) : pol(p){
        int pos = 0;

        for (int i = 1; i < p.size(); ++i){
            if (p[i].imag() < p[pos].imag() ||
                (p[i].imag() == p[pos].imag() && p[i].real() < p[pos].real()))
                pos = i;
        }

        rotate(pol.begin(), pol.begin() + pos, pol.end());
    }

    bool contains(point p){
        point c = pol[0];

        if (p.imag() < c.imag() || cross(pol.back() - c, p - c) > 0)
            return false;

        int lo = 1, hi = pol.size() - 1;

        while (lo + 1 < hi){
            int m = (lo + hi) / 2;

            if (cross(pol[m] - c, p - c) >= 0)
                lo = m;
            else
                hi = m;
        }

        return cross(pol[lo + 1] - pol[lo], p - pol[lo]) >= 0;
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<polygon> cities(3);

    for (int i = 0; i < 3; ++i)
        cities[i] = read();

    cities[0] = minkowski(cities[0], cities[1]);
    cities[0] = minkowski(cities[0], cities[2]);

    convex_container cc(cities[0]);

    int q; cin >> q;
    while (q--){
        int64 x, y;
        cin >> x >> y;
        point p(x, y);

        if (cc.contains(p * 3LL)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }


    return 0;
}